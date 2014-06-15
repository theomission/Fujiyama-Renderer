/*
Copyright (c) 2011-2014 Hiroshi Tsubokawa
See LICENSE and README
*/

#include "fj_plugin.h"
#include "fj_compatibility.h"
#include "fj_memory.h"
#include "fj_os.h"

#include <cstdio>
#include <cstring>

namespace fj {

static int error_no = PLG_ERR_NONE;
static void clear_pluginfo(struct PluginInfo *info);
static int is_valid_pluginfo(const struct PluginInfo *info);
static void set_errno(int err_no);

Plugin::Plugin() : dso_(NULL), info_()
{
}

Plugin::~Plugin()
{
}

int Plugin::Open(const std::string &filename)
{
  set_errno(PLG_ERR_NONE);

  void *tmpdso = OsDlopen(filename.c_str());
  if (tmpdso == NULL) {
    set_errno(PLG_ERR_PLUGIN_NOT_FOUND);
    OsDlclose(tmpdso);
    return -1;
  }

  // ISO C forbids conversion of object pointer to function pointer type.
  // This does void pointer -> uintptr_t -> function pointer
  PlgInitializeFn initialize_plugin =
      (PlgInitializeFn) (uintptr_t) OsDlsym(tmpdso, "Initialize");
  if (initialize_plugin == NULL) {
    set_errno(PLG_ERR_INIT_PLUGIN_FUNC_NOT_EXIST);
    OsDlclose(tmpdso);
    return -1;
  }

  PluginInfo info;

  const int err = initialize_plugin(&info);
  if (err) {
    set_errno(PLG_ERR_INIT_PLUGIN_FUNC_FAIL);
    OsDlclose(tmpdso);
    return -1;
  }

  // TODO this is checked in initialize_plugin
  if (!is_valid_pluginfo(&info)) {
    set_errno(PLG_ERR_BAD_PLUGIN_INFO);
    OsDlclose(tmpdso);
    return -1;
  }

  // commit
  dso_ = tmpdso;
  info_ = info;
  return 0;
}

int Plugin::Close()
{
  const int err = OsDlclose(dso_);

  if (err) {
    set_errno(PLG_ERR_CLOSE_PLUGIN_FAIL);
    return -1;
  } else {
    set_errno(PLG_ERR_NONE);
    return 0;
  }
}

void *Plugin::CreateInstance() const
{
  return info_.create_instance();
}

void Plugin::DeleteInstance(void *instance) const
{
  info_.delete_instance(instance);
}

const Property *Plugin::GetPropertyList() const
{
  return info_.properties;
}

const MetaInfo *Plugin::Metainfo() const
{
  return info_.meta;
}

const void *Plugin::GetVtable() const
{
  return info_.vtbl;
}

const char *Plugin::GetName() const
{
  return info_.plugin_name;
}

const char *Plugin::GetType() const
{
  return info_.plugin_type;
}

int Plugin::TypeMatch(const char *type) const
{
  return strcmp(GetType(), type) == 0;
}

struct Plugin *PlgOpen(const char *filename)
{
  int err = 0;
  void *tmpdso = NULL;
  struct Plugin *plugin = NULL;
  struct PluginInfo info;
  PlgInitializeFn initialize_plugin = NULL;

  set_errno(PLG_ERR_NONE);
  tmpdso = OsDlopen(filename);
  if (tmpdso == NULL) {
    set_errno(PLG_ERR_PLUGIN_NOT_FOUND);
    goto plugin_error;
  }

  /*
  ISO C forbids conversion of object pointer to function pointer type.
  This does void pointer -> uintptr_t -> function pointer
  */
  initialize_plugin = (PlgInitializeFn) (uintptr_t) OsDlsym(tmpdso, "Initialize");
  if (initialize_plugin == NULL) {
    set_errno(PLG_ERR_INIT_PLUGIN_FUNC_NOT_EXIST);
    goto plugin_error;
  }

  clear_pluginfo(&info);
  err = initialize_plugin(&info);
  if (err) {
    set_errno(PLG_ERR_INIT_PLUGIN_FUNC_FAIL);
    goto plugin_error;
  }

  /* TODO this is checked in initialize_plugin */
  if (!is_valid_pluginfo(&info)) {
    set_errno(PLG_ERR_BAD_PLUGIN_INFO);
    goto plugin_error;
  }

  plugin = FJ_MEM_ALLOC(struct Plugin);
  if (plugin == NULL) {
    set_errno(PLG_ERR_NO_MEMORY);
    goto plugin_error;
  }

  /* commit */
  plugin->dso_ = tmpdso;
  plugin->info_ = info;
  return plugin;

plugin_error:
  OsDlclose(tmpdso);
  return NULL;
}

int PlgClose(struct Plugin *plugin)
{
  const int err = OsDlclose(plugin->dso_);

  FJ_MEM_FREE(plugin);

  if (err) {
    set_errno(PLG_ERR_CLOSE_PLUGIN_FAIL);
    return -1;
  } else {
    set_errno(PLG_ERR_NONE);
    return 0;
  }
}

void *PlgCreateInstance(const struct Plugin *plugin)
{
  return plugin->info_.create_instance();
}

void PlgDeleteInstance(const struct Plugin *plugin, void *obj)
{
  plugin->info_.delete_instance(obj);
}

const struct Property *PlgGetPropertyList(const struct Plugin *plugin)
{
  return plugin->info_.properties;
}

const struct MetaInfo *PlgMetainfo(const struct Plugin *plugin)
{
  return plugin->info_.meta;
}

const void *PlgGetVtable(const struct Plugin *plugin)
{
  return plugin->info_.vtbl;
}

const char *PlgGetName(const struct Plugin *plugin)
{
  return plugin->info_.plugin_name;
}

const char *PlgGetType(const struct Plugin *plugin)
{
  return plugin->info_.plugin_type;
}

int PlgTypeMatch(const struct Plugin *plugin, const char *type)
{
  return strcmp(PlgGetType(plugin), type) == 0;
}

int PlgSetupInfo(struct PluginInfo *info,
    int api_version,
    const char *plugin_type,
    const char *plugin_name,
    PlgCreateInstanceFn create_instance,
    PlgDeleteInstanceFn delete_instance,
    const void *vtbl,
    const struct Property *properties,
    const struct MetaInfo *meta)
{
  info->api_version = api_version;
  info->plugin_type = plugin_type;
  info->plugin_name = plugin_name;
  info->create_instance = create_instance;
  info->delete_instance = delete_instance;
  info->vtbl = vtbl;
  info->properties = properties;
  info->meta = meta;

  if (is_valid_pluginfo(info))
    return 0;
  else
    return -1;
}

int PlgGetErrorNo(void)
{
  return error_no;
}

static void set_errno(int err_no)
{
  error_no = err_no;
}

static void clear_pluginfo(struct PluginInfo *info)
{
  info->api_version = 0;
  info->plugin_type = NULL;
  info->plugin_name = NULL;
  info->create_instance = NULL;
  info->delete_instance = NULL;
  info->vtbl = NULL;
  info->properties = NULL;
  info->meta = NULL;
}

static int is_valid_pluginfo(const struct PluginInfo *info)
{
  if (info->api_version != PLUGIN_API_VERSION ||
    info->plugin_type == NULL ||
    info->plugin_name == NULL ||
    info->create_instance == NULL ||
    info->delete_instance == NULL ||
    info->vtbl == NULL ||
    info->properties == NULL ||
    info->meta == NULL)
    return 0;
  else
    return 1;
}

} // namespace fj

/*
Copyright (c) 2011-2014 Hiroshi Tsubokawa
See LICENSE and README
*/

/*
this file is inteded to be included in fj_scene_interface.c 
defines all properties for builtin type and some helper functions
*/

static int set_ObjectInstance_transform_order(void *self, const struct PropertyValue *value)
{
  /* TODO error handling */
  if (!XfmIsTransformOrder((int) value->vector[0]))
    return -1;

  ObjSetTransformOrder((struct ObjectInstance *) self, (int) value->vector[0]);
  return 0;
}

static int set_ObjectInstance_rotate_order(void *self, const struct PropertyValue *value)
{
  /* TODO error handling */
  if (!XfmIsRotateOrder((int) value->vector[0]))
    return -1;

  ObjSetRotateOrder((struct ObjectInstance *) self, (int) value->vector[0]);
  return 0;
}

static int set_ObjectInstance_translate(void *self, const struct PropertyValue *value)
{
  ObjSetTranslate((struct ObjectInstance *) self,
      value->vector[0], value->vector[1], value->vector[2], value->time);
  return 0;
}

static int set_ObjectInstance_rotate(void *self, const struct PropertyValue *value)
{
  ObjSetRotate((struct ObjectInstance *) self,
      value->vector[0], value->vector[1], value->vector[2], value->time);
  return 0;
}

static int set_ObjectInstance_scale(void *self, const struct PropertyValue *value)
{
  ObjSetScale((struct ObjectInstance *) self,
      value->vector[0], value->vector[1], value->vector[2], value->time);
  return 0;
}

static int set_ObjectInstance_reflect_target(void *self, const struct PropertyValue *value)
{
  ObjSetReflectTarget((struct ObjectInstance *) self, value->object_group);
  return 0;
}

static int set_ObjectInstance_refract_target(void *self, const struct PropertyValue *value)
{
  ObjSetRefractTarget((struct ObjectInstance *) self, value->object_group);
  return 0;
}

static int set_ObjectInstance_shadow_target(void *self, const struct PropertyValue *value)
{
  ObjSetShadowTarget((struct ObjectInstance *) self, value->object_group);
  return 0;
}

static int set_Turbulence_lacunarity(void *self, const struct PropertyValue *value)
{
  TrbSetLacunarity((struct Turbulence *) self, value->vector[0]);
  return 0;
}

static int set_Turbulence_gain(void *self, const struct PropertyValue *value)
{
  TrbSetGain((struct Turbulence *) self, value->vector[0]);
  return 0;
}

static int set_Turbulence_octaves(void *self, const struct PropertyValue *value)
{
  TrbSetOctaves((struct Turbulence *) self, (int) value->vector[0]);
  return 0;
}

static int set_Turbulence_amplitude(void *self, const struct PropertyValue *value)
{
  TrbSetAmplitude((struct Turbulence *) self,
      value->vector[0], value->vector[1], value->vector[2]);
  return 0;
}

static int set_Turbulence_frequency(void *self, const struct PropertyValue *value)
{
  TrbSetFrequency((struct Turbulence *) self,
      value->vector[0], value->vector[1], value->vector[2]);
  return 0;
}

static int set_Turbulence_offset(void *self, const struct PropertyValue *value)
{
  TrbSetOffset((struct Turbulence *) self,
      value->vector[0], value->vector[1], value->vector[2]);
  return 0;
}

static int set_Renderer_sample_jitter(void *self, const struct PropertyValue *value)
{
  RdrSetSampleJitter((struct Renderer *) self, value->vector[0]);
  return 0;
}

static int set_Renderer_cast_shadow(void *self, const struct PropertyValue *value)
{
  RdrSetShadowEnable((struct Renderer *) self, (int) value->vector[0]);
  return 0;
}

static int set_Renderer_max_reflect_depth(void *self, const struct PropertyValue *value)
{
  RdrSetMaxReflectDepth((struct Renderer *) self, (int) value->vector[0]);
  return 0;
}

static int set_Renderer_max_refract_depth(void *self, const struct PropertyValue *value)
{
  RdrSetMaxRefractDepth((struct Renderer *) self, (int) value->vector[0]);
  return 0;
}

static int set_Renderer_raymarch_step(void *self, const struct PropertyValue *value)
{
  RdrSetRaymarchStep((struct Renderer *) self, value->vector[0]);
  return 0;
}

static int set_Renderer_raymarch_shadow_step(void *self, const struct PropertyValue *value)
{
  RdrSetRaymarchShadowStep((struct Renderer *) self, value->vector[0]);
  return 0;
}

static int set_Renderer_raymarch_reflect_step(void *self, const struct PropertyValue *value)
{
  RdrSetRaymarchReflectStep((struct Renderer *) self, value->vector[0]);
  return 0;
}

static int set_Renderer_raymarch_refract_step(void *self, const struct PropertyValue *value)
{
  RdrSetRaymarchRefractStep((struct Renderer *) self, value->vector[0]);
  return 0;
}

static int set_Renderer_sample_time_range(void *self, const struct PropertyValue *value)
{
  RdrSetSampleTimeRange((struct Renderer *) self, value->vector[0], value->vector[1]);
  return 0;
}

static int set_Renderer_resolution(void *self, const struct PropertyValue *value)
{
  RdrSetResolution((struct Renderer *) self, (int) value->vector[0], (int) value->vector[1]);
  return 0;
}

static int set_Renderer_pixelsamples(void *self, const struct PropertyValue *value)
{
  RdrSetPixelSamples((struct Renderer *) self,
      (int) value->vector[0], (int) value->vector[1]);
  return 0;
}

static int set_Renderer_tilesize(void *self, const struct PropertyValue *value)
{
  RdrSetTileSize((struct Renderer *) self, (int) value->vector[0], (int) value->vector[1]);
  return 0;
}

static int set_Renderer_filterwidth(void *self, const struct PropertyValue *value)
{
  RdrSetFilterWidth((struct Renderer *) self, value->vector[0], value->vector[1]);
  return 0;
}

static int set_Renderer_render_region(void *self, const struct PropertyValue *value)
{
  RdrSetRenderRegion((struct Renderer *) self,
      (int) value->vector[0], (int) value->vector[1],
      (int) value->vector[2], (int) value->vector[3]);
  return 0;
}

static int set_Renderer_use_max_thread(void *self, const struct PropertyValue *value)
{
  RdrSetUseMaxThread((struct Renderer *) self, (int) value->vector[0]);
  return 0;
}

static int set_Renderer_thread_count(void *self, const struct PropertyValue *value)
{
  RdrSetThreadCount((struct Renderer *) self, (int) value->vector[0]);
  return 0;
}

static int set_Camera_fov(void *self, const struct PropertyValue *value)
{
  CamSetFov((struct Camera *) self, value->vector[0]);
  return 0;
}

static int set_Camera_znear(void *self, const struct PropertyValue *value)
{
  CamSetNearPlane((struct Camera *) self, value->vector[0]);
  return 0;
}

static int set_Camera_zfar(void *self, const struct PropertyValue *value)
{
  CamSetFarPlane((struct Camera *) self, value->vector[0]);
  return 0;
}

static int set_Camera_translate(void *self, const struct PropertyValue *value)
{
  CamSetTranslate((struct Camera *) self,
      value->vector[0], value->vector[1], value->vector[2], value->time);
  return 0;
}

static int set_Camera_rotate(void *self, const struct PropertyValue *value)
{
  CamSetRotate((struct Camera *) self,
      value->vector[0], value->vector[1], value->vector[2], value->time);
  return 0;
}

static int set_Camera_transform_order(void *self, const struct PropertyValue *value)
{
  CamSetTransformOrder((struct Camera *) self, (int) value->vector[0]);
  return 0;
}

static int set_Camera_rotate_order(void *self, const struct PropertyValue *value)
{
  CamSetRotateOrder((struct Camera *) self, (int) value->vector[0]);
  return 0;
}

static int set_Volume_resolution(void *self, const struct PropertyValue *value)
{
  VolResize((struct Volume *) self,
      value->vector[0], value->vector[1], value->vector[2]);
  return 0;
}

static int set_Volume_bounds_min(void *self, const struct PropertyValue *value)
{
  struct Volume *volume = (struct Volume *) self;
  struct Box bounds = {{0}};

  VolGetBounds(volume, &bounds);

  bounds.min.x = value->vector[0];
  bounds.min.y = value->vector[1];
  bounds.min.z = value->vector[2];

  VolSetBounds(volume, &bounds);

  return 0;
}

static int set_Volume_bounds_max(void *self, const struct PropertyValue *value)
{
  struct Volume *volume = (struct Volume *) self;
  struct Box bounds = {{0}};

  VolGetBounds(volume, &bounds);

  bounds.max.x = value->vector[0];
  bounds.max.y = value->vector[1];
  bounds.max.z = value->vector[2];

  VolSetBounds(volume, &bounds);

  return 0;
}

static int set_Light_intensity(void *self, const struct PropertyValue *value)
{
  struct Light *light = (struct Light *) self;
  LgtSetIntensity(light, value->vector[0]);
  return 0;
}

static int set_Light_color(void *self, const struct PropertyValue *value)
{
  LgtSetColor((struct Light *) self,
      value->vector[0], value->vector[1], value->vector[2]);
  return 0;
}

static int set_Light_sample_count(void *self, const struct PropertyValue *value)
{
  struct Light *light = (struct Light *) self;
  LgtSetSampleCount(light, (int) value->vector[0]);
  return 0;
}

static int set_Light_double_sided(void *self, const struct PropertyValue *value)
{
  struct Light *light = (struct Light *) self;
  LgtSetDoubleSided(light, (int) value->vector[0]);
  return 0;
}

static int set_Light_environment_map(void *self, const struct PropertyValue *value)
{
  struct Light *light = (struct Light *) self;
  LgtSetEnvironmentMap(light, value->texture);
  return 0;
}

static int set_Light_transform_order(void *self, const struct PropertyValue *value)
{
  /* TODO error handling */
  if (!XfmIsTransformOrder((int) value->vector[0]))
    return -1;

  LgtSetTransformOrder((struct Light *) self, (int) value->vector[0]);
  return 0;
}

static int set_Light_rotate_order(void *self, const struct PropertyValue *value)
{
  /* TODO error handling */
  if (!XfmIsRotateOrder((int) value->vector[0]))
    return -1;

  LgtSetRotateOrder((struct Light *) self, (int) value->vector[0]);
  return 0;
}

static int set_Light_translate(void *self, const struct PropertyValue *value)
{
  LgtSetTranslate((struct Light *) self,
      value->vector[0], value->vector[1], value->vector[2], value->time);
  return 0;
}

static int set_Light_rotate(void *self, const struct PropertyValue *value)
{
  LgtSetRotate((struct Light *) self,
      value->vector[0], value->vector[1], value->vector[2], value->time);
  return 0;
}

static int set_Light_scale(void *self, const struct PropertyValue *value)
{
  LgtSetScale((struct Light *) self,
      value->vector[0], value->vector[1], value->vector[2], value->time);
  return 0;
}

#define END_OF_PROPERTY {PROP_NONE, NULL, {0, 0, 0, 0}, NULL}
static const struct Property ObjectInstance_properties[] = {
  {PROP_SCALAR,      "transform_order", {ORDER_SRT},  set_ObjectInstance_transform_order},
  {PROP_SCALAR,      "rotate_order",    {ORDER_ZXY},  set_ObjectInstance_rotate_order},
  {PROP_VECTOR3,     "translate",       {0, 0, 0, 0}, set_ObjectInstance_translate},
  {PROP_VECTOR3,     "rotate",          {0, 0, 0, 0}, set_ObjectInstance_rotate},
  {PROP_VECTOR3,     "scale",           {1, 1, 1, 0}, set_ObjectInstance_scale},
  {PROP_OBJECTGROUP, "reflect_target",  {0, 0, 0, 0}, set_ObjectInstance_reflect_target},
  {PROP_OBJECTGROUP, "refract_target",  {0, 0, 0, 0}, set_ObjectInstance_refract_target},
  {PROP_OBJECTGROUP, "shadow_target",   {0, 0, 0, 0}, set_ObjectInstance_shadow_target},
  END_OF_PROPERTY
};

static const struct Property Turbulence_properties[] = {
  {PROP_SCALAR,  "lacunarity", {2, 0, 0, 0},  set_Turbulence_lacunarity},
  {PROP_SCALAR,  "gain",       {.5, 0, 0, 0}, set_Turbulence_gain},
  {PROP_SCALAR,  "octaves",    {8, 0, 0, 0},  set_Turbulence_octaves},
  {PROP_VECTOR3, "amplitude",  {1, 1, 1, 0},  set_Turbulence_amplitude},
  {PROP_VECTOR3, "frequency",  {1, 1, 1, 0},  set_Turbulence_frequency},
  {PROP_VECTOR3, "offset",     {0, 0, 0, 0},  set_Turbulence_offset},
  END_OF_PROPERTY
};

static const struct Property Renderer_properties[] = {
  {PROP_SCALAR,  "sample_jitter",         {1, 0, 0, 0},      set_Renderer_sample_jitter},
  {PROP_SCALAR,  "cast_shadow",           {1, 0, 0, 0},      set_Renderer_cast_shadow},
  {PROP_SCALAR,  "max_reflect_depth",     {3, 0, 0, 0},      set_Renderer_max_reflect_depth},
  {PROP_SCALAR,  "max_refract_depth",     {3, 0, 0, 0},      set_Renderer_max_refract_depth},
  {PROP_SCALAR,  "raymarch_step",         {.05, 0, 0, 0},    set_Renderer_raymarch_step},
  {PROP_SCALAR,  "raymarch_shadow_step",  {.1, 0, 0, 0},     set_Renderer_raymarch_shadow_step},
  {PROP_SCALAR,  "raymarch_reflect_step", {.1, 0, 0, 0},     set_Renderer_raymarch_reflect_step},
  {PROP_SCALAR,  "raymarch_refract_step", {.1, 0, 0, 0},     set_Renderer_raymarch_refract_step},
  {PROP_VECTOR2, "sample_time_range",     {0, 1, 0, 0},      set_Renderer_sample_time_range},
  {PROP_VECTOR2, "resolution",            {320, 240, 0, 0},  set_Renderer_resolution},
  {PROP_VECTOR2, "pixelsamples",          {3, 3, 0, 0},      set_Renderer_pixelsamples},
  {PROP_VECTOR2, "tilesize",              {64, 64, 0, 0},    set_Renderer_tilesize},
  {PROP_VECTOR2, "filterwidth",           {2, 2, 0, 0},      set_Renderer_filterwidth},
  {PROP_VECTOR4, "render_region",         {0, 0, 320, 2400}, set_Renderer_render_region},
  {PROP_SCALAR,  "use_max_thread",        {1, 0, 0, 0},      set_Renderer_use_max_thread},
  {PROP_SCALAR,  "thread_count",          {8, 0, 0, 0},      set_Renderer_thread_count},
  END_OF_PROPERTY
};

static const struct Property Camera_properties[] = {
  {PROP_SCALAR,  "transform_order", {ORDER_SRT},     set_Camera_transform_order},
  {PROP_SCALAR,  "rotate_order",    {ORDER_ZXY},     set_Camera_rotate_order},
  {PROP_VECTOR3, "translate",       {0, 0, 0, 0},    set_Camera_translate},
  {PROP_VECTOR3, "rotate",          {0, 0, 0, 0},    set_Camera_rotate},
  {PROP_SCALAR,  "fov",             {30, 0, 0, 0},   set_Camera_fov},
  {PROP_SCALAR,  "znear",           {.01, 0, 0, 0},  set_Camera_znear},
  {PROP_SCALAR,  "zfar",            {1000, 0, 0, 0}, set_Camera_zfar},
  END_OF_PROPERTY
};

static const struct Property Volume_properties[] = {
  {PROP_VECTOR3, "resolution", {0, 0, 0, 0}, set_Volume_resolution},
  {PROP_VECTOR3, "bounds_min", {0, 0, 0, 0}, set_Volume_bounds_min},
  {PROP_VECTOR3, "bounds_max", {0, 0, 0, 0}, set_Volume_bounds_max},
  END_OF_PROPERTY
};

static const struct Property Light_properties[] = {
  {PROP_SCALAR,  "transform_order", {ORDER_SRT},   set_Light_transform_order},
  {PROP_SCALAR,  "rotate_order",    {ORDER_ZXY},   set_Light_rotate_order},
  {PROP_VECTOR3, "translate",       {0, 0, 0, 0},  set_Light_translate},
  {PROP_VECTOR3, "rotate",          {0, 0, 0, 0},  set_Light_rotate},
  {PROP_VECTOR3, "scale",           {1, 1, 1, 0},  set_Light_scale},
  {PROP_SCALAR,  "intensity",       {1, 0, 0, 0},  set_Light_intensity},
  {PROP_VECTOR3, "color",           {1, 1, 1, 0},  set_Light_color},
  {PROP_SCALAR,  "sample_count",    {16, 0, 0, 0}, set_Light_sample_count},
  {PROP_SCALAR,  "double_sided",    {0, 0, 0, 0},  set_Light_double_sided},
  {PROP_TEXTURE, "environment_map", {0, 0, 0, 0},  set_Light_environment_map},
  END_OF_PROPERTY
};

struct property_desc {
  int entry_type;
  const char *type_name;
  const struct Property *property_list;
  void *(*get_entry_from_scene)(const struct Scene *scene, int index);
};

#define GET_FUNC(type) \
void *get_##type(const struct Scene *scene, int index) { \
  return (void *) ScnGet##type(scene, index); \
}
#define DESC(type) {Type_##type, #type, type##_properties, get_##type}
GET_FUNC(ObjectInstance)
GET_FUNC(Turbulence)
GET_FUNC(Renderer)
GET_FUNC(Camera)
GET_FUNC(Volume)
GET_FUNC(Light)
static const struct property_desc property_desc_list[] = {
  DESC(ObjectInstance),
  DESC(Turbulence),
  DESC(Renderer),
  DESC(Camera),
  DESC(Volume),
  DESC(Light),
  {Type_Begin, NULL, NULL, NULL}
};
#undef GET_FUNC
#undef PROPERTY_DESC

static void *get_builtin_type_entry(struct Scene *scene, const struct Entry *entry)
{
  const struct property_desc *desc = NULL;

  for (desc = property_desc_list; desc->type_name != NULL; desc++) {
    if (desc->entry_type == entry->type) {
      return desc->get_entry_from_scene(scene, entry->index);
    }
  }
  return NULL;
}

static const struct Property *get_builtin_type_property_list(int entry_type)
{
  const struct property_desc *desc = NULL;

  for (desc = property_desc_list; desc->type_name != NULL; desc++) {
    if (desc->entry_type == entry_type) {
      return desc->property_list;
    }
  }
  return NULL;
}

static int get_builtin_type_by_name(const char *builtin_type_name)
{
  const struct property_desc *desc = NULL;

  for (desc = property_desc_list; desc->type_name != NULL; desc++) {
    if (strcmp(desc->type_name, builtin_type_name) == 0) {
      return desc->entry_type;
    }
  }
  return Type_Begin;
}

static const struct Property *get_property_list(const char *type_name)
{
  /* builtin type properties */
  const int entry_type = get_builtin_type_by_name(type_name);
  const struct Property *builtin_props = get_builtin_type_property_list(entry_type);

  if (builtin_props != NULL) {
    return builtin_props;
  }

  /* plugin type properties */
  {
    const char *plugin_name = type_name;
    struct Plugin **plugins = ScnGetPluginList(get_scene());
    struct Plugin *found = NULL;
    const int N = (int) ScnGetPluginCount(get_scene());
    int i;

    for (i = 0; i < N; i++) {
      if (strcmp(plugin_name, PlgGetName(plugins[i])) == 0) {
        found = plugins[i];
        break;
      }
    }

    if (found == NULL) {
      return NULL;
    } else {
      return PlgGetPropertyList(found);
    }
  }
}

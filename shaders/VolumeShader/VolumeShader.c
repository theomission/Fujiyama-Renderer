/*
Copyright (c) 2011-2013 Hiroshi Tsubokawa
See LICENSE and README
*/

#include "Shader.h"
#include "Numeric.h"
#include "Memory.h"
#include "Vector.h"
#include "Color.h"

#include <string.h>
#include <stdio.h>
#include <float.h>

struct VolumeShader {
	struct Color diffuse;
};

static void *MyNew(void);
static void MyFree(void *self);
static void MyEvaluate(const void *self, const struct TraceContext *cxt,
		const struct SurfaceInput *in, struct SurfaceOutput *out);

static const char MyPluginName[] = "VolumeShader";
static const struct ShaderFunctionTable MyFunctionTable = {
	MyEvaluate
};

static int set_diffuse(void *self, const struct PropertyValue *value);

static const struct Property MyProperties[] = {
	{PROP_VECTOR3, "diffuse", set_diffuse},
	{PROP_NONE,    NULL,      NULL}
};

static const struct MetaInfo MyMetainfo[] = {
	{"help", "A volume shader."},
	{"plugin_type", "Shader"},
	{NULL, NULL}
};

int Initialize(struct PluginInfo *info)
{
	return PlgSetupInfo(info,
			PLUGIN_API_VERSION,
			SHADER_PLUGIN_TYPE,
			MyPluginName,
			MyNew,
			MyFree,
			&MyFunctionTable,
			MyProperties,
			MyMetainfo);
}

static void *MyNew(void)
{
	struct VolumeShader *volume = NULL;

	volume = MEM_ALLOC(struct VolumeShader);
	if (volume == NULL)
		return NULL;

	ColSet(&volume->diffuse, 1, 1, 1);

	return volume;
}

static void MyFree(void *self)
{
	struct VolumeShader *volume = (struct VolumeShader *) self;
	if (volume == NULL)
		return;
	MEM_FREE(volume);
}

static void MyEvaluate(const void *self, const struct TraceContext *cxt,
		const struct SurfaceInput *in, struct SurfaceOutput *out)
{
	const struct VolumeShader *volume = (struct VolumeShader *) self;
	struct Color diff = {0, 0, 0};

	struct LightSample *samples = NULL;
	const int nsamples = SlGetLightSampleCount(in);

	int i = 0;

	/* allocate samples */
	samples = SlNewLightSamples(in);

	for (i = 0; i < nsamples; i++) {
		struct LightOutput Lout;

		SlIlluminance(cxt, &samples[i], &in->P, &in->N, N_PI, in, &Lout);

		/* diff */
		diff.r += Lout.Cl.r;
		diff.g += Lout.Cl.g;
		diff.b += Lout.Cl.b;
	}

	/* MEM_FREE samples */
	SlFreeLightSamples(samples);

	/* Cs */
	out->Cs.r = diff.r * volume->diffuse.r;
	out->Cs.g = diff.g * volume->diffuse.g;
	out->Cs.b = diff.b * volume->diffuse.b;

	/* Os */
	out->Os = 1;
}

static int set_diffuse(void *self, const struct PropertyValue *value)
{
	struct VolumeShader *volume = (struct VolumeShader *) self;
	struct Color diffuse = {0, 0, 0};

	diffuse.r = MAX(0, value->vector[0]);
	diffuse.g = MAX(0, value->vector[1]);
	diffuse.b = MAX(0, value->vector[2]);
	volume->diffuse = diffuse;

	return 0;
}


/*
Copyright (c) 2011-2012 Hiroshi Tsubokawa
See LICENSE and README
*/

#ifndef OBJECTINSTANCE_H
#define OBJECTINSTANCE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Transform.h"

struct Intersection;
struct Accelerator;
struct Shader;
struct Light;
struct Ray;

struct ObjectInstance;
struct ObjectGroup;

/* ObjectInstance interfaces */
extern struct ObjectInstance *ObjNew(const struct Accelerator *acc);
extern void ObjFree(struct ObjectInstance *obj);

extern void ObjSetTranslate(struct ObjectInstance *obj, double tx, double ty, double tz);
extern void ObjSetRotate(struct ObjectInstance *obj, double rx, double ry, double rz);
extern void ObjSetScale(struct ObjectInstance *obj, double sx, double sy, double sz);
extern void ObjSetTransformOrder(struct ObjectInstance *obj, int order);
extern void ObjSetRotateOrder(struct ObjectInstance *obj, int order);
extern void ObjSetShader(struct ObjectInstance *obj, const struct Shader *shader);
extern void ObjSetLightList(struct ObjectInstance *obj, const struct Light **lights, int count);
extern void ObjSetReflectTarget(struct ObjectInstance *obj, const struct ObjectGroup *grp);
extern void ObjSetRefractTarget(struct ObjectInstance *obj, const struct ObjectGroup *grp);
extern const struct ObjectGroup *ObjGetReflectTarget(const struct ObjectInstance *obj);
extern const struct ObjectGroup *ObjGetRefractTarget(const struct ObjectInstance *obj);

extern const struct Shader *ObjGetShader(const struct ObjectInstance *obj);
extern const struct Light **ObjGetLightList(const struct ObjectInstance *obj);
extern int ObjGetLightCount(const struct ObjectInstance *obj);

/* ObjectGroup interfaces */
extern struct ObjectGroup *ObjGroupNew(void);
extern void ObjGroupFree(struct ObjectGroup *grp);

extern void ObjGroupAdd(struct ObjectGroup *grp, const struct ObjectInstance *obj);
#if 0
extern const struct Accelerator *ObjGroupGetAccelerator(const struct ObjectGroup *grp);
#endif
extern const struct Accelerator *ObjGroupGetSurfaceAccelerator(const struct ObjectGroup *grp);
extern const struct Accelerator *ObjGroupGetVolumeAccelerator(const struct ObjectGroup *grp);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* XXX_H */


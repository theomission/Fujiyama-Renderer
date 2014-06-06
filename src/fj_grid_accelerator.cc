/*
Copyright (c) 2011-2014 Hiroshi Tsubokawa
See LICENSE and README
*/

#include "fj_grid_accelerator.h"
#include "fj_intersection.h"
#include "fj_primitive_set.h"
#include "fj_numeric.h"
#include "fj_memory.h"
#include "fj_ray.h"

#include <cfloat>
#include <cstdio>

namespace fj {

static const char ACCELERATOR_NAME[] = "Uniform-Grid";
enum { GRID_MAXCELLS = 512 };

struct Cell {
  int prim_id;
  struct Cell *next;
};

static void compute_grid_cellsizes(int nprimitives,
    double xwidth, double ywidth, double zwidth,
    int *xncells, int *yncells, int *zncells);

/* TODO move this somewhere */
static int prim_ray_intersect(const struct PrimitiveSet *primset, int prim_id,
    double time, const struct Ray &ray, struct Intersection *isect);
static void swap_isect_ptr(struct Intersection **isect0, struct Intersection **isect1);

GridAccelerator::GridAccelerator() : cells(NULL), bounds()
{
  cells = NULL;
  ncells[0] = 0;
  ncells[1] = 0;
  ncells[2] = 0;
  cellsize[0] = 0;
  cellsize[1] = 0;
  cellsize[2] = 0;
  BoxReverseInfinite(&bounds);
}

GridAccelerator::~GridAccelerator()
{
  int x, y, z;
  const int XNCELLS = ncells[0];
  const int YNCELLS = ncells[1];
  const int ZNCELLS = ncells[2];

  for (z = 0; z < ZNCELLS; z++) {
    for (y = 0; y < YNCELLS; y++) {
      for (x = 0; x < XNCELLS; x++) {
        int cell_id = z * YNCELLS * XNCELLS + y * XNCELLS + x;
        struct Cell *cell = cells[cell_id];

        while (cell != NULL) {
          struct Cell *kill = cell;
          struct Cell *next = cell->next;
          FJ_MEM_FREE(kill);
          cell = next;
        }
      }
    }
  }
  FJ_MEM_FREE(cells);
}

int GridAccelerator::build()
{
  // TODO TEMP
  printf("================================================================================\n");
  printf("GridAccelerator::build() CALLED!!!!\n");
  printf("================================================================================\n");

  int i;
  int NPRIMS = 0;
  int XNCELLS = 0;
  int YNCELLS = 0;
  int ZNCELLS = 0;
  struct Box bounds_tmp;
  double cellsize_tmp[3] = {0};
  struct Cell **cells_tmp = NULL;

  const PrimitiveSet *primset = GetPrimitiveSet();

  const double PADDING = GetBoundsPadding();
  const double HALF_PADDING = .5 * PADDING;

  primset->GetBounds(&bounds_tmp);
  BoxExpand(&bounds_tmp, PADDING);

  NPRIMS = primset->GetPrimitiveCount();
  compute_grid_cellsizes(NPRIMS, 
      bounds_tmp.max.x - bounds_tmp.min.x,
      bounds_tmp.max.y - bounds_tmp.min.y,
      bounds_tmp.max.z - bounds_tmp.min.z,
      &XNCELLS, &YNCELLS, &ZNCELLS);

  cells_tmp = FJ_MEM_ALLOC_ARRAY(struct Cell *, XNCELLS * YNCELLS * ZNCELLS);
  if (cells_tmp == NULL)
    return -1;

  for (i = 0; i < XNCELLS * YNCELLS * ZNCELLS; i++)
    cells_tmp[i] = NULL;

  cellsize_tmp[0] = (bounds_tmp.max.x - bounds_tmp.min.x) / XNCELLS;
  cellsize_tmp[1] = (bounds_tmp.max.y - bounds_tmp.min.y) / YNCELLS;
  cellsize_tmp[2] = (bounds_tmp.max.z - bounds_tmp.min.z) / ZNCELLS;

  for (i = 0; i < NPRIMS; i++) {
    int X0, X1, Y0, Y1, Z0, Z1;
    int x, y, z;
    int primid = i;
    struct Box primbbox;

    primset->GetPrimitiveBounds(primid, &primbbox);
    BoxExpand(&primbbox, HALF_PADDING);

    /* compute the ranges of cell indices. e.g. [X0 .. X1) */
    X0 = (int) floor((primbbox.min.x - bounds_tmp.min.x) / cellsize_tmp[0]);
    X1 = (int) floor((primbbox.max.x - bounds_tmp.min.x) / cellsize_tmp[0]) + 1;
    Y0 = (int) floor((primbbox.min.y - bounds_tmp.min.y) / cellsize_tmp[1]);
    Y1 = (int) floor((primbbox.max.y - bounds_tmp.min.y) / cellsize_tmp[1]) + 1;
    Z0 = (int) floor((primbbox.min.z - bounds_tmp.min.z) / cellsize_tmp[2]);
    Z1 = (int) floor((primbbox.max.z - bounds_tmp.min.z) / cellsize_tmp[2]) + 1;
    X0 = Clamp(X0, 0, XNCELLS);
    X1 = Clamp(X1, 0, XNCELLS);
    Y0 = Clamp(Y0, 0, YNCELLS);
    Y1 = Clamp(Y1, 0, YNCELLS);
    Z0 = Clamp(Z0, 0, ZNCELLS);
    Z1 = Clamp(Z1, 0, ZNCELLS);

    /* add cell list which holds face id inside the cell */
    for (z = Z0; z < Z1; z++) {
      for (y = Y0; y < Y1; y++) {
        for (x = X0; x < X1; x++) {
          int cell_id = z * YNCELLS * XNCELLS + y * XNCELLS + x;
          struct Cell *newcell = FJ_MEM_ALLOC(struct Cell);

          if (newcell == NULL) {
            /* TODO error handling */
            return -1;
          }
          newcell->prim_id = primid;
          newcell->next = NULL;

          if (cells_tmp[cell_id] == NULL) {
            cells_tmp[cell_id] = newcell;
          } else {
            struct Cell *oldcell = cells_tmp[cell_id];
            cells_tmp[cell_id] = newcell;
            cells_tmp[cell_id]->next = oldcell;
          }
        }
      }
    }
  }

  /* commit */
  cells = cells_tmp;
  ncells[0] = XNCELLS;
  ncells[1] = YNCELLS;
  ncells[2] = ZNCELLS;
  cellsize[0] = cellsize_tmp[0];
  cellsize[1] = cellsize_tmp[1];
  cellsize[2] = cellsize_tmp[2];
  bounds = bounds_tmp;

  return 0;
}

bool GridAccelerator::intersect(const Ray &ray, Real time, Intersection *isect) const
{
  //return false;
  double grid_min[3];
  double start[3];
  double dir[3];

  double t_start = FLT_MAX;
  double t_end = FLT_MAX;
  double boxhit_tmin;
  double boxhit_tmax;

  int i;
  int hit;
  int NCELLS[3];
  int cell_id[3];
  int cell_step[3];
  int cell_end[3];
  double t_next[3];
  double t_delta[3];

  const PrimitiveSet *primset = GetPrimitiveSet();

  /* check intersection with overall bounds */
  /* to get boxhit_tmin and boxhit_tmax */
  if (!BoxRayIntersect(bounds, ray.orig, ray.dir, ray.tmin, ray.tmax,
        &boxhit_tmin, &boxhit_tmax)) {
    return 0;
  }

  /* check if the ray shot from inside bounds */
  if (BoxContainsPoint(bounds, ray.orig)) {
    start[0] = ray.orig.x;
    start[1] = ray.orig.y;
    start[2] = ray.orig.z;
    t_start = 0;
  }
  else {
    t_start = boxhit_tmin;
    t_end = boxhit_tmax;
    start[0] = ray.orig.x + ray.dir.x * t_start;
    start[1] = ray.orig.y + ray.dir.y * t_start;
    start[2] = ray.orig.z + ray.dir.z * t_start;
  }
  t_end = Min(t_end, ray.tmax);

  NCELLS[0] = ncells[0];
  NCELLS[1] = ncells[1];
  NCELLS[2] = ncells[2];

  /* TODO grid_min is static? */
  grid_min[0] = bounds.min.x;
  grid_min[1] = bounds.min.y;
  grid_min[2] = bounds.min.z;
  dir[0] = ray.dir.x;
  dir[1] = ray.dir.y;
  dir[2] = ray.dir.z;

  /* setup 3D DDA */
  for (i = 0; i < 3; i++) {
    cell_id[i] = (int) floor((start[i] - grid_min[i]) / cellsize[i]);
    cell_id[i] = Clamp(cell_id[i], 0, NCELLS[i]-1);

    if (dir[i] > 0) {
      t_next[i] = t_start +
        (((cell_id[i]+1) * cellsize[i] + grid_min[i]) - start[i]) / dir[i];

      t_delta[i] = cellsize[i] / dir[i];
      cell_step[i] = +1;
      cell_end[i] = NCELLS[i];
    }
    else if (dir[i] <0) {
      t_next[i] = t_start +
        ((cell_id[i] * cellsize[i] + grid_min[i]) - start[i]) / dir[i];

      t_delta[i] = -1 * cellsize[i] / dir[i];
      cell_step[i] = -1;
      cell_end[i] = -1;
    }
    else {
      t_next[i] = FLT_MAX;
      t_delta[i] = 0;
      cell_step[i] = 0;
      cell_end[i] = -1;
    }
  }

  /* traverse voxels */
  hit = 0;
  for (;;) {
    int id;
    struct Cell *cell;
    struct Intersection isect_candidates[2];
    struct Intersection *isect_min, *isect_tmp;

    isect_min = &isect_candidates[0];
    isect_tmp = &isect_candidates[1];
    isect_min->t_hit = FLT_MAX;

    id = cell_id[2] * NCELLS[0] * NCELLS[1] + cell_id[1] * NCELLS[0] + cell_id[0];

    /* loop over face list that associated in current cell */
    for (cell = cells[id]; cell != NULL; cell = cell->next) {
      int hittmp;
      int inside_cell;
      struct Vector P_hit;
      struct Box cellbox;

      hittmp = prim_ray_intersect(primset, cell->prim_id, time, ray, isect_tmp);
      if (!hittmp)
        continue;

      /* check if the hit point is inside the cell */
      cellbox.min.x = bounds.min.x + cell_id[0] * cellsize[0];
      cellbox.min.y = bounds.min.y + cell_id[1] * cellsize[1];
      cellbox.min.z = bounds.min.z + cell_id[2] * cellsize[2];
      cellbox.max.x = cellbox.min.x + cellsize[0];
      cellbox.max.y = cellbox.min.y + cellsize[1];
      cellbox.max.z = cellbox.min.z + cellsize[2];
      P_hit = RayPointAt(ray, isect_tmp->t_hit);
      inside_cell = BoxContainsPoint(cellbox, P_hit);

      if (!inside_cell)
        continue;

      /* update info ONLY if isect->t_hit renewed */
      if (isect_tmp->t_hit < isect_min->t_hit) {
        swap_isect_ptr(&isect_min, &isect_tmp);
        hit = hittmp;
      }
    }
    if (hit) {
      *isect = *isect_min;
      break;
    }

    /* advance to the next cell */
    if ((t_next[0] < t_next[1]) && (t_next[0] < t_next[2])) {
      if (t_end < t_next[0])
        break;
      cell_id[0] += cell_step[0];
      if (cell_id[0] == cell_end[0])
        break;
      t_next[0] += t_delta[0];
    }
    else if ((t_next[2] < t_next[1])) {
      if (t_end < t_next[2])
        break;
      cell_id[2] += cell_step[2];
      if (cell_id[2] == cell_end[2])
        break;
      t_next[2] += t_delta[2];
    }
    else {
      if (t_end < t_next[1])
        break;
      cell_id[1] += cell_step[1];
      if (cell_id[1] == cell_end[1])
        break;
      t_next[1] += t_delta[1];
    }
  }
  return hit;
}

const char *GridAccelerator::get_name() const
{
  return "Grid Accelerator";
}

static void compute_grid_cellsizes(int nprimitives,
    double xwidth, double ywidth, double zwidth,
    int *xncells, int *yncells, int *zncells)
{
  double max_width = 0;
  double ncells_per_unit_dist = 0;
  double cube_root = 0;
  int XNCELLS = 0;
  int YNCELLS = 0;
  int ZNCELLS = 0;

  if (xwidth > ywidth && xwidth > zwidth) {
    max_width = xwidth;
  }
  else if (ywidth > zwidth) {
    max_width = ywidth;
  }
  else {
    max_width = zwidth;
  }

  cube_root = 3 * pow(nprimitives, 1./3);
  ncells_per_unit_dist = cube_root / max_width;

  XNCELLS = (int) floor(xwidth * ncells_per_unit_dist + .5);
  YNCELLS = (int) floor(ywidth * ncells_per_unit_dist + .5);
  ZNCELLS = (int) floor(zwidth * ncells_per_unit_dist + .5);
  XNCELLS = Clamp(XNCELLS, 1, GRID_MAXCELLS);
  YNCELLS = Clamp(YNCELLS, 1, GRID_MAXCELLS);
  ZNCELLS = Clamp(ZNCELLS, 1, GRID_MAXCELLS);

  *xncells = XNCELLS;
  *yncells = YNCELLS;
  *zncells = ZNCELLS;
}

static int prim_ray_intersect(const struct PrimitiveSet *primset, int prim_id,
    double time, const struct Ray &ray, struct Intersection *isect)
{
  const int hit = primset->RayIntersect(prim_id, time, ray, isect);

  if (!hit) {
    isect->t_hit = FLT_MAX;
    return 0;
  }

  if (isect->t_hit < ray.tmin || ray.tmax < isect->t_hit) {
    isect->t_hit = FLT_MAX;
    return 0;
  }

  return 1;
}

static void swap_isect_ptr(struct Intersection **isect0, struct Intersection **isect1)
{
  struct Intersection *isect_swp = *isect0;
  *isect0 = *isect1;
  *isect1 = isect_swp;
}

} // namespace xxx

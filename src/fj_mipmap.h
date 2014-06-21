// Copyright (c) 2011-2014 Hiroshi Tsubokawa
// See LICENSE and README

#ifndef FJ_MIPMAP_H
#define FJ_MIPMAP_H

#include "fj_framebuffer.h"
#include <string>
#include <cstdio>

namespace fj {

class FrameBuffer;

class MipInput {
public:
  MipInput();
  ~MipInput();

  int Open(const std::string &filename);
  void Close();
  bool IsOpen() const;

  int ReadHeader();
  int ReadTile(int xtile, int ytile, float *dst);

public:
  FILE *file_;
  int version_;
  int width_;
  int height_;
  int nchannels_;

  int tilesize_;
  int xntiles_;
  int yntiles_;

  size_t offset_of_header_;
  size_t offset_of_tile_;
};

class MipOutput {
public:
  MipOutput();
  ~MipOutput();

  int Open(const std::string &filename);
  void Close();
  bool IsOpen() const;

  int GenerateFromSourceData(const float *pixels, int width, int height, int nchannels);
  void WriteFile();

public:
  FILE *file_;
  int version_;
  int width_;
  int height_;
  int nchannels_;
  int tilesize_;

  FrameBuffer fb_;
};

enum MipErrorNo {
  ERR_MIP_NOERR = 0,
  ERR_MIP_NOMEM,
  ERR_MIP_NOFILE,
  ERR_MIP_NOTMIP,
  ERR_MIP_BADVER
};

} // namespace xxx

#endif // FJ_XXX_H

/*
Copyright (c) 2011-2014 Hiroshi Tsubokawa
See LICENSE and README
*/

#include "fj_os.h"
#include "fj_compatibility.h"

#if defined(SI_WINDOWS)
  #include "internal/fj_os_win.c"
#else
  #include "internal/fj_os_unix.c"
#endif

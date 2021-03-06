#Copyright (c) 2011-2015 Hiroshi Tsubokawa
#See LICENSE and README

CC = g++
OPT = -O3
CFLAGS = $(OPT) -Wall -ansi -pedantic-errors
LDFLAGS = -lscene -lm -lGL -lGLU -lglut
RM = rm -f

ifeq ($(shell uname),Darwin)
CFLAGS = $(OPT) -Wall -ansi -pedantic-errors -Wno-deprecated-declarations
LDFLAGS = -lscene -framework GLUT -framework OpenGL
endif

target_dir  := bin
target_name := fbview
files       := fbview image_card framebuffer_viewer shader_program load_images
topdir      := ../..

incdir  := $(topdir)/src
libdir  := $(topdir)/lib
target  := $(topdir)/$(target_dir)/$(target_name)

sources := $(addsuffix .cc, $(files))
objects := $(addsuffix .o, $(files))
depends := $(addsuffix .d, $(files))

.PHONY: all clean depend
all: $(target)

$(objects): %.o: %.cc
	@echo '  compile $<'
	@$(CC) $(CFLAGS) -I$(incdir) -c -o $@ $<

$(target): $(objects)
	@echo '  link $(target_name)'
	@$(CC) -o $@ $^ -L$(libdir) $(LDFLAGS)

$(depends): %.d: %.cc
	@echo '  dependency $<'
	@$(CC) $(CFLAGS) -I$(incdir) -c -MM $< > $@

clean:
	@echo '  clean $(target_name)'
	@$(RM) $(target) $(objects) $(depends) 

ifneq "$(MAKECMDGOALS)" "clean"
-include $(depends)
endif


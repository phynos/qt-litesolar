#
#  Example Makefile for building a program with embedded Duktape.
#
#  There are two source sets in the distribution: (1) combined sources where
#  you only need duktape.c, duktape.h, and duk_config.h, and (2) separate
#  sources where you have a bunch of source and header files.  Whichever
#  you use, simply include the relevant sources into your C project.  This
#  Makefile uses the combined source file.
#

DUKTAPE_SOURCES = ../../3rd/duktape/duktape.c
DUKTAPE_MODULE_SOURCES = ../../3rd/duktape/extras/module-node/duk_module_node.c

# Compiler options are quite flexible.  GCC versions have a significant impact
# on the size of -Os code, e.g. gcc-4.6 is much worse than gcc-4.5.

CC	= gcc
CCOPTS	= -Os -pedantic -std=c99 -Wall -fstrict-aliasing -fomit-frame-pointer
CCOPTS += -I../../3rd/duktape  # for combined sources
CCLIBS	= -lm
DEFINES =

# If you want a 32-bit build on a 64-bit host
#CCOPTS += -m32

# Use the tools/configure.py utility to modify Duktape default configuration:
# http://duktape.org/guide.html#compiling
# http://wiki.duktape.org/Configuring.html

# For debugging, use -O0 -g -ggdb, and don't add -fomit-frame-pointer

js: duktape.so duk-module-node.so js.c
	$(CC) -o $@ $(DEFINES) $(CCOPTS) duktape.so duk-module-node.so js.c $(CCLIBS)

# 生成支持node形式模块的 动态库
shared-module:  duktape.so $(DUKTAPE_MODULE_SOURCES)
	$(CC) -shared -fPIC $(CCOPTS) -o duk-module-node.so duktape.so $(DUKTAPE_MODULE_SOURCES)  $(CCLIBS)	

# 生成动态库
shared: $(DUKTAPE_SOURCES)
	$(CC) -shared -fPIC $(CCOPTS) -o duktape.so $(DUKTAPE_SOURCES)  $(CCLIBS)
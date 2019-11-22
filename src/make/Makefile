
# sqlite3源码
SQLITE3_SOURCES = ../3rd/sqlite-3.24.0/sqlite3.c

# libmodbus源码
LIBMODBUS_SOURCES = ../3rd/libmodbus/modbus.c \
 ../3rd/libmodbus/modbus-data.c \
 ../3rd/libmodbus/modbus-rtu.c \
 ../3rd/libmodbus/modbus-tcp.c

# libmodbus lua绑定源码
LMODBUS_SOURCES = ../3rd/lua-libmodbus/lua-modbus.c
# sqlite3_lua绑定源码
LSQLITE3_SOURCES = ../3rd/lsqlite3/lsqlite3.c

# duktape源码
DUKTAPE_SOURCES = ../3rd/duktape/duktape.c
DUKTAPE_MODULE_SOURCES = ../3rd/duktape/extras/module-node/duk_module_node.c
DUKTAPE_CONSOLE_SOURCES = ../3rd/duktape/extras/console/duk_console.c

# Compiler options are quite flexible.  GCC versions have a significant impact
# on the size of -Os code, e.g. gcc-4.6 is much worse than gcc-4.5.

CC	= gcc
CCOPTS	= -Os -pedantic -std=c99 -Wall -fstrict-aliasing -fomit-frame-pointer -static
CCOPTS += -I../3rd/duktape  # duktape
CCOPTS += -I../3rd/libmodbus #libmodbus
CCOPTS += -I../3rd/lua-5.3.4/src #lua
CCOPTS += -I../3rd/sqlite-3.24.0 #sqlite3
CCLIBS	= -lm
DEFINES =


OUTPUT = ../bin

# If you want a 32-bit build on a 64-bit host
#CCOPTS += -m32

# For debugging, use -O0 -g -ggdb, and don't add -fomit-frame-pointer

3rd-all: duk-all libmodbus-all
	@echo 生成所有第三方的dll库

duk-all: duktape duk-module-node duk-console
	@echo 编译所有的duk模块

lua:
	@echo not surport....	

# duktape-生成支持node形式模块的 动态库
duk-module-node:  duktape $(DUKTAPE_MODULE_SOURCES)
	$(CC) -shared -fPIC $(CCOPTS) -o $(OUTPUT)/duk-module-node.dll $(OUTPUT)/duktape.dll $(DUKTAPE_MODULE_SOURCES)  $(CCLIBS)	

# duktape-生成支持node形式模块的 动态库
duk-console:  duktape $(DUKTAPE_CONSOLE_SOURCES)
	$(CC) -shared -fPIC $(CCOPTS) -o $(OUTPUT)/duk-console.dll $(OUTPUT)/duktape.dll $(DUKTAPE_CONSOLE_SOURCES)  $(CCLIBS)	

# duktape-生成动态库
duktape: $(DUKTAPE_SOURCES)
	$(CC) -shared -fPIC $(CCOPTS) -o $(OUTPUT)/duktape.dll $(DUKTAPE_SOURCES)  $(CCLIBS)

# libmodbus-生成动态库
libmodbus: $(LIBMODBUS_SOURCES)
	$(CC) -shared -fPIC $(CCOPTS) -o $(OUTPUT)/libmodbus.dll $(LIBMODBUS_SOURCES) $(CCLIBS) -lWs2_32

#sqlite3
sqlite3: $(SQLITE3_SOURCES)
	$(CC) -shared -fPIC $(CCOPTS) -o $(OUTPUT)/sqlite3.dll $(SQLITE3_SOURCES) $(CCLIBS)	

#lsqlite3
lsqlite3: $(LSQLITE3_SOURCES)
	$(CC) -shared -fPIC $(CCOPTS) -o $(OUTPUT)/lsqlite3.dll $(LSQLITE3_SOURCES) $(OUTPUT)/sqlite3.dll $(OUTPUT)/lua53.dll $(CCLIBS)	

#lmodbus
lmodbus: $(LMODBUS_SOURCES)
	$(CC) -shared -fPIC $(CCOPTS) -o $(OUTPUT)/lmodbus.dll $(LMODBUS_SOURCES) $(OUTPUT)/libmodbus.dll $(OUTPUT)/lua53.dll $(CCLIBS)
#ifndef JSMODULES_H
#define JSMODULES_H
#endif

#include "quickjs/quickjs.h";
#include "quickjs/cutils.h";

JSModuleDef *js_init_module_test(JSContext *ctx, const char *module_name);

JSModuleDef *js_init_module_modbus_slave(JSContext *ctx, const char *module_name);
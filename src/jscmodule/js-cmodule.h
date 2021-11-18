#ifndef JSCMODULE_H
#define JSCMODULE_H


#include "quickjs.h"
#include "cutils.h"

JSModuleDef *js_init_module_test(JSContext *ctx, const char *module_name);

JSModuleDef *js_init_module_modbus_slave(JSContext *ctx, const char *module_name);

#endif

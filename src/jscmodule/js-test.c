/**
 * 这里展示了如何将C模块和js引擎绑定
 * 
 * @file js-test.c
 * @author lupc (phynos@126.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "quickjs/quickjs.h"
#include "quickjs/cutils.h"

static JSValue plusNumbers(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    int a, b;

    if (JS_ToInt32(ctx, &a, argv[0]))
        return JS_EXCEPTION;
    
    if (JS_ToInt32(ctx, &b, argv[1]))
        return JS_EXCEPTION;
        
    return JS_NewInt32(ctx, a + b);
}

static const JSCFunctionListEntry js_test_funcs[] = {
    JS_CFUNC_DEF("plus", 2, plusNumbers),
};

static int js_test_init(JSContext *ctx, JSModuleDef *m)
{
    return JS_SetModuleExportList(ctx, m, js_test_funcs,
                                  countof(js_test_funcs));
}

JSModuleDef *js_init_module_test(JSContext *ctx, const char *module_name)
{
    JSModuleDef *m;
    m = JS_NewCModule(ctx, module_name, js_test_init);
    if (!m)
        return NULL;
    JS_AddModuleExportList(ctx, m, js_test_funcs, countof(js_test_funcs));
    return m;
}


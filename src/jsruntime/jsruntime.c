/**
 * 初始化一个标准的JS运行时
 * 
 * @file js-runtime.c
 * @author lupc (phynos@126.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <string.h>
#include "jsruntime.h"


int eval_buf(JSContext *ctx, const void *buf, int buf_len,
                    const char *filename, int eval_flags)
{
    JSValue val;
    int ret;

    if ((eval_flags & JS_EVAL_TYPE_MASK) == JS_EVAL_TYPE_MODULE)
    {
        /* for the modules, we compile then run to be able to set
           import.meta */
        val = JS_Eval(ctx, buf, buf_len, filename,
                      eval_flags | JS_EVAL_FLAG_COMPILE_ONLY);
        if (!JS_IsException(val))
        {
            js_module_set_import_meta(ctx, val, TRUE, TRUE);
            val = JS_EvalFunction(ctx, val);
        }
    }
    else
    {
        val = JS_Eval(ctx, buf, buf_len, filename, eval_flags);
    }
    if (JS_IsException(val))
    {
        js_std_dump_error(ctx);
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    JS_FreeValue(ctx, val);
    return ret;
}

int eval_file(JSContext *ctx, const char *filename, int module)
{
    uint8_t *buf;
    int ret, eval_flags;
    size_t buf_len;

    buf = js_load_file(ctx, &buf_len, filename);
    if (!buf)
    {
        perror(filename);
        exit(1);
    }

    if (module < 0)
    {
        module = (has_suffix(filename, ".mjs") ||
                  JS_DetectModule((const char *)buf, buf_len));
    }
    if (module)
        eval_flags = JS_EVAL_TYPE_MODULE;
    else
        eval_flags = JS_EVAL_TYPE_GLOBAL;
    ret = eval_buf(ctx, buf, buf_len, filename, eval_flags);
    js_free(ctx, buf);
    return ret;
}

JSRuntime *createJsRuntime()
{
    JSRuntime *rt;
    rt = JS_NewRuntime();
    /* loader for ES6 modules */
    JS_SetModuleLoaderFunc(rt, NULL, js_module_loader, NULL);
    return rt;
}

JSContext *createJsContext(JSRuntime *rt)
{
    JSContext *ctx;
    ctx = JS_NewContext(rt);
    js_init_module_std(ctx, "std");
    js_init_module_os(ctx, "os");
    // 自定义C模块
    js_init_module_test(ctx, "test");
    js_init_module_modbus_slave(ctx, "modbus");
    return ctx;
}

void initJsContextGlobal(JSContext *ctx)
{
    // 在这里可以添加各种cfunction和cmodule的扩展，提供给JS调用
    js_std_add_helpers(ctx, 0, 0);
}

void releaseJsRuntime(JSRuntime *rt)
{
    JS_FreeRuntime(rt);
}

void releaseJsContext(JSContext *ctx)
{
    JS_FreeContext(ctx);
}

void test_quickjs()
{
    JSRuntime *rt;
    JSContext *ctx;
    rt = createJsRuntime();
    ctx = createJsContext(rt);
    initJsContextGlobal(ctx);

    eval_file(ctx, "js/index.js", JS_EVAL_TYPE_MODULE);
    js_std_loop(ctx);

    releaseJsContext(ctx);
    releaseJsRuntime(rt);
}

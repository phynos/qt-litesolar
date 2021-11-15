/**
 * 这里展示了如何将libmodbus和js引擎绑定
 * 
 * @file js-modbus-slave.c
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
#include "libmodbus/modbus.h"

static JSClassID _js_modbus_class_id;

static void _js_modbus_finalizer(JSRuntime *rt, JSValue val)
{
    // 在js modbus对象被GC前，用来销毁C的CanvasContext对象
    modbus_t *mb = (modbus_t *)JS_GetOpaque(val, _js_modbus_class_id);
    if (mb)
    {
        //7-关闭modbus端口
        modbus_close(mb);

        //8-释放modbus资源
        modbus_free(mb);
    }
}
static JSClassDef _js_modbus_class = {
    "Modbus",
    .finalizer = _js_modbus_finalizer, // modbus_t GC前的资源回收
};

static JSValue js_modbus_connect(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    modbus_t *mb = (modbus_t *)JS_GetOpaque(this_val, _js_modbus_class_id);
    //建立连接
    if (modbus_connect(mb) == -1)
    {
        modbus_free(mb);
        return JS_EXCEPTION;
    }
    // 返回jscanvas对象
    return JS_NewString(ctx, "连接成功");
}

static JSValue js_modbus_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    modbus_t *mb;
    //1-打开端口
    mb = modbus_new_tcp("127.0.0.1", 502);
    //2-设置从地址
    modbus_set_slave(mb, 1);
    // 创建对应的JS对象
    JSValue obj = JS_NewObjectClass(ctx, _js_modbus_class_id);

    //注册基本属性
    JS_SetPropertyStr(ctx, obj, "ip",
                      JS_NewString(ctx, "127.0.0.1"));
    JS_SetPropertyStr(ctx, obj, "port",
                      JS_NewString(ctx, "502"));
    //在这里注册其他API
    JS_SetPropertyStr(ctx, obj, "connect", 
                      JS_NewCFunction(ctx, js_modbus_connect, "connect", 0));

    // 绑定canvas对象
    JS_SetOpaque(obj, mb);
    // 返回jscanvas对象
    return obj;
}

static const JSCFunctionListEntry js_modbus_slave_funcs[] = {
    JS_CFUNC_DEF("createTcp", 0, js_modbus_create),
};

static int js_modbus_slave_init(JSContext *ctx, JSModuleDef *m)
{
    // 定义JS的canvas类
    JS_NewClassID(&_js_modbus_class_id);
    JS_NewClass(JS_GetRuntime(ctx), _js_modbus_class_id, &_js_modbus_class);
    return JS_SetModuleExportList(ctx, m, js_modbus_slave_funcs,
                                  countof(js_modbus_slave_funcs));
}

JSModuleDef *js_init_module_modbus_slave(JSContext *ctx, const char *module_name)
{
    JSModuleDef *m;
    m = JS_NewCModule(ctx, module_name, js_modbus_slave_init);
    if (!m)
        return NULL;
    JS_AddModuleExportList(ctx, m, js_modbus_slave_funcs, countof(js_modbus_slave_funcs));
    return m;
}

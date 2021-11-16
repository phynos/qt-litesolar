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

#include "js-cmodule.h"
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
        return JS_NewBool(ctx, JS_FALSE);
    }
    // 返回连接结果
    return JS_NewBool(ctx, JS_TRUE);
}

static JSValue js_modbus_read(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    JSValue result,data;
    uint16_t tab_reg[64]={0};
    int offset,count;
    if (JS_ToInt32(ctx, &offset, argv[0]))
        return JS_EXCEPTION; 
    if (JS_ToInt32(ctx, &count, argv[1]))
        return JS_EXCEPTION;             
    modbus_t *mb = (modbus_t *)JS_GetOpaque(this_val, _js_modbus_class_id);
    
    memset(tab_reg,0,64*2);
    //读寄存器设置：寄存器地址、数量、数据缓冲
    int regs = modbus_read_registers(mb, offset, count, tab_reg);

    result = JS_NewObject(ctx);
    JS_SetPropertyStr(ctx, result, "count", JS_NewInt32(ctx, regs));
    if(regs > 0) {
        data = JS_NewArray(ctx);
        for (size_t i = 0; i < regs; i++)
        {
            JS_SetPropertyUint32(ctx, data, i, JS_NewInt32(ctx, tab_reg[i]));
        }        
    }
    JS_SetPropertyStr(ctx, result, "data", data);

    return result;
}

static JSValue js_modbus_create(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv)
{
    modbus_t *mb;
    int port;
    const char* ip;
    if(argc != 2)
        return JS_EXCEPTION;
    ip = JS_ToCString(ctx, argv[0]);      
    if (JS_ToInt32(ctx, &port, argv[1]))
        return JS_EXCEPTION;    
    //1-打开端口
    mb = modbus_new_tcp(ip, port);
    //2-设置从地址
    modbus_set_slave(mb, 1);
    // 创建对应的JS对象
    JSValue obj = JS_NewObjectClass(ctx, _js_modbus_class_id);

    //注册基本属性
    JS_SetPropertyStr(ctx, obj, "ip",
                      JS_NewString(ctx, ip));
    JS_SetPropertyStr(ctx, obj, "port",
                      JS_NewInt32(ctx, port));
    //在这里注册其他API
    JS_SetPropertyStr(ctx, obj, "connect", 
                      JS_NewCFunction(ctx, js_modbus_connect, "connect", 2));
    JS_SetPropertyStr(ctx, obj, "read", 
                      JS_NewCFunction(ctx, js_modbus_read, "read", 2));

    // 绑定JS对象
    JS_SetOpaque(obj, mb);
    // 返回JS对象
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

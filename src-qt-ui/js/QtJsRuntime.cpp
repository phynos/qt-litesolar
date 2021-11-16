

#include "QtJsRuntime.h"

#include <QDebug>

/**
 * 这里存储一个全局，用来从C回调中找到对应的对象
 * 
 */
QtJsRuntime *QtJsRuntime::gInstance = nullptr;

QtJsRuntime::QtJsRuntime(/* args */)
{
    gInstance = this;
    //初始化一个线程（内含消息循环），作为js的运行线程
    thread = new QThread();
    this->moveToThread(thread);
    //
    timer = new QTimer();
    timer->setInterval(3000);
    timer->moveToThread(thread);
    connect(timer, &QTimer::timeout, this, &QtJsRuntime::timeoutSlot);
}

QtJsRuntime::~QtJsRuntime()
{
    releaseJsRuntime(rt);
}

JSRuntime *QtJsRuntime::getJsRuntime()
{
    if (rt == NULL)
    {
        //初始化——必须和ctx在同一个线程创建
        rt = JS_NewRuntime();
        /* loader for ES6 modules */
        JS_SetModuleLoaderFunc(rt, NULL, js_module_loader, NULL);
    }
    return rt;
}

void QtJsRuntime::startThread()
{
    thread->start();
}

void QtJsRuntime::printThreadInfo(QString str)
{
    QString threadId;
    threadId.sprintf("%p", QThread::currentThread());
    emit sendMsgToMain(str + ":" + threadId);
}

void QtJsRuntime::runJsExpr(QString)
{
    JSContext *ctx;
    printThreadInfo("JS执行线程");
    ctx = createJsContext(getJsRuntime());

    releaseJsContext(ctx);
}

void QtJsRuntime::runJsIndexFile()
{
    JSContext *ctx;
    printThreadInfo("JS执行线程");
    ctx = createJsContext(getJsRuntime());

    mountJsGlobal(ctx);
    mountJsCModule(ctx);

    eval_file(ctx, "js/index.js", JS_EVAL_TYPE_MODULE);

    //todo 暂时用std的循环处理用户回调
    js_std_loop(ctx);

    releaseJsContext(ctx);
}

void QtJsRuntime::timeoutSlot() {
    printThreadInfo("JS定时器执行");
}

JSValue QtJsRuntime::jsPrintCallback(JSContext *ctx, JSValueConst this_val,
                                     int argc, JSValueConst *argv)
{
    int i;
    const char *str;
    size_t len;

    for (i = 0; i < argc; i++)
    {
        if (i != 0)
            qDebug() << " ";
        str = JS_ToCStringLen(ctx, &len, argv[i]);
        if (!str)
            return JS_EXCEPTION;
        QString str2 = QString::fromUtf8(str, len);
        emit gInstance->sendMsgToMain(str2);

        JS_FreeCString(ctx, str);
    }
    return JS_UNDEFINED;
}

void QtJsRuntime::mountJsGlobal(JSContext *ctx)
{
    JSValue global_obj, console;
    global_obj = JS_GetGlobalObject(ctx);

    console = JS_NewObject(ctx);
    JS_SetPropertyStr(ctx, console, "log",
                      JS_NewCFunction(ctx, QtJsRuntime::jsPrintCallback, "log", 1));
    JS_SetPropertyStr(ctx, global_obj, "console", console);
    JS_SetPropertyStr(ctx, global_obj, "print",
                      JS_NewCFunction(ctx, QtJsRuntime::jsPrintCallback, "print", 1));
    JS_FreeValue(ctx, global_obj);
}

void QtJsRuntime::mountJsCModule(JSContext *ctx)
{
    //这2个模块要替换
    js_init_module_std(ctx, "std");
    js_init_module_os(ctx, "os");
    // 自定义C模块
    js_init_module_test(ctx, "test");
    js_init_module_modbus_slave(ctx, "modbus");
}


#include "qtjsruntime.h"

#include <QDebug>
#include <QtConcurrent/QtConcurrent>

/**
 * 这里存储一个全局，用来从C回调中找到对应的对象
 * 
 */
QtJsRuntime *QtJsRuntime::gInstance = nullptr;

QtJsRuntime::QtJsRuntime(/* args */)
{
    gInstance = this;
    rt = NULL;
    //初始化一个线程（内含消息循环），作为js的运行线程
    thread = new QThread();
    thread->setObjectName("JsThread");
    this->moveToThread(thread);
    //预留一个定时器
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
    //初始化
}

bool QtJsRuntime::isThreadRunning()
{
    return thread->isRunning();
}

void QtJsRuntime::printThreadInfo(QString str)
{
    QString LogInfo;
    LogInfo.sprintf("%p", QThread::currentThread());
    qDebug() << str << " thread=" << LogInfo << ", threadObjectName" << QThread::currentThread()->objectName();
    emit sendMsgToMain(str + ":" + LogInfo + ":" + QThread::currentThread()->objectName());
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
    printThreadInfo("js thread");
    //初始化——必须和ctx在同一个线程创建
    getJsRuntime();
    ctx = JS_NewContext(rt);

    mountJsGlobal(ctx);
    mountJsSetTimeout(ctx);
    mountJsCModule(ctx);

    eval_file(ctx, "js/index.js", JS_EVAL_TYPE_MODULE);

    //因为QT线程有消息循环，这里不用再循环等待异步任务了

    releaseJsContext(ctx);
}

void QtJsRuntime::timeoutSlot()
{
    emit sendMsgToMain("JS定时器触发了");
    timer->stop();
}

void QtJsRuntime::mountJsSetTimeout(JSContext *ctx)
{
    JSValue global_obj, console;
    global_obj = JS_GetGlobalObject(ctx);
    JS_SetPropertyStr(ctx, global_obj, "setTimeout",
                      JS_NewCFunction(ctx, QtJsRuntime::jsCallSetTimeout, "setTimeout", 2));
    JS_FreeValue(ctx, global_obj);
}
void QtJsRuntime::jsCleanTimeout()
{
}

JSValue QtJsRuntime::jsCallSetTimeout(JSContext *ctx, JSValueConst this_val,
                                       int argc, JSValueConst *argv)
{
    emit gInstance->sendMsgToMain("JS调用了SetTimeout");

    int64_t delay;
    JSValueConst func;

    func = argv[0];
    if (!JS_IsFunction(ctx, func))
        return JS_ThrowTypeError(ctx, "not a function");
    if (JS_ToInt64(ctx, &delay, argv[1]))
        return JS_EXCEPTION;


    //这里启动定时器
    gInstance->timer->start(delay);

    return JS_UNDEFINED;
}

JSValue QtJsRuntime::jsCallPrint(JSContext *ctx, JSValueConst this_val,
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
                      JS_NewCFunction(ctx, QtJsRuntime::jsCallPrint, "log", 1));
    JS_SetPropertyStr(ctx, global_obj, "console", console);
    JS_SetPropertyStr(ctx, global_obj, "print",
                      JS_NewCFunction(ctx, QtJsRuntime::jsCallPrint, "print", 1));
    JS_FreeValue(ctx, global_obj);
}

void QtJsRuntime::mountJsCModule(JSContext *ctx)
{
    // 自定义C模块
    js_init_module_test(ctx, "test");
    js_init_module_modbus_slave(ctx, "modbus");
}

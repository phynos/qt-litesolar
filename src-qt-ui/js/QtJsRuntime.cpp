

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
}

QtJsRuntime::~QtJsRuntime()
{
    releaseJsRuntime(rt);
}

void QtJsRuntime::startThread() {    
    thread->start();
}

void QtJsRuntime::printThreadInfo() {
    QString LogInfo;
    LogInfo.sprintf("JS执行线程：%p", QThread::currentThread());
    emit sendMsgToMain(LogInfo);
}

void QtJsRuntime::runJsExpr(QString) {
    JSContext *ctx;
    printThreadInfo();
    if(rt == NULL) {
        //初始化——必须和ctx在同一个线程创建
        rt = createJsRuntime();
    }
    ctx = createJsContext(rt);



    releaseJsContext(ctx);
}

void QtJsRuntime::runJsIndexFile()
{
    JSContext *ctx;
    printThreadInfo();
    if(rt == NULL) {
        //初始化——必须和ctx在同一个线程创建
        rt = createJsRuntime();
    }
    ctx = createJsContext(rt);

    JSValue global_obj, console;
    global_obj = JS_GetGlobalObject(ctx);

    console = JS_NewObject(ctx);
    JS_SetPropertyStr(ctx, console, "log",
                      JS_NewCFunction(ctx, QtJsRuntime::jsPrintCallback, "log", 1));
    JS_SetPropertyStr(ctx, global_obj, "console", console);
    JS_SetPropertyStr(ctx, global_obj, "print",
                      JS_NewCFunction(ctx, QtJsRuntime::jsPrintCallback, "print", 1));
    JS_FreeValue(ctx, global_obj);

    eval_file(ctx, "js/index.js", JS_EVAL_TYPE_MODULE);
    js_std_loop(ctx);

    releaseJsContext(ctx);
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

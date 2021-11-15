

#include "QtJsRuntime.h"

#include <QDebug>

/**
 * 这里存储一个全局，用来从C回调中找到对应的对象
 * 
 */
QtJsRuntime *QtJsRuntime::JsBindPr = nullptr;

QtJsRuntime::QtJsRuntime(/* args */)
{
    JsBindPr = this;
    //初始化一个线程（内含消息循环），作为js的运行线程
    thread = new QThread();
    this->moveToThread(thread);
}

QtJsRuntime::~QtJsRuntime()
{
}

void QtJsRuntime::startThread() {    
    thread->start();    
}

void QtJsRuntime::runJsOnce()
{
    QString LogInfo;
    LogInfo.sprintf("JS执行线程：%p", QThread::currentThread());
    emit sendMsgToMain(LogInfo);
    JSRuntime *rt;
    JSContext *ctx;
    rt = createJsRuntime();
    ctx = createJsContext(rt);

    JSValue global_obj, console;
    global_obj = JS_GetGlobalObject(ctx);

    console = JS_NewObject(ctx);
    JS_SetPropertyStr(ctx, console, "log",
                      JS_NewCFunction(ctx, QtJsRuntime::print, "log", 1));
    JS_SetPropertyStr(ctx, global_obj, "console", console);
    JS_SetPropertyStr(ctx, global_obj, "print",
                      JS_NewCFunction(ctx, QtJsRuntime::print, "print", 1));
    JS_FreeValue(ctx, global_obj);

    eval_file(ctx, "js/index.js", JS_EVAL_TYPE_MODULE);
    js_std_loop(ctx);

    releaseJsContext(ctx);
    releaseJsRuntime(rt);
}

JSValue QtJsRuntime::print(JSContext *ctx, JSValueConst this_val,
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
        emit JsBindPr->sendMsgToMain(str2);

        JS_FreeCString(ctx, str);
    }
    return JS_UNDEFINED;
}

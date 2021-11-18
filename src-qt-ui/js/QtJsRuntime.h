#ifndef QTJSRUNTIME_H
#define QTJSRUNTIME_H

extern "C"
{
#include "jsruntime.h"
}
#include <QThread>
#include <QTimer>



class QtJsRuntime : public QObject
{
    Q_OBJECT
private:
    /* data */
    JSRuntime *rt;
    QThread *thread; //js实际运行的线程
    QTimer *timer;   //预留，作为settimeout的实现

    JSRuntime *getJsRuntime();
    void printThreadInfo(QString);
    void mountJsGlobal(JSContext *ctx);
    void mountJsCModule(JSContext *ctx);

    void mountJsSetTimeout(JSContext *ctx);
    void jsCleanTimeout();
    static JSValue jsCallSetTimeout(JSContext *ctx, JSValueConst this_val,
                                     int argc, JSValueConst *argv);
    static JSValue jsCallPrint(JSContext *ctx, JSValueConst this_val,
                                   int argc, JSValueConst *argv);

public Q_SLOTS:
    void runJsExpr(QString);
    void runJsIndexFile();
    void timeoutSlot();

public:
    QtJsRuntime(/* args */);
    static QtJsRuntime *gInstance;
    /**
     * 启动线程，作为JS的运行线程
     */
    void startThread();

    bool isThreadRunning();
    ~QtJsRuntime();

Q_SIGNALS:
    //给主线程发消息
    void sendMsgToMain(QString);
};

#endif

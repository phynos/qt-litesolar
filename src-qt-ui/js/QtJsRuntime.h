#ifndef QTJSBIND_H
#define QTJSBIND_H

extern "C"
{
#include "js-runtime.h"
}
#include <QThread>

class QtJsRuntime : public QObject
{
    Q_OBJECT
private:
    /* data */
    JSRuntime *rt;
    QThread *thread;

    void printThreadInfo();
    static JSValue jsPrintCallback(JSContext *ctx, JSValueConst this_val,
                         int argc, JSValueConst *argv);
public slots:
    void runJsExpr(QString);
    void runJsIndexFile();

public:
    QtJsRuntime(/* args */);
    static QtJsRuntime *gInstance;
    /**
     * 启动线程，作为JS的运行线程
     */
    void startThread();
    ~QtJsRuntime();

signals:
    //给主线程发消息
    void sendMsgToMain(QString);
};

#endif

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
    QThread *thread;
    static JSValue print(JSContext *ctx, JSValueConst this_val,
                         int argc, JSValueConst *argv);
public slots:
    void runJsOnce();

public:
    QtJsRuntime(/* args */);    
    /**
     * 启动线程，作为JS的运行线程
     */
    void startThread();
    static QtJsRuntime *JsBindPr;
    ~QtJsRuntime();

signals:
    //给主线程发消息
    void sendMsgToMain(QString);
};

#endif

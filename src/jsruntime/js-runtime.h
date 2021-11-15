#ifndef JSRUNTIME_H
#define JSRUNTIME_H


#include "quickjs/quickjs-libc.h"
#include "quickjs/quickjs.h"
#include "quickjs/cutils.h"

typedef struct qjs_engine {
    JSContext *ctx;
    JSRuntime *rt;
} qjs_engine;

JSRuntime *createJsRuntime();

JSContext *createJsContext(JSRuntime *rt);

void releaseJsRuntime(JSRuntime *rt);

void releaseJsContext(JSContext *ctx);

void test_quickjs();

#endif
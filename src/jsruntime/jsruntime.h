#ifndef JSRUNTIME_H
#define JSRUNTIME_H


#include "js-cmodule.h"

#include "quickjs-libc.h"
#include "quickjs.h"
#include "cutils.h"


typedef struct qjs_engine {
    JSContext *ctx;
    JSRuntime *rt;
} qjs_engine;

JSRuntime *createJsRuntime();

JSContext *createJsContext(JSRuntime *rt);

void initJsContextGlobal(JSContext *ctx);

void releaseJsRuntime(JSRuntime *rt);

void releaseJsContext(JSContext *ctx);

int eval_buf(JSContext *ctx, const void *buf, int buf_len,
                    const char *filename, int eval_flags);

int eval_file(JSContext *ctx, const char *filename, int module);

void test_quickjs();

#endif

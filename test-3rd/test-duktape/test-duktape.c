/*
 *  Very simple example program
 */

#include "duktape.h"

#include "extras/module-node/duk_module_node.h"
#include "extras/console/duk_console.h"

#include <windows.h>

/* For brevity assumes a maximum file length of 16kB. */
static void push_file_as_string(duk_context *ctx, const char *filename) {
    FILE *f;
    size_t len;
    char buf[16384];	
    f = fopen(filename, "rb");
    if (f) {
        len = fread((void *) buf, 1, sizeof(buf), f);
        fclose(f);
        duk_push_lstring(ctx, (const char *) buf, (duk_size_t) len);
    } else {
        duk_push_undefined(ctx);
    }
}

static duk_ret_t native_print(duk_context *ctx) {
	int len = 0;
	duk_push_string(ctx, " ");
	duk_insert(ctx, 0);
	duk_join(ctx, duk_get_top(ctx) - 1);
	//js 返回的字符
	const char * str = duk_safe_to_string(ctx, -1);
	len = strlen(str);
	//utf8 to unicode
	int n = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	wchar_t uni[n];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, uni, n); 
	//unicode to gbk
	int len3 = WideCharToMultiByte(CP_ACP, 0, uni, -1, NULL, 0, NULL, NULL);
	char gbk[len3];
	WideCharToMultiByte(CP_ACP, 0, uni, -1, gbk, len, NULL, NULL); 
	//
	printf("%s\n",gbk);
	//printf("长度：%d，%s\n", len,str);
	return 0;
}

static duk_ret_t cb_resolve_module(duk_context *ctx) {
	const char *module_id;
	const char *parent_id;

	module_id = duk_require_string(ctx, 0);
	parent_id = duk_require_string(ctx, 1);

	duk_push_sprintf(ctx, "%s.js", module_id);
	printf("resolve_cb: id:'%s', parent-id:'%s', resolve-to:'%s'\n",
		module_id, parent_id, duk_get_string(ctx, -1));

	return 1;
}

static duk_ret_t cb_load_module(duk_context *ctx) {
	const char *filename;
	const char *module_id;

	module_id = duk_require_string(ctx, 0);
	duk_get_prop_string(ctx, 2, "filename");
	filename = duk_require_string(ctx, -1);
	
	//这里稍微对文件名做一下处理（js文件必须都放在js目录下）	
	int len1 = strlen(filename);
	int len2 = strlen("js/");	
	//注意：这里str是局部数据，本函数执行完毕就会被回收
	char js_path[len1 + len2];
	memset(js_path, 0, len1 + len2);
	strcpy(js_path,"js/");
	strcat(js_path,filename);
	//printf("filename:%s\n", js_path);

	printf("load_cb: id:'%s', filename:'%s'\n", module_id, js_path);

	if (strcmp(module_id, "pig.js") == 0) {
		duk_push_sprintf(ctx, "module.exports = 'you\\'re about to get eaten by %s';",
			module_id);
	} else if (strcmp(module_id, "cow.js") == 0) {
		duk_push_string(ctx, "module.exports = require('pig');");
	} else if (strcmp(module_id, "ape.js") == 0) {
		duk_push_string(ctx, "module.exports = { module: module, __filename: __filename, wasLoaded: module.loaded };");
	} else if (strcmp(module_id, "badger.js") == 0) {
		duk_push_string(ctx, "exports.foo = 123; exports.bar = 234;");
	} else if (strcmp(module_id, "comment.js") == 0) {
		duk_push_string(ctx, "exports.foo = 123; exports.bar = 234; // comment");
	} else if (strcmp(module_id, "shebang.js") == 0) {
		duk_push_string(ctx, "#!ignored\nexports.foo = 123; exports.bar = 234;");
	} else {
		push_file_as_string(ctx,js_path);
		//(void) duk_type_error(ctx, "cannot find module: %s", module_id);
	}

	return 1;
}



static duk_ret_t native_adder(duk_context *ctx) {
	int i;
	int n = duk_get_top(ctx);  /* #args */
	double res = 0.0;

	for (i = 0; i < n; i++) {
		res += duk_to_number(ctx, i);
	}

	duk_push_number(ctx, res);
	return 1;  /* one return value */
}

int main(int argc, char *argv[]) {
	int a = 0;
	duk_context *ctx = duk_create_heap_default();

	(void) argc; (void) argv;  /* suppress warning */

	//加载 node模块
	duk_push_object(ctx);
	duk_push_c_function(ctx, cb_resolve_module, DUK_VARARGS);
	duk_put_prop_string(ctx, -2, "resolve");
	duk_push_c_function(ctx, cb_load_module, DUK_VARARGS);
	duk_put_prop_string(ctx, -2, "load");
	duk_module_node_init(ctx);
	//加载console模块
	duk_console_init(ctx, DUK_CONSOLE_PROXY_WRAPPER /*flags*/);

	duk_push_c_function(ctx, native_print, DUK_VARARGS);
	duk_put_global_string(ctx, "print");
	duk_push_c_function(ctx, native_adder, DUK_VARARGS);
	duk_put_global_string(ctx, "adder");

	duk_eval_string(ctx, "print('Hello world!');");

	duk_eval_string(ctx, "print('2+3=' + adder(2, 3));");
	duk_pop(ctx);  /* pop eval result */

    push_file_as_string(ctx, "js/index.js");
    if (duk_peval(ctx) != 0) {
        printf("Error running: %s\n", duk_safe_to_string(ctx, -1));
        goto finished;
    }
    duk_pop(ctx);  /* ignore result */

 finished:
    duk_destroy_heap(ctx);

	scanf("%d",&a); 

	return 0;
}

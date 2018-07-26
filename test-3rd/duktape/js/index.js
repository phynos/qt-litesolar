

var Test = require("lib-base");
var JsUtil = require("lib-util");


// 
print("js ----------------");

//中文注释
console.log("我是源码中的中文字符");

//
var t1 = new Test();
t1.setName("JackMa");
t1.toString();
var t2 = new Test();
t2.setName("Pony");
t2.toString();
t2.stringTest();

//
console.log(typeof(t1) === typeof(t2));
console.log(typeof(t1) == typeof(t2));


JsUtil.test(); 
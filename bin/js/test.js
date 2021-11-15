
import Persion from "./persion.js";
import {CalContext} from "./lib-rpn.js";

//中文编码测试
function testChar(){
	//中文测试-1
	console.log("char test-1:");
	print("abcd1234");
	print("中文字符1234");
	console.log("");

	//中文测试-2
	console.log("char test-2:");
	console.log("abcd1234");
	console.log("中文字符1234");
	console.log("");
}

//字符长度测试
function testCharLength(){
	var str1 = "123456789";
	console.log("want:9,actuly:" + str1.length);
	var str2 = "我是中文字符";
	console.log("want:6,actuly:" + str2.length);
	console.log("");
}

//对象类型测试
function testObject(){
	//
	console.log("object test:");
	console.log(typeof(Persion));
	console.log(Persion);
	console.log("");
	//
	console.log("object create test:");
	var t1 = new Persion();
	t1.setName("JackMa");
	t1.toString();
	var t2 = new Persion();
	t2.setName("Pony");
	t2.toString();
	console.log("");
	//
	console.log("object type test:");
	console.log(typeof(t1) === typeof(t2));
	console.log(typeof(t1) == typeof(t2));
	console.log("");
}


//复杂运算测试
function testRPN(){
    var context = new CalContext();
    //增加值栈——变量
    context.putData("$a",5);
    //增加值栈——无参数函数
    context.putFunction("fun0",function(){ return 1000;});
    //增加值栈——单参数函数
    context.putFunction("fun1",function(a){ return 10 * a;});
    //增加值栈——多参数函数
    context.putFunction("fun2",function(a,b){ return 10 * a + b;});
    //增加值栈——对象参数函数
    var t = {
      year: 28,
      fun: function(a) {
        return a + this.year;
      }
    };
    context.putFunction("fun3",t.fun,t);

    //获取值
    //var result = context.calc(expr);

    //下面是测试用例

    context.test("40+8*2",56);

    context.test("40*8+2",322);

    context.test("40/8+2",7);

    context.test("40+8/2",44);

    context.test("(40+8)/2",24);

    context.test("40*(8-2)",240);

    context.test("10%3 + 1",2);

    context.test("0.1 + 1 + 0.3",1.4);

    context.test("0.1 *10 + 6.3",7.3);

    context.test("$a + 5",10);

    context.test("$a + fun0()",1005);

    context.test("$a + fun0() + 100",1105);

    context.test("$a + fun1(1)",15);

    context.test("$a + fun2(2,1)",26);

    context.test("$a + fun2(3+7,3)",108);

    context.test("$a + fun2(fun1(2),3) + 20",228);
}


export {testChar, testCharLength, testObject, testRPN}
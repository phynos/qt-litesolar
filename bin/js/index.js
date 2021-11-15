

import {testChar, testCharLength, testObject, testRPN} from './test.js';

import {default as test} from "./lib/libtest.js";
import {default as modbus} from "./lib/libmodbus.js";

testChar();

testCharLength();

//testObject();

[1,2,3,4].map(a => a*a).forEach(b => console.log(b))

console.log(test.plus(1,2));

//modbus测试
var slave = modbus.createTcp("127.0.0.1", 502);
console.log("connect ip=", slave.ip);
console.log("connect port=", slave.port);
try {    
    var result = slave.connect();
    if(result) {
        console.log("连接成功");
        var result = slave.read(0,4);
        console.log(result.count);
        console.log(result.data.map(a => a+"").join(","));
    } else {
        console.log("连接失败");
    }
} catch (error) {
    console.log(error); 
}






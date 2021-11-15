

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
var result = slave.connect();
console.log(result);
var result = slave.read(0,4);
console.log(result.count);
console.log(result.data.map(a => a+"").join(","));



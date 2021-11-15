

import {testChar, testCharLength, testObject, testRPN} from './test.js';

import {default as test} from "./lib/libtest.js";
import {default as modbus} from "./lib/libmodbus.js";

testChar();

testCharLength();

//testObject();

[1,2,3,4].map(a => a*a).forEach(b => console.log(b))

console.log(test.plus(1,2));

var slave = modbus.createTcp("127.0.0.1", 502);
for(var p in slave) {
    var v = slave[p];
    console.log("name=" + p + ", value=" + v);
}
var result = slave.connect();
console.log(result);


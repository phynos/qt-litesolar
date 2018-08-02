
var JsUtil = require("util/lib-util");

function Persion(){
	console.log("Persion created.");
}

Persion.prototype.setName = function(name){
	this.name = name;
}

Persion.prototype.toString = function() {
	console.log("type:" + typeof(this) + ",name:" + this.name);
};

module.exports = Persion;
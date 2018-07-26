


function Test(){
	print("test-base");
}

Test.prototype.setName = function(name){
	this.name = name;
}

Test.prototype.toString = function() {
	console.log("type:" + typeof(this) + ",name:" + this.name);
};

Test.prototype.stringTest = function() {
	var str1 = "123456789";
	console.log("want:9,actuly:" + str1.length);
	var str2 = "我是中文字符";
	console.log("want:6,actuly:" + str2.length);
};

module.exports = Test;
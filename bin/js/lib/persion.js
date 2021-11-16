

export default class Persion {
	constructor() {
		console.log("Persion created.");
	}
	
	setName(name) {
		this.name = name;
	}

	toString() {
		console.log("type:" + typeof(this) + ",name:" + this.name);
	}
}
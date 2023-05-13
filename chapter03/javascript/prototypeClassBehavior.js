function Person(name, age) {
	this.name = name;
	this.age  = age;
}

Person.prototype.sayHello = function () {
	console.log("hello, my name is " + this.name);
}

var john = new Person("john", 32);

//console.log("name: '", john.name, "' age: '", john.age, "'");
console.log("{name: '" + john.name+ "', age: '" + john.age+ "'}");

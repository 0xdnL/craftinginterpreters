var person = {
  name: "John",
  age: 30,
  sayHello: function() {
    console.log("Hello, my name is " + this.name);
  }
};

var student = Object.create(person); // create object that inherits from the prototype
student.studentID = "12345";

// use the inherited properties and methods
console.log(student.name);
console.log(student.age);
student.sayHello();

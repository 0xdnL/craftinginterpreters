# classes

- js-class doesn't offer addition functionality and syntactical sugar
- a js class is a type of function
- classes are declared with using `class` keyword

https://www.digitalocean.com/community/tutorials/understanding-classes-in-javascript

## operator: new

- `new` creates an instance of used-defined object type
  or a built-in object type that has a constructor function
- `new` sets new objects private property: `__proto__`
- `__proto__` property holds link to another object called its "prototype"
- js-runtim looks up `__proto__`chain


https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/new
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Inheritance_and_the_prototype_chain

## dynamic dispatch

- process of selecting which implementation of polymorphic operation to call at runtime
- static dispatch selects implementation at compiletime


```js
dividend.divide(divisor)  // dividend / divisor
```

- sending a message `divide` with parameter `divisor` to `divident`

https://en.wikipedia.org/wiki/Dynamic_dispatch

## keyword: static

- defines a values that is shared across all instances of the class

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes/static
https://www.baeldung.com/java-static
https://www.javatpoint.com/static-keyword-in-java


```js
class Car {
  constructor(maker, model) {
    this.maker = maker;
    this.model = model;
  }

  drive() {
      console.log("Zoom!");
  }
}

const tesla = new Car('Tesla', '3');
tesla.drive();

class Tesla extends Car {
    constructor(model, chargetime) {
        super('Tesla', model);
        this.chargetime = chargetime;
    }

    charge() {
        console.log("Charging...");
    }
}

const tesla = new Tesla('3', 20);
tesla.drive();
tesla.charge();
```


```js
function Car(maker, model) {
    this.maker = maker;
    this.model = model;
}

const tesla = new Car('Tesla', '3');

Car.prototype.drive = function() {
    console.log("Zoom!");
}

tesla.drive();
```


```js
const parentM = {
  value: 2,
  method() {
    return this.value + 1;
  },
};

const parentF = {
  value: 4,
  method() {
    return this.value * 2;
  },
};

console.log(parent.method()); // 3
// When calling parent.method in this case, 'this' refers to parent

// child is an object that inherits from parent
const child = {
  __proto__: parentM,
};

Object.getPrototypeOf(child)
Object.setPrototypeOf(child, parentF)  // this is slow !
Object.getPrototypeOf(child)
```


```js
class Bar {
  constructor(x) {
    this.x = x;
  }
  getX () {
    return this.x
  }
}

function Bar(x) {
  this.x = x;
}
Bar.prototype.getX = function getX() {
  return this.x;
}
```

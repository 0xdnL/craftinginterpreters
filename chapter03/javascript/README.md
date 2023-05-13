# javascript classes via prototypes

- js is one of the few languages using prototype
- lua and scheme use prototypes too

remembered this project TAL, in which classes were implemented using prototypes

## setup

```sh
nvm install 5.12.0  # use version that does not have class keyword
nvm use 5.12.0
```

[node.green](https://node.green/)

## usage

```sh
node FILE.js
```

```js
.load FILE.js
```

## javascript

```sh
function Cat(name) {
  this.name = name;
}

Cat.prototype.meow = function meow() {
  console.log(this.name + ": meow!");
}

let cat = new Cat("jim");

cat.meow();

cat
cat.__proto__
```

## see also

- [bbc.github.io/tal/overview/concepts.html](https://bbc.github.io/tal/overview/concepts.html)
- [johnresig.com/blog/simple-javascript-inheritance/](https://johnresig.com/blog/simple-javascript-inheritance/)
- [prototypejs.org/learn/class-inheritance](http://prototypejs.org/learn/class-inheritance)
- [en.wikipedia.org/wiki/Immediately_invoked_function_expression](https://en.wikipedia.org/wiki/Immediately_invoked_function_expression)

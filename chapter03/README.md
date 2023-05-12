# chapter 03 challenge


```sh
git@github.com:munificent/craftinginterpreters.git cd ./craftinginterpreters

brew tap dart-lang/dart && brew install dart    # optional, not needed for lox

make clox cpplox   # compile cpp and c implementation of lox

cd ./build

./clox FILE


cat <<EOF > helloworld.lox
class Foo {

// var name;   // class properties only via init()
// age;

  init(name, age){    // only one type possible
    this.name = name;
    if (age != "0") {
      this.age = age;
    }
  }

  sayHello(times) {
    for (var i=0;i<times;i =i+1) {
      print("helloworld");
    }
  }
//  /*String*/    // no start comment notation
  getName() {
    return this.name;
  }

  getAge() {
    return this.age;
  }

  addHobby(hoby) {

  }
}

var foo = Foo("bar","1");

foo.sayHello(3);

print("hello i am: " + foo.getName() + "I'm " + foo.getAge() + "years old.");


// var array = [1,2,3];     // no arrays
EOF

./clox helloworld.lox
```

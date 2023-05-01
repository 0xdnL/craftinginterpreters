# helloworld in java

## usage

```sh
javac -d  target/classes src/main/java/HelloWorld.java
java  -cp target/classes src.main.java.HelloWorld
```

## example java classpath

```sh
mkdir -p com/test

cat <<EOF > com/test/HelloWorld.java
package com.test;

public class HelloWorld {
  public static void main(String[] args) {
    System.out.println("hello world");
  }
}
EOF

javac com/test/HelloWorld.java
java com.test.HelloWorld

rip com/test
```

## makefiles and java

- https://gist.github.com/the-mikedavis/23a4c0fc4e2338c5535c3b2245257c83
- https://stackoverflow.com/questions/29184999/making-a-java-makefile
- https://www.cs.swarthmore.edu/~newhall/unixhelp/javamakefiles.html
- https://www.oreilly.com/library/view/managing-projects-with/0596006101/ch09.html

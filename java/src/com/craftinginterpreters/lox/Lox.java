package com.craftinginterpreters.lox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

// javac -cp gen/chap04_scanning -d build/gen/chap04_scanning -Werror -implicit:none gen/chap04_scanning/com/craftinginterpreters/lox/Lox.java
// javac -cp CLASSPATH           -d build/CLASSPATH           -Werror -implicit:none CLASSPATH/com/craftinginterpreters/lox/Lox.java


// javac -d target/classes -implicit:none src/com/craftinginterpreters/lox/Lox.java
// java -cp target/classes com/craftinginterpreters/lox/Lox


// javac -cp . -d target/classes -implicit:none  src/com/craftinginterpreters/lox/Lox.java
// java  -cp target/classes                          com/craftinginterpreters/lox/Lox

public class Lox {

  static boolean hadError = false;

  public static void main(String[] args) throws IOException {

    if(args.length < 1) {
      System.out.println("Usage: jlox [script]");
    } else if (args.length == 1) {
      runFile(args[0]);
    } else {
      runPrompt();
    }
  }


  private static void runFile(String path) throws IOException {
    byte[] bytes = Files.readAllBytes(Paths.get(path));
    run(new String(bytes, Charset.defaultCharset()));

    if(hadError) System.exit(65);
  }

  private static void runPrompt() throws IOException {
    InputStreamReader input = new InputStreamReader(System.in);
    BufferedReader   reader = new BufferedReader(input);

    for(;;) {
      System.out.println("> ");
      String line = reader.readLine();
      if (line == null) break;
      run(line);
      hadError = false; // reset, mistake shouldn't kill session
    }
  }

  private static void run(String source) {
    Scanner scanner = new Scanner(source);
    List<Token> tokens = scanner.scanTokens();

    for(Token token: tokens) {
      System.out.println(token);
    }
  }


  static void error(int line, String message) {
    report(line, "", message);
  }

  private static void report(int line, String where, String message) {
    System.err.println("" + where + ": " + message);
    hadError = true;
  }
}

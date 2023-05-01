package src.main.java;

public class Application {

  private String name;

  public String greet(String s) {
    return "hello " + s + "I " + this.name + "greet you";
  }

  public void setName (String p) {
    this.name = p;
  }

  /**
   * @param args
   */
  public static void main(String[] args) {
    System.out.println("Application: hello world");

    Application app = new Application();
    app.setName("herbert");
    System.out.println(app.greet("human"));
  }
}

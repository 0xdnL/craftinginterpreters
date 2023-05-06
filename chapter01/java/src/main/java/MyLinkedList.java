package src.main.java;

class MyLinkedList {

  class Node {
    int value;
    Node next;  // java has no pointers but references = "pointers with training wheels"

    Node(int value, Node next) {
      this.value = value;
      this.next = next;
    }
  }

  Node head;

  MyLinkedList() {
    head = null;
  }

  void add (int newvalue) {
    Node newnode = new Node(newvalue, head);
    head = newnode;
  }

  public String toString() {
    Node tmp = head;
    String result = "[";
    while (tmp != null) {
      result = result + Integer.toString(tmp.value) + " - ";
      tmp = tmp.next;
    }
    result += "]";
    return result;
  }
}

package src.main.java;

import java.util.*;

class LenkedLest {

  public static void main(String[] args) {
    LinkedList<Integer> intList = new LinkedList<Integer>();

    intList.add(123);
    intList.add(456);
    intList.add(789);
    intList.add(900);
    System.out.println(intList);


    LinkedList<String> domesticAnimals = new LinkedList<>(
    List.of("cow", "hen", "goat", "sheep", "donkey"));
    System.out.println(domesticAnimals);
    // for (int i = 0; i < domesticAnimals.size(); i++) {
    //   System.out.println(i +" = "+domesticAnimals.get(i));
    // }

    MyLinkedList myLinkedList = new MyLinkedList();
    myLinkedList.add(0);
    myLinkedList.add(1);
    myLinkedList.add(2);

    System.out.println(myLinkedList);
  }
}

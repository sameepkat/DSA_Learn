
class Node {
  int data;
  Node next;

  public Node(int data) {
    this.data = data;
    this.next = null;
  }
};

public class singly_linked_list {
  private Node head;

  public void append(int data) {
    if (head == null) {
      head = new Node(data);
      return;
    }
    Node current = head;
    while (current.next != null) {
      current = current.next;
    }
    current.next = new Node(data);
  }

  public void prepend(int data) {
    Node newHead = new Node(data);
    newHead.next = head;
    head = newHead;
  }

  public void deleteWithValue(int data) {
    if (head == null)
      return;
    if (head.data == data) {
      head = head.next;
      return;
    }

    Node current = head;
    while (current.next != null) {
      if (current.next.data == data) {
        current.next = current.next.next;
        return;
      }
      current = current.next;
    }
  }

  public void printList() {
    Node current = head;
    while (current != null) {
      System.out.println(current.data + " -> ");
      current = current.next;
    }
    System.out.println("null");
  }

  public static void main(String[] args) {
    singly_linked_list list = new singly_linked_list();

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(6);
    list.printList();

    System.out.println("Deleting");
    list.deleteWithValue(20);
    list.printList();
  }
};

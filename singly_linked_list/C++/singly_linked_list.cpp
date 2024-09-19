#include <iostream>
#include <vector>

class Node{
  public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
      data = data1;
      next = next1;
    } 

    Node(int data1) {
      data = data1;
      next = nullptr;
    }
};

int main (int argc, char *argv[]) {
  std::vector<int> arr = {2, 5, 8, 7}; 
  Node* y = new Node(arr[0], nullptr); 
  std::cout << y->data;
  return 0;
}


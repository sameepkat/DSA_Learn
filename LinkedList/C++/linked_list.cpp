#include <iostream>

class Node {
  public:
  int value;
  Node* next;
};

Node* head = NULL;

void insertBeginning(int data)
{
  Node* newNode;
  newNode = new Node();
  newNode->value = data;
  if(head == NULL)
  {
    newNode->next = NULL;
    head = newNode;
  }else{
    newNode->next = head;
    head = newNode;
  }
}

void insertEnd(int data){
  Node* newNode;
  newNode = new Node();
  newNode->value = data;
  newNode->next = NULL;
  if(head == NULL){
    head = newNode;
  }else {
    Node *temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void insertAfter(int data, int location)
{
  Node *newNode;
  newNode = new Node();
  newNode->value = data;
  if(head == NULL){
    newNode->next = NULL;
    head=  newNode;
  }else{
    Node* temp = head;
    while(temp->value != location)
    {
      temp = temp->next;
    }
    newNode->next = temp ->next;
    temp->next = newNode;
  }
}

void deleteBeginning()
{
  if(head == NULL)
    std::cout << "Empty List.. " << std::endl;
  else{
    Node* temp = head;
    if(temp->next == NULL)
      head = NULL;
    else{
      head = temp->next;
    }
    delete temp;
  }
}

void deleteEnd()
{
  if(head == NULL)
    std::cout << "Empty Lidt.. " << std::endl;
  else{
    Node* temp1 = head, *temp2;
    if(temp1->next == NULL)
      head = NULL;
  else{
      while(temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
      }
      temp2->next = NULL;
    }
    delete temp1;
  }
}

void deleteSpecific(int deleteData){
  if (head == NULL){
    std::cout << "Empty List.. " << std::endl;
  }else{
    Node* temp1 = head;
    Node* temp2;
    if(temp1->next == NULL){
      if(temp1->value == deleteData){
        head = NULL;
        delete temp1;
      }else{
        std::cout << "Node not found.";
      }
    }else{
      while(temp1->value != deleteData){
        temp2 = temp1;
        temp1 = temp1->next;
      }
      if(temp1 == head){
        head = temp1->next;
      }else if(temp1->next == NULL){
        temp2->next = NULL;
      }else{
        temp2->next = temp1->next;
      }
    }
  }
}

void traverse(){
  if(head == NULL)
    std::cout << "List is empty." << std::endl;
  else{
    Node* temp = head;
    while(temp != NULL){
      std::cout << temp->value << "  ";
      temp = temp->next;
    }
  }
}

int main()
{
  insertEnd(22);
  insertBeginning(11);
  insertAfter(33, 22);

  traverse();
  
  deleteSpecific(22);
  std::cout << std::endl;

  traverse();

  return 0;
}


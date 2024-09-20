#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

Node* head = NULL;

void push(int n)
{
  Node* temp= malloc(sizeof(Node));
  temp->data = n;
  temp->next = NULL;
  if(!head)
  {
    head = temp;
  }else{
    Node* current = head;
    while(current->next) // Get to the end node
    {
      current = current->next;
    }
    current->next = temp;
  }
}

void display()
{
  Node* current = head;
  while(current)
  {
    printf("%d\n", current->data);
    current = current->next;
  }
  printf("END\n");
}

int main(int argc, char *argv[])
{
  push(1);
  push(2);
  push(3);
  display();
  return EXIT_SUCCESS;
}

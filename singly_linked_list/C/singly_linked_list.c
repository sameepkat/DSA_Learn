#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;

int main(int argc, char *argv[])
{
  Node* head = NULL;
  for(int i=1; i < argc ; i++)
  {
    int number = atoi(argv[i]);
    Node *temp = malloc(sizeof(Node));
    if(temp==NULL) return 1;
    temp->data = number;
    temp->next = head;
    head = temp;
  }
  Node *list = head;
  while(list)
  {
    printf("%i\n",list->data);
    list = list->next;
  }
  list = head;
  while(list)
  {
    Node *next = list->next;
    free(list);
    list = next;
  }
  return 0;
}

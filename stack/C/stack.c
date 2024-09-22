#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct Stack{
  int arr[MAX];
  int top;
};

void initStack(struct Stack* stack)
{
  stack->top=-1; 
}

int isEmpty(struct Stack* stack){
  return stack->top ==-1;
}
int isFull(struct Stack* stack){
  return stack->top==MAX-1;
}
void push(struct Stack* stack, int value){
  if(isFull(stack)){
    printf("Stack overflow! Cannot push\n");
  }else{
    stack->arr[++(stack->top)] = value;
    printf("Pushed %d to the stack.\n", value);
  }
}

int pop(struct Stack* stack){
  if(isEmpty(stack)){
    printf("Stack overflow! No elements to pop");
    return -1;
  }else{
    return stack->arr[(stack->top)--];
  }
}

int peek(struct Stack* stack){
  if(isEmpty(stack)){
    printf("Stack is empty.\n");
  }else{
    return stack->arr[stack->top];
  }
}

int main(int argc, char *argv[])
{
  struct Stack stack;
  initStack(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);
  push(&stack, 40);
  push(&stack, 50);
  push(&stack, 60);
  printf("Top element is %d.\n",peek(&stack));
  printf("Popped element is %d.\n",pop(&stack));
  printf("Popped element is %d.\n",pop(&stack));
  printf("Top element after popping is %d.\n",peek(&stack));
  return EXIT_SUCCESS;
}

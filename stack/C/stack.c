#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

typedef enum{false, true} bool;

typedef struct
{
	int size, top;
	int *STACK;
}stack;

void init(stack* s, int SIZE)
{
	s->size = SIZE;
	s->STACK = (int*)malloc(sizeof(int));
	s->top = -1;
}

bool isEmpty(stack* s)
{
	if(s->top == -1)
		return true;
	else
		return false;
}

bool isFull(stack* s)
{
	if(s->top == s->size - 1)
		return true;
	else
		return false;
}

void push(stack* s, int item)
{
	if(isFull(s)){
		perror("Stack overflow\n");
		exit(1);
		}
	else{
		s->top++;
		s->STACK[s->top] = item;
	}
}

int pop(stack* s)
{
	if(isEmpty(s)){
		perror("Stack underflow\n");
		exit(1);
	}
	else{
		int item = s->STACK[s->top];
		s->top--;
		return item;
	}
}

void display(stack* s)
{
	printf("Items in the stack: \n");
	while(s->top!=-1){
		printf("%d\n",s->STACK[s->top]);
		s->top--;
	}
}

int main()
{
	stack s;
	init(&s, 5);
	push(&s, 5);
	push(&s, 2);
	push(&s, 1);
	display(&s);
}

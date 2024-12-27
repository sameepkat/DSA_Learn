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
	s->STACK = (int*)malloc(SIZE * sizeof(int));
	if(s->STACK == NULL){
		perror("Memory allocation failed.");
	}
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
	int i = s->top;
	while(i!=-1){
		printf("%d\n",s->STACK[i]);
		i--;
	}
}

void destroy(stack* s)
{
	free(s->STACK);
}

int main()
{
	stack s;
	init(&s, 5);
	push(&s, 5);
	push(&s, 2);
	push(&s, 1);
	display(&s);
	destroy(&s);
}

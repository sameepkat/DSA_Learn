#include <iostream>
#include <stdexcept>

class stack
{
	int size, top;
	int *STACK;
	public:
		stack(int);
		bool isFull();
		bool isEmpty();
		int pop();
		void push(int item);
		void display();
		~stack(){
			delete[] STACK;
		}
};

stack::stack(int SIZE)
{
	size = SIZE;
	STACK = new int[size];
	top = -1;
}

bool stack::isEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}

bool  stack::isFull()
{
	if(top==size-1)
		return true;
	else
		return false;
}

void stack::push(int item)
{
	if(isFull())
		std::cout << "Stack overflow\n";
	else{
		top++;
		STACK[top] = item;
	}
}

int stack::pop()
{
	int item;
	if(isEmpty()){
		throw std::runtime_error("Stack underflow");
	}else{
		item = STACK[top];
		top--;
		return item;
	}
}

void  stack::display()
{
	std::cout << "Items in the stack: \n";
  int count = top;
	while(count!=-1){
		std::cout << STACK[count] << "\n";
		count --;
	}
}

int main()
{
	stack s(3);
	s.push(5);
	s.push(2);
	s.push(1);
	s.display();
  std::cout << "Popped: " << s.pop() << std::endl;
  s.display();
}

#include <iostream>

class node
{
public:
	int info;
	node *next;

	node *top = NULL;

	void push(int data)
	{
		node *newNode;
		newNode = new node();
		newNode->info = data;
		if(top == NULL)
			{
				newNode->next = NULL;
				top = newNode;
			}
		else{
			newNode->next = top;
			top = newNode;
		}
	}

	int pop()
	{
		int item = -1;
		if(top == NULL)
			{
				throw std::runtime_error("Stack is empty");
			}
		else{
			node *temp = top;
			item = temp -> info;
			if(temp->next == NULL)
				{
					top = NULL;
				}
			else{
				top = temp->next;
			}
			delete temp;
			return item;
		}
	}

	void display()
	{
		if(top == NULL)
			{
				throw std::runtime_error("Stack: empty\n");
			}
		else{
			node *temp = top;
			std::cout << "Stack is: ";
			while(temp != NULL)
				{
					std::cout << temp->info << "  ";
					temp = temp->next;
				}
			std::cout << "\n";
		}
	}
};

int main()
{
	node n1;
	n1.push(5);
	n1.push(4);
	n1.push(3);
	n1.push(2);
	n1.push(1);
	n1.display();
}

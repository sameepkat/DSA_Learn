#include <iostream>
class node
{
public:
		int info;
		node *next;

		node *front = NULL;
		node* rear = NULL;

		void enqueue(int data)
		{
				node *newNode;
				newNode = new node();
				newNode->info = data;
				newNode->next = NULL;
				if(rear == NULL)
						{
						rear = newNode;
						front = newNode;
						}
				else
						{
						rear->next = newNode;
						rear = newNode;
						}
				}

		int dequeue()
		{
		int item = -1;
		if(front == NULL){
				throw std::runtime_error("Queue is empty.\n");
		}
		else
				{
				node* temp = front;
				item = temp->info;
				if(temp->next == NULL)
						{
						front = NULL;
						}
				else{
						front = temp->next;
				}
				delete temp;
				return item;
				}
		}


		void display()
		{
		if(front == NULL)
				{
				throw std::runtime_error("Queue empty\n");
				}
		else
				{
				node* temp = front;
				std::cout << "Queue is: ";
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
	n1.enqueue(5);
	n1.enqueue(4);
	n1.enqueue(3);
	n1.enqueue(2);
	n1.enqueue(1);
	n1.display();

}

#include <iostream>
#define SIZE 10

class Queue{
  int a[SIZE];
  int rear;
  int front;
public:
  Queue(){
    rear = front  = -1;
  }

  void enqueue(int x);
  int dequeue();
  void display();
  ~Queue(){}
};

void Queue::enqueue(int x){
  if(front==-1) front++;
  if(rear==SIZE-1) std::cout << "Queue is full\n";
  else{
    rear++;
    a[rear] = x;
  }
}

int Queue::dequeue(){
  int i, item;
  if(rear == -1){
    std::cout << "Empty Queue";
    return 0;
  }else{
    item = a[front];
    for(i=0;i<rear; i++)a[i] = a[i+1];
  }
  rear--;
  return item;
}

/* // Second implementation of queue without shifting -> Creates holes
int Queue::dequeue(){
  int item;
  if(front == -1 || front> rear){
    std::cout << "Queue is empty\n";
  }else{
    item = a[front];
    front++;
    return item;
  }
}
*/

void Queue::display()
{
  int i;
  if(front==-1||rear==-1||front>rear)std::cout<< "Nothing to display\n";
  else{
    for(int i = front; i<= rear; i++){
      std::cout << a[i] << std::endl;
    }
  }
}

int main (int argc, char *argv[]) {
  Queue q;
  q.enqueue(5);
  q.enqueue(4);
  q.enqueue(3);
  q.enqueue(2);
  q.enqueue(1);
  q.dequeue();
  q.display();
  return 0;
}

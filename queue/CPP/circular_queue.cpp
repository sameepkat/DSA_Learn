#include <iostream>
#define SIZE 5
class Queue{
  private:
    int items[SIZE], front, rear;
  public:
    Queue(){ front = rear = -1; } 
    bool isFull();
    bool isEmpty();
    void enQueue(int element);
    int deQueue();
    void display();
    ~Queue(){}
};

bool Queue::isFull(){
  if (front == (rear+1)%SIZE) {
    return true; 
  }else{
    return false;
  }
}

bool Queue::isEmpty(){
  if(front == -1)
    return true;
  else {
    return false;
  }
}

void Queue::enQueue(int element){
  if(isFull()){
    std::cout << "Queue is full\n";
  }else{
    if(front == -1 ) front == 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
  }
}

int Queue::deQueue(){
  int element;
  if(isEmpty()){
    std::cerr << "Queue is empty\n";
    return -1;
  }else{
    element = items[front];
    if(front==rear){
      front = -1;
      rear = -1;
    }else{
      front = (front+1) % SIZE;
    }
    return element;
  }
}

void Queue::display(){
  if(isEmpty())
    std::cout << "Empty queue" << std::endl;
  else{
    std::cout << "Front -> " << front;
    std::cout << "\nItems -> ";
    for (int i = 0; i!=rear; (i+1)%SIZE) {
      std::cout << items[i]; 
    }
    std::cout << "\nRear -> " << std::endl;
  }
}

int main()
{
  Queue q;
  q.deQueue();
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);
  q.enQueue(6);
  q.display();
  int elem = q.deQueue();
  if(elem!=-1)
    std::cout << "\n Deleted Element is " << elem;
  q.display();
  q.enQueue(7);
  q.display();
  q.enQueue(8);
  return 0;
}

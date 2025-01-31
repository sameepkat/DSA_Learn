#include <iostream>
#define SIZE 5
class Queue{
  private:
    int items[SIZE], front, rear;
  public:
    Queue(){ front = -1; rear = -1; } 
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
  else
    return false;
}

void Queue::enQueue(int element){
  if(isFull()){
    std::cout << "Queue is full\n";
  }else{
    if(front == -1 && rear == -1){ front = rear = 0;}
    else{
      rear = (rear + 1) % SIZE;
    }
      items[rear] = element;
  }
}

int Queue::deQueue(){
  int element;
  if(isEmpty()){
    return -1;
  }else{
    element = items[front];
    if(front==rear){
      front = -1;
      rear = -1;
    }else{
      front = (front+1) % SIZE;
    }
  }
    return element;
}

void Queue::display(){
  if(isEmpty()){
    std::cout << "Empty queue\n" << std::endl;
  }
  else{
    std::cout << "Front -> " << front;
    std::cout << "\nItems -> ";
    for (int i = front; i!=rear; i = (i+1)%SIZE) {
      std::cout << items[i] << "  "; 
    }
    std::cout << std::endl;
  }
}

int main()
{
  Queue q;
  q.enQueue(1);
 q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.display();
  int elem = q.deQueue();
  if(elem!=-1)
    std::cout << "\nDeleted Element is " << elem << std::endl;
  q.display();
  q.enQueue(7);
  q.display();
  return 0;
}

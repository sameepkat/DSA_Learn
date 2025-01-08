// USing unsorted array;
#include <iostream>
class PriorityQ{
private:
  int FRONT , REAR , Size;
  int *P_QUEUE;
public:
  PriorityQ(int);
  bool isFull();
  bool isEmpty();
  void Enqueue(int item);
  int Dequeue();
  ~PriorityQ();
};

PriorityQ::PriorityQ(int SIZE){
  Size = SIZE;
  FRONT = REAR = -1;
  P_QUEUE = new int[SIZE];
}

bool PriorityQ::isFull()
{
  if( FRONT == (REAR+1)%Size )
    return true;
  return false;
}

bool PriorityQ::isEmpty()
{
  if( REAR == -1 )
    return true;
  return false;
}


void PriorityQ::Enqueue(int item){
  if(isFull())
    std::cerr << "Queue is full\n";
  else{
    if(FRONT == -1 && REAR == -1)
      FRONT = REAR = 0;
    else{
      REAR = (REAR+1)%Size;
    }
    P_QUEUE[REAR] = item;
  }
}

int PriorityQ::Dequeue(){
  int item;
  if(isEmpty()){
    //std::cerr << "Queue is empty\n";
    throw std::runtime_error("Queue is empty\n");
  }
  else{
    int i, index;
    index = FRONT;
    int large = P_QUEUE[index];
    //finds the max element;
    for(i = index+1; i<= REAR; i++){
      if(large<P_QUEUE[i]){
        large = P_QUEUE[i];
        index = i;
      }
    }
    item = P_QUEUE[index];
    if(FRONT == REAR) {
      FRONT = REAR = -1;
    }
    else{
      for(int i = index; i< REAR; i++){
        P_QUEUE[i] = P_QUEUE[i+1];
      }
      REAR--;
    }
  }
  return item;
}

PriorityQ::~PriorityQ(){
  delete[] P_QUEUE;
}

int main()
{
  try{
    PriorityQ pq(5);
    pq.Enqueue(10);
    pq.Enqueue(20);
    pq.Enqueue(5);
    pq.Enqueue(15);

    std::cout << "Dequeued: " << pq.Dequeue() << "\n"; // Should dequeue 20
    std::cout << "Dequeued: " << pq.Dequeue() << "\n"; // Should dequeue 15

    pq.Enqueue(25);
    std::cout << "Dequeued: " << pq.Dequeue() << "\n"; // Should dequeue 25
    std::cout << "Dequeued: " << pq.Dequeue() << "\n"; // Should dequeue 10
    std::cout << "Dequeued: " << pq.Dequeue() << "\n"; // Should dequeue 5
    std::cout << "Dequeued: " << pq.Dequeue() << "\n"; // Should print queue empty message
  }catch(const std::runtime_error &e){
    std::cerr << e.what() << "\n";
  }
  return 0;
}

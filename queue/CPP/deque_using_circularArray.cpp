#include <iostream>

class Deque{
  int FRONT, REAR, Size;
  int *DEQUE;
public:
  Deque(int MaxSize);
  bool isFull();
  bool isEmpty();
  void Insert_Front(int item);
  void Insert_Rear(int item);
  int Delete_Front();
  int Delete_Rear();
  int Peek_Front();
  int Peek_Rear();
  void display();
  ~Deque(){delete []DEQUE}:
}

bool Deque::isFull(){
  if((REAR+1)%SIZE == FRONT)
    return true;
  else 
    return false;
}

bool Deque::isEmpty(){
  if(REAR==-1)
    return true;
  else 
    return false;
}

void Deque::Insert_Front(int item)
{
  if(isFull())
    std::cerr << "\nDeque OverFlow\n";
  else{
    if(REAR == -1){
      FRONT = REAR = 0;
    }else if(FRONT == 0){
      FRONT = Size - 1;
    }else{
      FRONT = FRONT - 1;
    }
    DEQUE[FRONT] = item;
  }
}

void Deque::Insert_Rear(int item)
{
  if(isFull())
    std::cerr << "\nDeque Overflow." << std::endl;
  else{
    if(REAR == -1){
      FRONT = REAR = 0;
    }else{
      REAR = (REAR + 1)%SIZE;
    }
    DEQUE[REAR] = item;
  }
}

int Deque::Delete_Front()
{
  int item;
  if(isEmpty()){
    std::cout << "\nDeque Underflow." << std::endl;
    return 0;
  }else{
    if(FRONT == REAR){
      item = DEQUE[FRONT];
      FRONT = REAR = -1;
    }else{
      item = DEQUE[FRONT];
      FRONT = (FRONT + 1)%Size;
    }
    return item;
  }
}

int Deque::Delete_Rear()
{
  int item;
  if(isEmpty()){
    std::cerr << "\nDeque Underflow" << std::endl;
    return 0;
  }else{
    if(FRONT == REAR){
      item = DEQUE[REAR];
      FRONT = REAR = -1;
    }else if(REAR == 0){
      item = DEQUE[REAR];
      REAR = Size - 1;
    }else{
      item = DEQUE[REAR];
      REAR = REAR - 1;
    }
    return item;
  }
}

#include <iostream>
#include <cstdlib>

#define MAX 5

class stack{
  private:
    int arr[MAX];
    int top;
  public:
    stack(){
      top = -1;
    }
    bool isEmpty(){
      return top==-1;
    }
    bool isFull(){
      return top==MAX-1;
    }
    void push(int n){
      if(isFull()){
        std::cerr<<"Stack overflow" << std::endl;
      }
      else {
        arr[++top] = n;
      }
    }
    int pop(){
      if(isEmpty()){
        std::cerr<<"Empty Stack" << std::endl;
        return 1;
      }
      else{
        return arr[top--];
      }
    }
    int peek(){
      if(isEmpty())std::cerr << "Empty stack " << std::endl;
      return arr[top];
    }
    void display()
    {
      std::cout << "Elements: \n";
      for (int i = 0; i < MAX; i++) {
        std::cout << arr[i] << std::endl;
      }
    }
};

int main (int argc, char *argv[]) {
  stack s;
  s.push(1);
  s.push(4);
  s.push(2);
  s.push(8);
  s.push(5);
  s.pop();
  s.peek();
  s.pop();
  s.pop();
  s.display();
  return 0;
}


#include <iostream>

void Hanoi(int n, char source, char dest, char aux)
{
  if(n==1){
    std::cout << "MOVE DISK" << n << " from " << source << " to " << dest << std::endl;
  }
  else{
    Hanoi(n-1, source, aux, dest);
    std::cout << "MOVE DISK " << n << " from " << source << " to " << dest << std::endl;
    Hanoi(n-1, aux, dest, source);
  }
}

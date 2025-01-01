#include <stdio.h>

int GCD(int a, int b)
{
  if(b==0)
    return a;
  return GCD(b, a%b);
}

int main(){
  int a = 18, b = 48;
  printf("GCD(%d, %d) = %d\n", a, b, GCD(a,b));
  return 0;
}

#include <iostream>

void selection_sort(int list[], int n){
  int i, j, smallest, temp;

  for(i = 0; i< n; i++){
    smallest = i;
    for(j=i+1; j<n;j++){
      if(list[j]< list[smallest]){
        smallest = j;
      }
    }
    temp = list[i];
    list[i] = list[smallest];
    list[smallest] = temp;
  }
}

int main()
{
  int arr[] = { 44, 77, 22, 66, 11, 00, 55, 44 };
  int n = sizeof(arr)/sizeof(arr[0]);

  selection_sort(arr, n);
  for(int i = 0; i<n; i++){
    std::cout << arr[i] << "  ";
  }
    std::cout << std::endl;
  return 0;
}

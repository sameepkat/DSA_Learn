#include <iostream>
#include <cstring>

int hash_ascii(char* s, int n){
  int len = strlen(s);
  int i, sum = 0;
  for(i = 0; i< len; i++){
    sum += s[i];
  }
  return sum%n;
}

int main(){
    char record[][10] = {"Rama", "Hari", "Muna","Gita", "Rita", "Joy","Shiya"};
  std::cout << "Search key\tIndex value at hash table\n";
  for(int i=0; i<7; i++){
    std::cout << record[i] << "\t\t\t" << hash_ascii(record[i], 7);
    std::cout << "\n";
  }
  return 0;
}

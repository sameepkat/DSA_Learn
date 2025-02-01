#include <stdio.h>

typedef enum{false, true} bool;

int hash_Table[5];
int col_flag[5] = {};

int hash_function(int key){
  return key%5;
}

int linear_probing(int hv){
  int i;
  for(i = hv+1; i<5 && i!=hv; i=(i+1)%5){
    if(col_flag[i] == 0){
      return i;
    }
  }
  return -1;
}

void insert(int key){
  int hv = hash_function(key);
  int new_hv;
  if(col_flag[hv]==0){
    hash_Table[hv] = key;
    col_flag[hv] = 1;
  }else{
    printf("Collision occured at %d! ", hv);
    new_hv = linear_probing(hv);
    if(new_hv != -1){
      hash_Table[new_hv] = key;
      col_flag[new_hv] = 1;
      printf("Then %d is placed at new slot %d using linear probing.\n", key, new_hv);
    }else{
      printf("Collision cannot be resolved.\n");
    }
  }
}

void search(int key){
  int hv = hash_function(key);
  int i;
  bool found_flag = false;
  if(hash_Table[hv] == key)
    printf("%d is found at %d.\n", key, hv);
  else{
    for(i=hv+1;i<5 && i!=hv; i=(i+1)%5){
      if(hash_Table[i] == key){
        printf("%d is found at %d.\n", key, i);
        found_flag = true;
      }
    }
    if(found_flag == false)
      printf("%d is not found!\n", key);
  }
}

void print_ht(){
  int i;
  printf("\nHash Value\t Key\n");
  for(i=0;i<5;i++){
    if(col_flag[i] == 1){
      printf("%d \t\t %d", i, hash_Table[i]);
      printf("\n");
    }
  }
}

int main()
{
  insert(11);
  insert(12);
  insert(22);
  insert(13);
  insert(32);

  search(32);
  search(44);

  print_ht();
  return 0;
}

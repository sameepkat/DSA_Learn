#include <stdio.h>

typedef enum{false, true} bool;

int hash_Table[10];
int col_flag[10] = {};
int col_count;

int hash_function(int key){
  return key%10;
}

int quad_probing(int key){
  int i;
  int hv = hash_function(key);
  i = hv;
  while(col_count < 10){
    i = (hash_function(key) + col_count*col_count)%10;
    if(col_flag[i] == 0){
      return i;
    }else{
      col_count ++;
    }
  }
  return -1;
}

void insert(int key){
  int hv = hash_function(key);
  int new_hv;
  if(col_flag[hv] == 0){
    hash_Table[hv] = key;
    col_flag[hv] = 1;
  }else{
    printf("Collision occured at %d! \n", hv);
    new_hv = quad_probing(key);
    printf("new hv = %d\n", new_hv);
    if(new_hv != -1){
      hash_Table[new_hv] = key;
      col_flag[new_hv] = 1;
      printf("Then %d is placed at new slot %d using quadratic probing.\n", key, new_hv);
    }else{
      printf("Collision cannot be resolved.\n");
    }
  }
}

void search(int key){
  int i;
  int count = 0;
  bool found_flag = false;
  int hv = hash_function(key);
  if(hash_Table[hv] == key){
    printf("%d is found at %d.\n", key, hv);
    found_flag = true;
  }else{
    count++;
    i = hv;
    while(count < 10){
      i = (hash_function(key) + count*count) %10;
      if(hash_Table[i] == key){
        printf("%d is found at %d.\n", key, i);
        found_flag = true;
        return;
      }else{
        count++;
      }
    }
    if(found_flag == false){
      printf("%d is not found!\n", key);
    }
  }
}

void print_ht(){
  int i;
  printf("\nHash Value\t Key\n");
  for(i=0; i<10; i++){
    if(col_flag[i] == 1){
      printf("%d\t\t %d", i, hash_Table[i]);
      printf("\n");
    }
  }
}

int main()
{
  insert(11);
  insert(21);
  insert(61);
  insert(74);
  insert(91);

  search(11);
  search(61);
  search(74);
  search(91);
  search(67);

  print_ht();

  return 0;
}

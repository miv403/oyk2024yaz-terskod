#include <stdio.h>
#include <stdlib.h>


int main() {

  int *arr;
  arr = malloc(sizeof(int) * 10);
  int i = 0;

  arr[0] = 10;
  arr[1] = 11;
  arr[2] = 12;
  arr[3] = 13;
  arr[4] = 14;
  arr[5] = 15;
  arr[6] = 16;
  arr[7] = 17;
  arr[8] = 18;
  arr[9] = 19;

  printf("Array 0. deger: %d\n",arr[0]);
  printf("Array 5. deger: %d\n",arr[4]);
  printf("Array 10. deger: %d\n",arr[9]);

  for(i = 0; i < 10; i++) {
    printf("Array %d. deger: %d\n",i,arr[i]);
  }
}
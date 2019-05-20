#include <stdio.h>

void swap (int *x, int *y) {
  int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

void heap_sort(int array[], int size)
{
  int i, j;
  /* for(j=size;j>=0;j--){ */
  /* 	adjustment_heap(array, j, size, size); */
  /* } */
  /* swap(&array[0], &array[size]); */
  /* for(j=size-1;j>=0;j--){ */
  /* 	adjustment_heap(array, j, size - 1, size); */
  /* } */
  /* swap(&array[0], &array[size-1]); */
  /* for(j=size-2;j>=0;j--){ */
  /* 	adjustment_heap(array, j, size - 2, size); */
  /* } */
  /* swap(&array[0], &array[size-2]); */

  for(i=0;i<size;i++){
  	for(j=size-i-1;j>=0;j--){
  	  adjustment_heap(array, j, size-i, size);
  	}
  	swap(&array[0], &array[size-i]);
  }
}

void adjustment_heap(int array[], int n, int max, int size)
{
  int left = n * 2;
  int right = n * 2 + 1;
  if(n > size) { return; }
  if(left > size || left > max) { return; }
  if(array[n] < array[left]) { swap(&array[n], &array[left]); }
  if(right > size || right > max) { return; }
  if(array[n] < array[right]) { swap(&array[n], &array[right]); }
}


int main (void) {
  /* int array[11] = { 0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3 }; */
  int array[] = {1, 2, 9, 5, 2, 45, 7, 9};
  int i;

  printf("Before sort: ");
  for (i = 0; i < (int)(sizeof(array) / 4); i++) { printf("%d ", array[i]); }
  printf("\n");

  heap_sort(array, (int)(sizeof(array) / 4) - 1);

  printf("After sort: ");
  for (i = 0; i < (int)(sizeof(array) / 4); i++) { printf("%d ", array[i]); }
  printf("\n");

  return 0;
}

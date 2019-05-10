#include <stdio.h>

void heap_sort(int*, int);
void pushdown(int*, int, int);
void swap(int*, int*);

int main()
{
  int i;
  int list[] = {1, 2, 9, 5, 2, 45, 7, 9};
  int len = (int)(sizeof(list) / 4);

  heap_sort(list, len - 1);

  for(i=0;i<len;i++)
	printf("%d,", list[i]);
  printf("\n");
}

void heap_sort(int* list, int size)
{
  int i;

  for(i = size/2;i >= 1;i--){
	pushdown(list, i, size);
  }

  for(i = size;i >= 2;i--){
	swap(&list[1], &list[i]);
	pushdown(list, 1, i-1);
  }
}

void pushdown(int *list, int first, int last)
{
  int parent = first;
  int child = 2*parent;

  while(child <= last){
	if((child < last) && (list[child] < list[child+1])){
	  child++;
	}
	if(list[child] <= list[parent]){ break; }
	swap(&list[child], &list[parent]);
	parent = child;
	child = 2 * parent;
  }
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

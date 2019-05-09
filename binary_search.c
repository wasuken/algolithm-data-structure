#include <stdio.h>
#include "./quicksort2.c"

int binary_search(int*, int, int);

int main()
{
  int list[] = {4, 8, 7, 6, 9, 3, 2, 1, 0};
  printf("%d\n", binary_search(list, 9, 9));
  printf("%d\n", binary_search(list, 10, 9));
  printf("%d\n", binary_search(list, 4, 9));
  printf("%d\n", binary_search(list, 0, 9));
}

int binary_search(int *list, int value, int size)
{
  int i, begin, end, middle;
  begin = 0;
  end = size;
  quicksort(list, 0, end);
  for(i = 0;begin < end;i++){
	middle = (int)((begin + end) / 2);
	if(value == list[middle])
	  return value;
	else if(list[middle] < value)
	  begin = middle + 1;
	else if(list[middle] >= value)
	  end = middle;
  }
  return -1;
}

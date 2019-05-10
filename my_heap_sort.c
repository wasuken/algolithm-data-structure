#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *list, int size);

int main()
{
  int i, len;
  int list[] = {6, 3, 2, 4, 5, 6, 7, 9, 0, 5, 99, 2, 3, 4, 93, 4, 192};
  len = (int)(sizeof(list) / sizeof(int));
  for(i=0;i<len;i++)
	printf("%d,", list[i]);
  printf("\n");
  heap_sort(list, len);
}

void heap_sort(int *list, int size)
{

}

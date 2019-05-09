#include <stdio.h>

void quicksort(int*, int, int);
void swap(int*, int*);
int partision(int*, int, int);

/* int main() */
/* { */
/*   int list[] = {4, 8, 7, 6, 9, 3, 2, 1, 0}; */
/*   int len = (int)(sizeof list / 4); */
/*   int i; */
/*   for(i=0;i<len;i++) */
/* 	printf("%d,", list[i]); */
/*   printf("\n"); */
/*   quicksort(list, 0, len); */

/*   for(i=0;i<len;i++) */
/* 	printf("%d,", list[i]); */
/*   printf("\n"); */
/* } */

void quicksort(int *list, int begin, int end)
{
  if(begin >= end)
	return;

  int piv = partision(list, begin, end);
  quicksort(list, begin, piv - 1);
  quicksort(list, piv + 1, end);
}

int partision(int *list, int begin, int end)
{
  int i, j, piv;
  piv = begin;
  i = 0;
  j = end + 1;
  do{
	do{
	  i++;
	}while(list[i] < list[piv]);
	do{
	  j--;
	}while(list[piv] < list[j]);
	if(i < j) swap(&list[i], &list[j]);
  }while(i < j);
  swap(&list[piv], &list[j]);
  return j;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

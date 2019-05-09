#include <stdio.h>

#define MAX_SIZE 10000
int b[MAX_SIZE];

void merge_sort(int*, int, int);

int main()
{
  int i, len;
  int list[] = {6, 3, 2, 4, 5, 6, 7, 9, 0, 5, 99, 2, 3, 4, 93, 4, 192};
  len = (int)(sizeof(list) / sizeof(int));
  for(i=0;i<len;i++)
	printf("%d,", list[i]);
  printf("\n");
  merge_sort(list, 0, len);
  for(i=0;i<len;i++)
	printf("%d,", list[i]);
  printf("\n");
}
void merge_sort(int *list, int left, int right)
{
  if(left >= right)
	return;

  int mid = (right + left) / 2;
  int i, j, k;
  merge_sort(list, left, mid);
  merge_sort(list, mid + 1, right);

  for(i=mid;i>=left;i--)
	b[i] = list[i];

  for(i=mid+1;i<=right;i++)
	b[right-(i-(mid+1))] = list[i];

  j = left;
  k = right;
  for(i=left;i<=right;i++)
	if(b[j] <= b[k])
	  list[i] = b[j++];
	else
	  list[i] = b[k--];
}

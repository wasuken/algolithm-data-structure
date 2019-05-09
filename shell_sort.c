#include <stdio.h>

void shell_sort(int*, int);

int main()
{
  int list[] = {8,5,3,7,8,9,5,2};
  int i;
  shell_sort(list, 8);
  for(i = 0;i<8;i++)
	printf("%d,", list[i]);
  printf("\n");
}

void shell_sort(int *list, int n)
{
  int h, i, j, t;
  for(h = 1;h < n/9;h = h * 3 + 1)
	;
  for(;h > 0; h /= 3){
	for(i = h; i < n; i++){
	  j = i;
	  while(j >= h && list[j-h] > list[j]){
		printf("h:%d,i:%d,j:%d,t:%d\n", h, i, j, t);
		t = list[j]; list[j] = list[j-h]; list[j-h] = t;
		j -= h;
	  }
	}
  }
}

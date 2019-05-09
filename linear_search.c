#include <stdio.h>

int search(int, int[]);

int main()
{
  int list[] = {1,8,3,7,3,4,8,4,8,3};
  printf("%d\n", search(13, list));

}

int search(int key, int list[])
{
  int i;

  int n = (sizeof list / sizeof list[0]);
  for(i = 0;i < n;i++){
	if(list[i] == key){
	  return key;
	}
  }
  return -1;
}

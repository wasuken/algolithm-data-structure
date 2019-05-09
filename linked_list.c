#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node *next;
};

int main()
{
  struct Node *node;
  if((node = malloc(sizeof(struct Node))) == NULL){
	printf("メモリが足りません。\n");
  }
  node->value = 1;
  printf("%d\n", node->value);
}

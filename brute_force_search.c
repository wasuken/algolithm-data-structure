#include <stdio.h>

int brute_force_search(char*, int, char*, int);

int main()
{
  char text[] = "hello world!";
  char pattern[] = "ello";
  printf("%d\n", brute_force_search(text, 12, pattern, 4));

}

int brute_force_search(char *text, int text_len, char *pattern, int pat_len)
{
  int i, j;

  i = 0, j = 0;

  while(i < text_len && j < pat_len){
	if(text[i] == pattern[j]){
	  i++; j++;
	}else{
	  i = i - j + 1; j = 0;
	}
  }
  return (j == pat_len) ? (i - j) : -1;
}

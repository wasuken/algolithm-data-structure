#include <stdio.h>

#define MAX_ELEMENTS 10000
int b[MAX_ELEMENTS];

void merge_sort(int*, int, int);

int main()
{
  int i;
  int list[] = {6, 3, 2, 4, 5, 6, 7, 9, 0, 5, 99, 2, 3, 4, 93, 4, 192};
  for(i=0;i<10;i++)
	printf("%d,", list[i]);
  printf("\n");
  merge_sort(list, 0, 10);
  for(i=0;i<10;i++)
	printf("%d,", list[i]);
  printf("\n");
}

/* マージソート */
void merge_sort (int array[], int left, int right) {
  int i, j, k, mid;
  int work[100];  // 作業用配列
  if (left < right) {
    mid = (left + right)/2; // 真ん中
    merge_sort(array, left, mid);  // 左を整列
    merge_sort(array, mid+1, right);  // 右を整列
    for (i = mid; i >= left; i--) { work[i] = array[i]; } // 左半分
    for (j = mid+1; j <= right; j++) {
      work[right-(j-(mid+1))] = array[j]; // 右半分を逆順
    }
    i = left; j = right;
    for (k = left; k <= right; k++) {
      if (work[i] < work[j]) { array[k] = work[i++]; }
      else                   { array[k] = work[j--]; }
    }
  }
}

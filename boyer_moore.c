#include <stdio.h>

#define uchar unsigned char
#define max(a, b) ((a) > (b) ? a : b)

int bm_search(uchar*, int, uchar*, int);

int main()
{
  uchar text[] = "hello world!";
  uchar pattern[] = "ello";
  printf("%d\n", bm_search(text, 12, pattern, 4));
}


int bm_search(uchar *text, int text_len, uchar *pattern, int pat_len)
{
  /* テキストとパターンの不一致が見つかった時に、どれだけずらすかを示す表 */
  int skip[256];

  /* 変数iは注目しているテキストの位置、変数jは注目しているパターンの位置を表すポインタ */
  int i, j;

  /* 表skipを作成する */
  for(i = 0;i<256;i++)
	skip[i] = pat_len;
  for(i = 0;i<pat_len - 1;i++)
	skip[pattern[i]] = pat_len - i - 1;

  /* ポインタを初期化する。パターンを後ろから前に向かって比較するので、パターンのながさ−1に初期化する */
  i = pat_len - 1;

  /* テキストの最後尾に行き当たるまで繰り返す */
  while(i < text_len){
	/* ポインタjをパターンの最後の文字をさすようにする */
	j = pat_len - 1;

	/* テキストとパターンの最後の文字をさすようにする */
	while(text[i] == pattern[j]){

	  /* 最初の文字まで一致したら、探索は成功である */
	  if(j == 0){
		return i;
	  }

	  /* ポインタiとjをそれぞれ１文字分戻す */
	  i--; j--;
	}

	/* 一致しなかったので、パターンをずらす */
	i = i + max(skip[text[i]], pat_len - j);
  }
  /* 結局見つからなかった */
  return -1;
}

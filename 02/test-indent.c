/* test0.c */
#include <stdio.h>
/*
* このファイルを改変し，インデントを正しくすること
*/
int test(int i, int j) {
  return (i * j);
}

int main(int argc, char *argv) {
  int i, j;
  int k;
  i = 3;
  j = 2;
  k = test(i, j);
  if (k > 5)
    printf(">5\n";
  else
  printf("<=5\n");
  return 0;
}

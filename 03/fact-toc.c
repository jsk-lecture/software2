#include <stdio.h>
#include <stdlib.h>

int fact(int product, int counter, int max_counter) {
  if (counter > max_counter) {
    return product;
  }else{
    return fact(counter * product, counter + 1, max_counter);
  }
}

int main (int argc, char *argv[]) {
  int x, ret;
  x = atoi(argv[1]);
  ret = fact(1, 1, x);
  printf("ret = %d\n", ret);
}

#include <stdio.h>

// (define (p) (p))
void p(void) {
  fprintf(stderr, "p()\n");
  p();
}

// (define (test x y) (if (= x 0) 0 y))
void test (int x, void (*p)(void)) {
  if ( x == 0 ) {
    fprintf(stderr, "0\n");
  } else {
    (*p)();
  }
}

//(print (test 0 (p)))
int main() {
  test(0, p);
  return 0;
}

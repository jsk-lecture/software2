#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int fib(int n) {
  if ( n == 0 ) {
    return 0;
  } else if ( n == 1 ) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  printf("call fib(%d)\n", n);
  int r = fib(n);
  printf(" --> %d\n", r);

  struct rusage r_usage;
  getrusage(RUSAGE_SELF, &r_usage);
  printf("memory usage = %ld\n", r_usage.ru_maxrss);
}

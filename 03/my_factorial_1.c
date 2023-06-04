#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/resource.h>

int my_factorial_1(int n) {
  if ( n == 1 ) {
    return 1;
  } else {
    return n * my_factorial_1 (n - 1);
  }
}

int main(int argc, char **argv) {
  int n = atoi(argv[1]);

  int ret = my_factorial_1(n);
  printf("%d\n", ret);

  printf("INT_MAX %d(%ld), LONG_MAX %ld(%ld), LLONG_MAX %lld(%ld)\n",
         INT_MAX, sizeof(int), LONG_MAX, sizeof(long), LLONG_MAX, sizeof(long long));
  struct rusage r_usage;
  getrusage(RUSAGE_SELF, &r_usage);
  printf("memory usage = %ld\n", r_usage.ru_maxrss);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/resource.h>

int my_factorial_2(int product, int counter, int max_count) {
  if ( counter > max_count ) {
    return product;
  } else {
    return my_factorial_2(counter * product,
                          counter + 1,
                          max_count);
  }
}

int main(int argc, char **argv) {
  int n = atoi(argv[1]);

  int ret = my_factorial_2(1, 1, n);
  printf("%d\n", ret);

  printf("INT_MAX %d(%ld), LONG_MAX %ld(%ld), LLONG_MAX %lld(%ld)\n",
         INT_MAX, sizeof(int), LONG_MAX, sizeof(long), LLONG_MAX, sizeof(long long));
  struct rusage r_usage;
  getrusage(RUSAGE_SELF, &r_usage);
  printf("memory usage = %ld\n", r_usage.ru_maxrss);
}

#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/resource.h>

#include <iostream>
#include <iomanip>
#include <gmpxx.h>

mpz_class my_factorial_2(mpz_class product, mpz_class counter, mpz_class max_count) {
  if ( counter > max_count ) {
    return product;
  } else {
    return my_factorial_2(counter * product,
                          counter + 1,
                          max_count);
  }
}

int main (int argc, char *argv[]) {
  mpz_class n, ret;

  n = atoi(argv[1]);
  ret = my_factorial_2(1, 1, n);
  std::cerr << "ret = " << ret << std::endl;

  printf("INT_MAX %d(%ld), LONG_MAX %ld(%ld), LLONG_MAX %lld(%ld)\n",
         INT_MAX, sizeof(int), LONG_MAX, sizeof(long), LLONG_MAX, sizeof(long long));
  struct rusage r_usage;
  getrusage(RUSAGE_SELF, &r_usage);
  printf("memory usage = %ld\n", r_usage.ru_maxrss);
}

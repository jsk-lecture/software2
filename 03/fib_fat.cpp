#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

#include <iostream>
#include <vector>
#define SIZE 100000


std::vector<int> fib(std::vector<int> n) {
  if ( n[0] == 0 ) {
    return []{std::vector<int> tmp(SIZE, 0); return tmp;}();
  } else if ( n[0] == 1 ) {
    return []{std::vector<int> tmp(SIZE, 1); return tmp;}();
  } else {
    //return fib(n[0] - 1) + fib(n[0] - 2);
    return std::vector<int> (SIZE, fib([n]{std::vector<int> tmp(SIZE, n[0]-1); return tmp;}())[0] + fib([n]{std::vector<int> tmp(SIZE, n[0]-2); return tmp;}())[0]);
    //return [n]{std::vector<int> tmp(SIZE, n[0]); return tmp;}();
  }
}

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  printf("call fib(%d)\n", n);
  auto r = fib([n]{std::vector<int> tmp(SIZE, n); return tmp;}());
  printf(" --> %d\n", r[0]);

  struct rusage r_usage;
  getrusage(RUSAGE_SELF, &r_usage);
  printf("memory usage = %ld\n", r_usage.ru_maxrss);
}

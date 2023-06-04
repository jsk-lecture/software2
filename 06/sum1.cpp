#include <iostream>

auto sum(auto term, auto a, auto next, auto b) {
  if ( a > b ) {
    return 0;
  } else {
    return term(a) + sum(term, next(a), next, b);
  }
}

int inc(int n) { return n + 1; }
int identity(int x) { return x; }
int sum_integers(int a, int b) {
  return sum(identity, a, inc, b);
}

int cube(int x) { return x * x * x; }
int sum_cubes(int a, int b) {
  return sum(cube, a, inc, b);
}

int main() {
  std::cout << "sum_integers(1, 10): " << sum_integers(1, 10) << std::endl;
  std::cout << "sum_cubes(1, 10): " << sum_cubes(1, 10) << std::endl;
}


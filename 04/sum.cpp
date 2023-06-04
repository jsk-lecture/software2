// https://gcc.gnu.org/projects/cxx-status.html
#include <iostream>

#define dx 0.00001

double cube(double x) { return x * x * x; }

auto deriv(auto g){
  return [&, g](auto x) { return ((g(x + dx) - g(x)) / dx); };
}

int main() {
  auto four = [](auto x) { return x + 4; };
  printf("lambda x : x + 4 = %d, %d\n", four(1), [](auto x) { return x + 4; }(1));

  printf("deriv(cube)(5) = %f\n", (deriv(cube))(5.0));
}

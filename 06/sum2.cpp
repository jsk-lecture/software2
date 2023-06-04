#include <iostream>

auto sum(auto term, auto a, auto next, auto b) {
  if ( a > b ) {
    return 0.0; // THIS IS VERY IMPORTANT
  } else {
    return term(a) + sum(term, next(a), next, b);
  }
}

//double pi_term(double x) {return 1.0 / (x * (x + 2.0));}
//double pi_next(double x) {return x + 4;}
double pi_sum(int a, int b) {
  return sum([](auto x){return 1.0 / (x * (x + 2.0));},
             (double)a,
             [](auto x){return x + 4.0;},
             (double)b);
}

int main() {
  std::cout << "8 * pi_sum(1, 10000): " << 8 * pi_sum(1, 100000) << std::endl;
}

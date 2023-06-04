#include <iostream>
#include <gmpxx.h>

int main (int argc, char *argv[]) {
  mpf_set_default_prec(1024);
  mpf_class a, b, c;

  a = 1;
  b = -100000;
  c = 1;

  //mpf_t bb, mb, ac, b2ac, a2, x1, x2;
  mpf_class x1, x2;
  x1 = ( - b - sqrt ( b * b - 4 * a * c )) / ( 2 * a );
  x2 = ( - b + sqrt ( b * b - 4 * a * c )) / ( 2 * a );

  std::cerr << "a  = " << a << std::endl;
  std::cerr << "b  = " << b << std::endl;
  std::cerr << "c  = " << c << std::endl;
  std::cerr << "x1 = " << x1 << std::endl;
  std::cerr << "x2 = " << x2 << std::endl;

  mpf_class e1, e2;
  e1 = a * x1 * x1 + b * x1 + c;
  e2 = a * x2 * x2 + b * x2 + c;
  std::cerr << "e1 = " << e1 << std::endl;
  std::cerr << "e2 = " << e2 << std::endl;
}

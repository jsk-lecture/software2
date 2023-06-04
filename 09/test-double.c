#include <math.h>
#include <stdio.h>

#define sign(x) (x/(fabs (x)))

int main () {
  double a = 1.0, b = -100000.0, c = 1.0;

  double x1 = (- b - sqrt(b*b - 4*a*c))/2*a;
  double x2 = (- b + sqrt(b*b - 4*a*c))/2*a;

  printf("a  = %27.20e\n", a);
  printf("b  = %27.20e\n", b);
  printf("c  = %27.20e\n", c);
  printf("x1 = %27.20e\n", x1);
  printf("x2 = %27.20e\n", x2);
  printf("e1   %27.20e\n", a * x1 * x1 + b * x1 + c);
  printf("e2   %27.20e\n", a * x2 * x2 + b * x2 + c);


  double x1_ = (- b - sign(b)*sqrt(b*b - 4*a*c))/2*a;
  double x2_ = c / (a * x1_);
  printf("x1'= %27.20e\n", x1_);
  printf("x2'= %27.20e\n", x2_);

  printf("e1'  %27.20e\n", a * x1_ * x1_ + b * x1_ + c);
  printf("e2'  %27.20e\n", a * x2_ * x2_ + b * x2_ + c);
}

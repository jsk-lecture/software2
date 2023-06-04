//  gcc test-gmp.c -lgmp; ./a.out
#include <stdio.h>
#include <math.h>
#include <gmp.h>

#define sign(x) (x/(fabs (x)))

int main () {
  unsigned long int prec;
  mpf_t a, b, c;
  prec = 64;
  mpf_init2(a, prec);
  mpf_init2(b, prec);
  mpf_init2(c, prec);

  mpf_set_d(a,1);
  mpf_set_d(b,-100000);
  mpf_set_d(c,1);

  mpf_t bb, mb, ac, b2ac, a2, x1, x2;
  mpf_init2(bb, prec);
  mpf_init2(mb, prec);
  mpf_init2(ac, prec);
  mpf_init2(b2ac, prec);
  mpf_init2(a2, prec);
  mpf_init2(x1, prec);
  mpf_init2(x2, prec);
  mpf_mul(bb, b, b);
  mpf_mul(ac, a, c);
  mpf_mul_ui(ac, ac, 4);
  mpf_mul_ui(a2,  a, 2);
  mpf_sub(b2ac, bb, ac);
  mpf_sqrt(b2ac, b2ac);
  mpf_neg(mb, b);
  mpf_sub(x1, mb, b2ac);
  mpf_add(x2, mb, b2ac);
  mpf_div(x1, x1, a2);
  mpf_div(x2, x2, a2);

  printf("a :");
  mpf_out_str(stdout, 10, 10, a);
  printf("\n");
  printf("b :");
  mpf_out_str(stdout, 10, 10, b);
  printf("\n");
  printf("c :");
  mpf_out_str(stdout, 10, 10, c);
  printf("\n");
  printf("x1:");
  mpf_out_str(stdout, 10, prec, x1);
  printf("\n");
  printf("x2:");
  mpf_out_str(stdout, 10, prec, x2);
  printf("\n");

  mpf_t r, axx, bx;
  mpf_init2(r, prec);
  mpf_init2(axx, prec);
  mpf_init2(bx, prec);
  mpf_mul(axx, a, x1);
  mpf_mul(axx, axx, x1);
  mpf_mul(bx, b, x1);
  mpf_add(r, axx, bx);
  mpf_add(r, r, c);
  printf("e1:");
  mpf_out_str(stdout, 10, prec, r);
  printf("\n");

  mpf_mul(axx, a, x2);
  mpf_mul(axx, axx, x2);
  mpf_mul(bx, b, x2);
  mpf_add(r, axx, bx);
  mpf_add(r, r, c);
  printf("e2:");
  mpf_out_str(stdout, 10, prec, r);
  printf("\n");
}

#include <stdio.h>

void sub(float f)
{
  union {
    float f;
    unsigned int i;
  } x;
  unsigned char *p; unsigned int *l;
  int i;            unsigned int g;
  p = (unsigned char *)&f;
  l = (unsigned int *)&f;
  x.f = f;
  g=x.i;
  printf(" %-12g : % ", f, *l);
  for ( i = 0; i < sizeof(float); i++) {
    printf("%02x", *p++);
  }
  printf(" : ");
  for ( i = 0; i < 32; i++ ) {
    printf("%c", ((0x80000000)&g)?'1':'0');
    if ( (i == 0) || (i == 8) ) printf(" ");
    g = g<<1;
  }
  printf("\n");
}

int main () {
  float e = 1, w, a=0.6, b=a+a+a;
  int i = 0;
  do {
    i++; e /= 2; w = 1+e;
    printf("%2d:", i); sub(e);
    printf("  w"); sub(w);
  } while ( w > 1 );

  if ( b == 1.8f )
    printf("same\n");
  else
    printf("diff\n");

  sub (a);
  sub (0.6f);
  sub (b);
  sub (1.8f);

  printf("%.28f\n", a);
  printf("%.28f\n", 0.6f);
  printf("%.28f\n", b);
  printf("%.28f\n", 1.8f);
  return 0;
}

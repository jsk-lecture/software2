/* test-minus.c */
#include <stdio.h>

int print_bit (unsigned char s) {
  int i;
  printf("0x%02x : ", s);
  for (i = 0; i < 8; i++) {
    printf("%c", ((0x80)&s)?'1':'0');
    s = s << 1;
  }
  printf("\n");
}

int main (int argc, char* argv[]) {
  int i;
  unsigned char u1, u2, u3;
  u1 = 36;
  printf("u1 = "); print_bit(u1);
  printf("u1 = %d\n", u1);
  // 2's complement
  u2 = (0xff ^ u1) + 0x01;
  printf("u2 = "); print_bit(u2);
  printf("u2 = %d\n", u2);
  printf("u2 = %d\n", (char)u2);
  u3 = u1 + u2;
  printf("u3 = ");  print_bit(u3);
}

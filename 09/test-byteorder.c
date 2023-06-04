// test-byteorder.c
#include <stdio.h>

int print_byte (unsigned int s) {
  int i;
  unsigned char *p;
  p = (unsigned char*)&s;
  for (i=0;i<sizeof(unsigned int);i++) {
    printf("%02x", *p);
    p++;
  }
  printf("\n");
}

int main (int argc, char* argv[]) {
  unsigned int u1; // 32bit, 4byte

  u1 = 0x1234abcd;
  printf("u1 = %x : ", u1);
  print_byte(u1);
}

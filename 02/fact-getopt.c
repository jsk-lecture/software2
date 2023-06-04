#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FALSE 0
#define TRUE 1

int Debug = FALSE;

// -d を付けて実行した際にのみ，以下のデバッグメッセージが表示されるようにせよ．
int fact (int x) {
  if (x > 0) {
    if ( Debug ) {
      printf("x = %d\n", x);
    }
    return ( x * fact (x - 1) );
  } else {
    if ( Debug ) {
      printf("x = %d, return 1\n", x);
    }
    return 1;
  }
}

int main (int argc, char *argv[]) {
  int c, x, ret;
  // https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html
  // を参考に ./fact-getopt -d 10 とした際にDebug変数がTRUEと成るようにしてみよ．
  x = atoi(argv[optind]);
  ret = fact(x);
  printf("ret = %d\n", ret);
}

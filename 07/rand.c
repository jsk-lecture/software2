#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
man -k rand
man -s 3 rand

DESCRIPTION
       The  rand() function returns a pseudo-random integer in the range 0 to RAND_MAX inclusive (i.e., the
       mathematical range [0, RAND_MAX]).

       The srand() function sets its argument as the seed for a new sequence of pseudo-random  integers  to
       be returned by rand().  These sequences are repeatable by calling srand() with the same seed value.
*/

int main()
{
  //srand((unsigned int)time(NULL));
  for (int i = 0; i < 10; i++) {
    fprintf(stdout, "%d ", rand()%10);
  }
  fprintf(stdout, "\n");
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void output_rand(int length, char *fileName) {
  FILE *fo;
  int i;

  if ((fo = fopen(fileName, "w"))==NULL){
    exit(1);
  }

  srand(time(NULL));
  for(i=0;i<length;i++){
    fprintf(fo, "%d\n", rand()%1000);
  }
  fclose(fo);
}

int main(int argc, char *argv[]){
  int c, length = 100;
  char *fname = "rand.txt";

  while ((c = getopt(argc, argv, "n:o:")) != -1) {
    switch (c) {
    case 'n':
      length = atoi(optarg);
      break;
    case 'o':
      fname = optarg;
    }
  }

  fprintf(stderr, "writing data with %d length to %s\n", length, fname);
  output_rand(length, fname);
  return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *read_array(char *fname, int *num, int *len)
{
  FILE *fo;
  int i;
  char str[256];

  if ((fo = fopen(fname, "r")) == NULL){
    printf("can not open input file");
    exit(1);
  }

  *len = 0; while (fgets(str, 256, fo) != NULL) { (*len)++; }
  num = (int *)malloc(sizeof(int)*(*len));
  
  fseek(fo, 0, SEEK_SET);

  i = 0;
  while(fgets(str, 256, fo)!=NULL){
    num[i] = atoi(str);
    i++;
  }
  return num;
}

void print_array(int num[], int length) {
  int i;
  for (i=0; i < length; i++){
    fprintf(stdout, "%d, ", num[i]);
  }
  fprintf(stdout, "\n");
}


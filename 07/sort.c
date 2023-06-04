#include <stdio.h>
#include <stdlib.h>

int *read_array(char *fname, int *num, int *len);
void print_array(int num[], int length);

void selection_sort(int *num, int length) {
  int i, n, tmp;
  int min, min_pos;
  for(i = 0; i < length - 1; i ++) {
    printf("selectoin sort i = %d : ", i);
    print_array(num, length); // debug

    min = num[i];
    min_pos = i;
    for ( n = i + 1; n < length; n++) {
      if ( num[n] < min ) {
        min = num[n];
        min_pos = n;
      }
    }
    tmp = num[i];
    num[i] = min;
    num[min_pos] = tmp;
  }
}

void bubble_sort(int *num, int length) {
  int i, n, tmp;

  for(i = 0; i < length - 1; i ++) {
    printf("bubble sort i = %d : ", i);
    print_array(num, length); // debug

    for (n = length - 1; n > i; n--)
      if (num[n] < num[n-1]) {
        tmp = num[n];
        num[n] = num[n-1];
        num[n-1] = tmp;
      }
  }
}

void heap_add(int *num, int length, int c)
{
  int p, tmp;
  while (1) {
    p = (c-1)/2; // 親のインデックスを計算
    if (c < 0)
      break;
    // 親の方が小さい場合はbreak
    if (num[p] <= num[c])
      break;
    tmp=num[p];num[p]=num[c];num[c]=tmp;
    c = p; //親ノードを新たな子ノードにする
  }
}

void heap_del(int *num, int length, int p)
{
  int c, tmp;
  while (1) {
    c = p*2+1; // 子のインデックスを計算
    if (c >= length)
      break;
    if (c+1 < length && num[c+1] <= num[c] )
      c = c+1;
    // 親の方が小さい場合はbreak
    if (num[p] <= num[c])
      break;
    tmp=num[p];num[p]=num[c];num[c]=tmp;
    p = c; //子ノードを新たな親ノードにする
  }
}

void heap_sort(int *num, int length)
{
  int tmp, i;
  //最初のヒープを作る
  for (i = 1; i < length; i++ ){
    heap_add(num, length, i);
    printf("heap sort i = %d : ", i);
    print_array(num, i+1); // debug
  }
  //ヒープから最小値を抜き配列の後ろからつめていく
  for (i = 0; i < length; i++) {
    tmp = num[length-1-i];
    num[length-1-i] = num[0];
    num[0] = tmp;
    heap_del(num, length-1-i, 0);
    printf("heap sort i = %d : ", i);
    print_array(num, length-i); // debug
  }
  //逆順にする
  for (i = 0; i < length/2; i++){
    tmp = num[i];
    num[i] = num[length-i-1];
    num[length-i-1] = tmp;
  }
}

void merge(int *num, int left, int right, int size)
{
  int *tmp, h, i, j, k, l;
  tmp = malloc((left + size) * sizeof(int));
  i = left;
  j = right;
  k = left;
  l = left + size;
  while (( i < right ) && (j < l)) {
    if (num[i] < num[j]) {
      tmp[k] = num[i];
      i++;
    }else {
      tmp[k] = num[j];
      j++;
    }
    k++;
  }
  if ( i < right ) {
    for(h = i; h < right; h++) {
      tmp[k] = num[h];
      k++;
    }
  }
  if ( j < l ) {
    for(h = j; h < l; h++) {
      tmp[k] = num[h];
      k++;
    }
  }
  for(h = left; h < l; h++){
    num[h] = tmp[h];
  }
  free(tmp);
}

void merge_sort(int *num, int left, int right) {
  int middle;
  printf("merge sort i = %d, j = %d : ", left, right);
  for(int k = 0; k < left; k ++) printf("     ");
  print_array(num+left, right-left+1); // debug
  if (left < right) {
    middle = (right + left)/2;
    merge_sort(num, left, middle);
    merge_sort(num, middle+1, right);
    merge(num, left, middle + 1, right - left + 1);
  }
}

void quick_sort (int *num, int first, int last) {
  int i, j, x, t;

  x = (num[first] + num[last]) / 2;
  i = first;
  j = last;
  while (1) {
    printf("quick sort i = %d, j = %d : ", i, j);
    for(int k = 0; k < i; k ++) printf("     ");
    print_array(num+i, j-i+1); // debug
    while (num[i] < x)
      i++;
    while (x < num[j])
      j--;
    if (i >= j)
      break;
    t = num[i];
    num[i] = num[j];
    num[j] = t;
    i++;
    j--;
  }
  if (first < i - 1)
    quick_sort (num, first, i - 1);
  if (j + 1 < last)
    quick_sort (num, j + 1, last);
}

/* */

int main(int argc, char *argv[]) {
  int length, *num;
  char *fname = "rand.txt";

  /* selection sort */
  printf("reading from %s\n", fname);
  num = read_array(fname, num, &length);
  print_array(num, length);
  selection_sort(num, length);
  print_array(num, length);
  free(num);

  /* bubble sort */
  printf("reading from %s\n", fname);
  num = read_array(fname, num, &length);
  print_array(num, length);
  bubble_sort(num, length);
  print_array(num, length);
  free(num);

  /* heap sort */
  printf("reading from %s\n", fname);
  num = read_array(fname, num, &length);
  print_array(num, length);
  heap_sort(num, length);
  print_array(num, length);
  free(num);

  /* merge sort */
  printf("reading from %s\n", fname);
  num = read_array(fname, num, &length);
  print_array(num, length);
  merge_sort(num, 0, length-1);
  print_array(num, length);
  free(num);

  /* quick sort */
  printf("reading from %s\n", fname);
  num = read_array(fname, num, &length);
  print_array(num, length);
  quick_sort(num, 0, length-1);
  print_array(num, length);
  free(num);

  return(0);
}

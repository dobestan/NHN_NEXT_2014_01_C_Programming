#include <stdio.h>

int get_2_exp(int);

int main() {
  int foo = 0;
  printf("N = ");
  scanf("%d", &foo);

  printf("2^N = %d\n", get_2_exp(foo));
  return 0;
}

int get_2_exp(int num) {
  if ( num == 0 ) return 1;
  return 2 * get_2_exp(num - 1);
}

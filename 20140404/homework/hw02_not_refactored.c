#include <stdio.h>

int getMaxNum(int, int, int);

int main() {
  int foo, bar, baz;
  printf("Enter 3 numbers : ");
  scanf("%d %d %d", &foo, &bar, &baz);

  printf("getMaxNum( %d , %d , %d) = %d\n", foo, bar, baz, getMaxNum(foo, bar, baz));
  return 0;
}

int getMaxNum(int foo, int bar, int baz) {
  int max = 0;
  max = ( foo > bar ) ? foo : bar;
  max = ( max > baz ) ? max : baz;
  return max;
}

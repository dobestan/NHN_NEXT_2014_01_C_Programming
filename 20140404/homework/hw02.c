#include <stdio.h>

int getMaxNum(int, int, int);
int getMinNum(int, int, int);

int main() {
  int foo, bar, baz;
  printf("Enter 3 numbers : ");
  scanf("%d %d %d", &foo, &bar, &baz);

  printf("getMaxNum( %d , %d , %d) = %d\n", foo, bar, baz, getMaxNum(foo, bar, baz));
  printf("getMinNum( %d , %d , %d) = %d\n", foo, bar, baz, getMinNum(foo, bar, baz));
  return 0;
}

int getMaxNum(int foo, int bar, int baz) { return ( ( ( foo > bar ) ? foo : bar ) > baz ) ? ( ( foo > bar ) ? foo : bar ) : baz; }
int getMinNum(int foo, int bar, int baz) { return ( ( ( foo < bar ) ? foo : bar ) < baz ) ? ( ( foo < bar ) ? foo : bar ) : baz; }

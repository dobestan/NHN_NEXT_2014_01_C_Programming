#include <stdio.h>

int get_GCD(int, int);

int main() {
  int foo, bar;
  printf("Enter two integer = ");
  scanf("%d %d", &foo, &bar);
  printf("GCD( %d , %d ) = %d\n", foo, bar, get_GCD(foo, bar));

  return 0;
}

int get_GCD(int foo, int bar) {
  if ( bar == 0 ) return foo;
  return get_GCD(bar, foo % bar);
}

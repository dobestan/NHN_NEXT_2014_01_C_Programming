#include <stdio.h>

int main() {
  int foo;
  float bar;
  double baz;
  char quz;

  printf("char : %d\n", sizeof(quz));
  printf("int : %d\n", sizeof(foo));
  printf("float : %d\n", sizeof(bar));
  printf("double : %d\n", sizeof(baz));
  return 0;
}

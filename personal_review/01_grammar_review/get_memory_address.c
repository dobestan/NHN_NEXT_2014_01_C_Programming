#include <stdio.h>

int main() {
  int foo;
  printf("value : %d (garbage value)\n", foo);
  printf("address : %p\n", &foo);

  return 0;
}

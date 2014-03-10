#include <stdio.h>

void swap(int, int);

int main() {
  int x =  5;
  int y = 10;

  printf("original pair : (%2d, %2d)\n", x, y);
  swap(x, y);
  printf("swapped pair : (%2d, %2d)\n", x, y);

  return 0;
}

void swap(int x, int y) {
  int temp;

  temp = x;
  x = y;
  y = temp;

  return;
}

#include <stdio.h>

void print_array(const int *);

int main() {
  int arr[3] = { 10, 20, 30 };
  print_array(arr);
  return 0;
}

void print_array(const int * arr) {
  printf("(1) value : %d\n", arr[0]);
  printf("(2) value : %d\n", arr[1]);
  printf("(3) value : %d\n", arr[2]);
}

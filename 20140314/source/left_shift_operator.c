#include <stdio.h>

int main() {
  int num = 15;

  int result_1 = num << 1;
  int result_2 = num << 2;
  int result_3 = num << 3;

  printf("result of 15 << 1 : %d\n", result_1); //30
  printf("result of 15 << 2 : %d\n", result_2); //60
  printf("result of 15 << 3 : %d\n", result_3); //120
  return 0;
}

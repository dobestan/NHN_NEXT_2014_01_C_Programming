#include <stdio.h>

int main() {
  int num = -16;

  int result_1 = num >> 1;
  int result_2 = num >> 2;
  int result_3 = num >> 3;

  printf("result of -16 >> 1 : %d\n", result_1); //-8
  printf("result of -16 >> 2 : %d\n", result_2); //-4
  printf("result of -16 >> 3 : %d\n", result_3); //-2
  return 0;
}


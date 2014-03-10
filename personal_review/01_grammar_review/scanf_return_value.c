#include <stdio.h>

int main() {
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;

  printf("Enter numbers(3) : ");
  int res = scanf("%d %d %d", &num1, &num2, &num3);
  printf("scanf return value : %d\n", res);
  printf("num1 = %d\n", num1);
  printf("num2 = %d\n", num2);
  printf("num3 = %d\n", num3);

  return 0;
}

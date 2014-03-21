#include <stdio.h>

// 9x9 table with while loop

int main() {
  int num1 = 1;
  int num2 = 1;

  while ( num1 < 10 ) {
    num2 = 1; // don't forget to initialize num2 value

    while ( num2 < 10 ) {
      printf("%d x %d = %d\n", num1, num2, num1 * num2);
      num2++;
    }

    printf("\n"); // new line character for pretty format
    num1++;
  }
  return 0;
}

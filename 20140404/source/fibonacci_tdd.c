#include <stdio.h>

int fibonacci(int num);
void fibonacci_test(int num, int expected);
void main_test(void);

int main() {
  main_test();

  return 0;
}

int fibonacci(int num) {
  if ( num == 0 ) return 1;
  if ( num == 1 ) return 1;
  return fibonacci(num-1) + fibonacci(num-2);
}

void fibonacci_test(int num, int expected) {
  char * msg = ( fibonacci(num) == expected ) ? "success" : "failed";
  printf("fib(%2d) should be (%3d) result is (%3d) : %s\n", num, expected, fibonacci(num), msg);
}

void main_test(void) {
  printf("---Test Start---\n");
  fibonacci_test(0, 1);
  fibonacci_test(1, 1);
  fibonacci_test(2, 2);
  fibonacci_test(3, 3);
  fibonacci_test(4, 5);
  fibonacci_test(5, 8);
  fibonacci_test(6, 13);
  fibonacci_test(7, 21);
  printf("---Test End---\n");
}

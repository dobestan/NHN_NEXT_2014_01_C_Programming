#include <stdio.h>

int fibonacci(int);

int main() {
  for ( int i = 0 ; i < 11 ; i++ ) printf("fibonacci(%d) = %d\n", i, fibonacci(i));
  return 0;
}

int fibonacci(int num) {
  if ( num == 0 ) return 0;
  if ( num == 1 ) return 1;
  return fibonacci( num - 1 ) + fibonacci( num - 2 );
}

/* ---출력 결과---
 * fibonacci(0) = 0
 * fibonacci(1) = 1
 * fibonacci(2) = 1
 * fibonacci(3) = 2
 * fibonacci(4) = 3
 * fibonacci(5) = 5
 * fibonacci(6) = 8
 * fibonacci(7) = 13
 * fibonacci(8) = 21
 * fibonacci(9) = 34
 * fibonacci(10) = 55
 * */

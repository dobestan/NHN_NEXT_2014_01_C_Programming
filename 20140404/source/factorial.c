#include <stdio.h>

int factorial(int);

int main() {
  for ( int i = 0 ; i < 10 ; i++ ) {
    printf("factorial(%d) = %d\n", i+1, factorial(i+1) );
  }
  return 0;
}

int factorial(int num) {
  // 음수를 입력했을 때 예외처리는 구현하지 않았습니다.
  // 이해하는데 집중하세요.

  if ( num == 1) return 1;
  return num * factorial( num - 1 );
}

/* ---출력 결과---
 * factorial(1) = 1
 * factorial(2) = 2
 * factorial(3) = 6
 * factorial(4) = 24
 * factorial(5) = 120
 * factorial(6) = 720
 * factorial(7) = 5040
 * factorial(8) = 40320
 * factorial(9) = 362880
 * factorial(10) = 3628800
 * */

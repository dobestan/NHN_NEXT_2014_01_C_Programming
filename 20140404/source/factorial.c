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

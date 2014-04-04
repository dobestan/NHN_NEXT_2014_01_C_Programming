#include <stdio.h>

int CompareTwoInteger(int, int);

int main() {
  printf("CompareTwoInteger(3, 4) = %d\n", CompareTwoInteger(3, 4) );
  printf("CompareTwoInteger(7, 2) = %d\n", CompareTwoInteger(7, 2) );
  return 0;
}

int CompareTwoInteger(int num1 , int num2) {
  return ( num1 >= num2 ) ? num1 : num2;

  // 이 부분은 확실히 이해해보세요.
  // ( 조건 ) ? ( true ) : ( false )
}

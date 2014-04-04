#include <stdio.h>

int CompareTwoIntegerAbsolute(int, int);

int main() {
  printf("CompareTwoIntegerAbsolute(3, -4) = %d\n", CompareTwoIntegerAbsolute(3, 4) );
  printf("CompareTwoIntegerAbsolute(-7, 2) = %d\n", CompareTwoIntegerAbsolute(7, 2) );
  printf("CompareTwoIntegerAbsolute(12, -1) = %d\n", CompareTwoIntegerAbsolute(12, -1) );
  return 0;
}

int CompareTwoIntegerAbsolute(int num1 , int num2) {
  num1 = (num1 > 0) ? num1 : -num1;
  num2 = (num2 > 0) ? num2 : -num2;

  return ( num1 >= num2 ) ? num1 : num2;

  // 이 부분은 확실히 이해해보세요.
  // ( 조건 ) ? ( true ) : ( false )
}

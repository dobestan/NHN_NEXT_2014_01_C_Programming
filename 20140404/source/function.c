#include <stdio.h> // c library에서 제공하는 헤더파일은 <>를 사용한다.
#include "function.h" // 사용자가 임의로 만든 헤더파일은 ""를 사용한다.

int main() {
  int foo = 1;
  int bar = 2;
  int result = Add(foo, bar);
  printf("RESULT = %d\n", result);
}

int Add( int num1, int num2 ) {
  return num1 + num2;
}

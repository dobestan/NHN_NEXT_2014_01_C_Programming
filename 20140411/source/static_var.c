#include <stdio.h>

void SimpleFunc(void) {
  static int num1 = 0; // static variable
  int num2 = 0; // local variable
  num1++; num2++;
  printf("Static : %d, Local : %d\n", num1, num2);
}

int main(void) {
  for ( int i = 0 ; i < 5 ; i++ ) SimpleFunc();
  return 0;
}

/* --- 출력결과 ---
 * Static : 1, Local : 1
 * Static : 2, Local : 1
 * Static : 3, Local : 1
 * Static : 4, Local : 1
 * Static : 5, Local : 1
 */

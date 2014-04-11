#include <stdio.h>

int main(void) {
  int foo[5] = { 2, 3, 5, 7, 11 }; // init array
  printf("sizeof(foo) = %d\n", sizeof(foo)); // sizeof(foo) = 5 * 4(byte) = 20(byte)
  return 0;
}

/* --- 출력결과 ---
 * sizeof(foo) = 20
 */

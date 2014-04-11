#include <stdio.h>

int main(void) {
  int foo[5] = { 2, 3, 5, 7, 11 }; // init array
  for ( int i = 0 ; i < 5 ; i++ ) {
    printf("foo[%d] = %d\n", i, foo[i]);
  }
  return 0;
}

/* --- 출력 결과 ---
 * foo[0] = 2
 * foo[1] = 3
 * foo[2] = 5
 * foo[3] = 7
 * foo[4] = 11
 *
 * foo[1]이 아니라 foo[0]부터 시작합니다.
 * 배열의 index는 0부터 시작합니다.
 */

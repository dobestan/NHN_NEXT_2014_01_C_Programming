#include <stdio.h>

int main(void) {
  int foo[5] = { 2, 3, 5, 7, 11 }; // init array
  for ( int i = 0 ; i < 5 ; i++ ) {
    printf("foo[%d] address = %d (%p)\n", i, &foo[i], &foo[i]);
  }
  return 0;
}

/* --- 출력결과 ---
 * foo[0] address = 1549485120 (0x7fff5c5b4440)
 * foo[1] address = 1549485124 (0x7fff5c5b4444)
 * foo[2] address = 1549485128 (0x7fff5c5b4448)
 * foo[3] address = 1549485132 (0x7fff5c5b444c)
 * foo[4] address = 1549485136 (0x7fff5c5b4450)
 *
 * 단, 뒤에 숫자값은 다르게 출력될 수 있습니다.
 * offset만 확인하세요.
 * 각각의 주소값이 4byte씩 차이가 있습니다.
 */

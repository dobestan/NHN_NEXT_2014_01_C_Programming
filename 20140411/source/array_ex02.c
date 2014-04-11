// 1부터 10까지의 합을 배열로 선언하여 구현해보세요.

#include <stdio.h>
int main() {
  int foo[10];
  int sum = 0;

  for ( int i = 0 ; i < 10 ; i++ ) {
    foo[i] = i + 1;
    sum += foo[i];
    printf("foo[%d] = %d\n", i, foo[i]);
  }
  printf("sum = %d\n", sum);
  return 0;
}

/* --- 출력결과 ---
 * foo[0] = 1
 * foo[1] = 2
 * foo[2] = 3
 * foo[3] = 4
 * foo[4] = 5
 * foo[5] = 6
 * foo[6] = 7
 * foo[7] = 8
 * foo[8] = 9
 * foo[9] = 10
 * sum = 55
 */

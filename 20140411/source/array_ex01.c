#include <stdio.h>

int main() {
  int foo[5];
  int bar;

  for ( bar =0 ; bar < 5 ; bar++ ) {
    foo[bar] = bar + 1;
    printf("foo[%d] = %d\n", bar, foo[bar]);
  }
  return 0;
}

/* --- 출력 결과 ---
 * foo[0] = 1
 * foo[1] = 2
 * foo[2] = 3
 * foo[3] = 4
 * foo[4] = 5
 */

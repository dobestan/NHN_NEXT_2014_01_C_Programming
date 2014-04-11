/* scanf를 이용하여 영어단어 하나를 입력받은 후,
 * 이를 거꾸로 뒤집고,
 * 거꾸로 뒤집은 문자열을 출력하시오.
 */

#include <stdio.h>
#include <string.h> // strlen 함수를 사용합니다.

int main() {
  char foo[20];
  char bar[20];

  printf("문자열을 하나 입력하세요 : ");
  scanf("%s", foo);

  int foo_length = strlen(foo);

  for ( int i = 0 ; i < foo_length ; i++ ) { bar[i] = foo[foo_length - i - 1]; }
  bar[foo_length] = '\0';

  printf("reverse(%s) =  %s\n", foo, bar);

  return 0;
}

/* --- 출력결과 ---
 * 문자열을 하나 입력하세요 : hello
 * reverse(hello) =  olleh
 */

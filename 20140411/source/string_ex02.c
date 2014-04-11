/* 하나의 영단어를 입력받아,
 * 그 길이를 계산하는 프로그램을 만들어 보세요.
 */

#include <stdio.h>
#include <string.h>

int custom_strlen(char *);

int main() {
  char foo[20];
  printf("영단어를 하나 입력하세요 : ");
  scanf("%s", foo); // 지금은 scanf로 받기 때문에 중간에 개행문자가 들어가면 안됩니다.

  // printf("길이[%s] = %d\n", foo, strlen(foo));
  printf("길이[%s] = %d\n", foo, custom_strlen(foo));

  return 0;
}

int custom_strlen(char * foo) {
  int strlen = 0;
  while ( *foo++ != '\0' ) { strlen ++; }
  return strlen;
}

/* --- 출력결과 ---
 * 영단어를 하나 입력하세요 : programming
 * 길이[programming] = 11
 */

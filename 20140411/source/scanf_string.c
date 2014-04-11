#include <stdio.h>
#include <string.h>

void print_by_char(char *, int);

int main() {
  char foo[20];
  int index = 0;

  printf("문자열을 입력하세요 : ");
  scanf("%s", foo);
  printf("입력받은 문자열 : %s\n", foo);

  print_by_char(foo, strlen(foo));

  return 0;
}

void print_by_char(char * foo, int foo_size) {
  printf("--- 문자 단위로 출력 ---\n");
  for ( int i = 0 ; i < foo_size+1 ; i++ ) {
    printf("foo[%d] = %c\n", i, foo[i]);
  }
}

/* --- 출력결과 ---
 * 문자열을 입력하세요 : hello
 * 입력받은 문자열 : hello
 * --- 문자 단위로 출력 ---
 *  foo[0] = h
 *  foo[1] = e
 *  foo[2] = l
 *  foo[3] = l
 *  foo[4] = o
 *  foo[5] =
 */

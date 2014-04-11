#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "hello world!";
  printf("string = %s\n", str);
  printf("sizeof(str) = %d\n", sizeof(str));
  printf("strlen(str) = %d\n", strlen(str));

  str[11] = '?';
  printf("string = %s\n", str);

  return 0;
}

/* --- 출력 결과 ---
 * string = hello world!
 * sizeof(str) = 13
 * strlen(str) = 12
 * string = hello world?
 */

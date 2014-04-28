/**
 * @file hw03.c
 *
 * @brief
 *
 * @details
 * 하나의 문장을 입력 받아 각 단어마다 출력을 거꾸로 하세요\n
 * 입력 시 gets(char *s) 함수를 이용하세요\n\n
 * 입력> I am a student
 * 출력> I ma a tneduts
 *
 * @todo
 * - 일단 함수를 만들고 테스트 코드를 만들자.
 */

#include <stdio.h>
#include <stdlib.h> /// stdlib.h > malloc 메모리 동적 할당을 위해서 헤더파일 추가
#include <string.h> 
/// 테스트 코드를 위하여 string.h > strcmp를 사용하기 위하여 추가
/// strlen 함수를 사용합니다.

char * make_words_inverse(char *);
void make_words_inverse_test(char *, char *);
void make_words_inverse_tests(void);

int main() {
  // make_words_inverse_tests();
  return 0;
}

/**
 * @fn char * make_words_inverse(char * foo)
 * @brief
 * @details
 * - char * string을 입력받는다.
 * - 함수 내부에서는 메모리를 동적할당 받아 문자열을 거꾸로 저장한다.
 * - 새로 생성된 문자열 포인터를 리턴한다.
 */
char * make_words_inverse(char * src) {
  // char * foo = "foo";
  // return foo;
  // source for TDD ( RED )
}

void make_words_inverse_test(char * src, char * expected) {
  printf("[%s] input is [%s], output should be [%s]\n",
      !strcmp(make_words_inverse(src), expected) ? "SUCCESS" : "FAILED",
      src,
      expected );
}

void make_words_inverse_tests(void) {
  printf("---test---\n");
  make_words_inverse_test("apple", "elppa");
  make_words_inverse_test("hello world", "olleh dlrow");
  make_words_inverse_test("I am a student", "I ma a tneduts");
  printf("----------\n");
}

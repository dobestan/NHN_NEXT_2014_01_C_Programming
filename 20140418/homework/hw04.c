/**
 * @file hw04.c
 *
 * @brief I am a student -> I ma a tneduts
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

void make_words_inverse_exec(void);

int main() {
  make_words_inverse_tests();
  make_words_inverse_exec();
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

  /// 일단 핵심적인 아이디어는 Stack을 이용하는 것
  /// 그냥 배열을 Stack으로 이용하자.
  ///
  /// 공백이 나올 때 까지 진행한다
  /// 공백이 나오면 지금까지 저장했던 문자열을 출력한다.

  char * dest = (char *) malloc (sizeof(char) * ( strlen(src) + 1) );
  /// 마지막에 NULL을 넣기 위해서 strlen(src)보다는 하나 더 크게 만들어주자.
  int dest_index = 0;

  char store_word[10] = {'\0'};
  int store_word_index = 0;
  /// for stack

  while ( *src ) { // 일단은 \0이 나올때까지 진행한다.
    store_word[store_word_index++] = *src++;

    if ( *src == ' ' || *src == '\0' ) {
      if ( *src == ' ') src++;
      for ( int i = store_word_index-1 ; i >= 0 ; i-- ) {
        dest[dest_index++] = store_word[i];
      }
      store_word_index = 0;
      dest[dest_index++] = ' ';
    }
  }

  dest[dest_index-1] = '\0';
  return dest;
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

void make_words_inverse_exec(void) {
  char foo[100] = {'\0'}; // init
  char * bar;
  printf("Enter a Sentence : ");
  gets(foo);
  bar = make_words_inverse(foo);

  printf("[%s] -> [%s]\n", foo, bar);
}

/*
 * --- result ---
 *  ---test---
 *  [SUCCESS] input is [apple], output should be [elppa]
 *  [SUCCESS] input is [hello world], output should be [olleh dlrow]
 *  [SUCCESS] input is [I am a student], output should be [I ma a tneduts]
 *  ----------
 *  warning: this program uses gets(), which is unsafe.
 *  Enter a Sentence : my name is dobestan
 *  [my name is dobestan] -> [ym eman si natsebod]
 * --------------
 */

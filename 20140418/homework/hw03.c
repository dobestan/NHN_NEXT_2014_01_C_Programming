/**
 * @file hw03.c
 * @brief
 * @details
 * 두 개의 단어를 입력 받아 두 입력 받은 두 단어를 연결하는 함수를 구현한다.
 * char *s mystrCat(char *s1, char *s2);
 * 출력에 필요한 array는 char out[100];으로 사용한다.
 */

#include <stdio.h>
#include <string.h> // string.h는 테스트 코드를 위해서 사용했습니다.

char * mystrcat(char * s1, char * s2);
void mystrcat_test(char * s1, char * s2, char * expected);
void mystrcat_tests(void);

void mystrcat_exec(void);

int main() {
  mystrcat_tests();
  mystrcat_exec();
  return 0;
}

/**
 * @fn char * mystrcat(char * s1, char * s2)
 * @brief
 * @details
 */
char * mystrcat(char * s1, char * s2) {
  // char * foo = "foo";
  // return foo;
  // RED -> Refactoring -> GREEN의 테스트 방식을 따른다.
  // 일단 char * foo를 리턴했을 때 테스트 FAILED
  // 테스트를 성공하기 위해서 성공하는 코드를 짜자.

  // char out[100] = {'\0'}; // init as NULL
  // int index = 0;

  // while ( *s1 ) { out[index++] = *s1++; }
  // out[index++] = ' ';
  // while ( *s2 ) { out[index++] = *s2++; }
  // out[index++] = '\0'; // 반드시 명시적으로 NULL character를 넣어주자.

  /**
   * warning: address of stack memory associated with local
   * variable 'out' returned [-Wreturn-stack-address]
   * return out;
   *        ^~~
   * 1 warning generated.
   *
   * 당연히 local Variable은 함수가 종료되면 사라지는데 어떻게 이 문제를 해결할 수 있을까?
   * Memory Allocation을 사용할 수 있나?
   *
   * No! strcmp 사용법에 대해서 잘못 생각을 했다.
   * 단순히 char *가 리턴되는 것이 아니라 실제로 char * dest의 값이 변경되는 것이다.
   * 그러면 처음의 s1 string이 문자의 배열로 선언되어야 하겠다.
   */

  int i = 0;
  while ( s1[i] ) { i++; }
  s1[i++] = ' ';
  while ( *s2 ) { s1[i++] = *s2++; }

  return s1;
}

/**
 * @fn void mystrcat_test(char * s1, char * s2, char * expected)
 * @brief unit test
 */
void mystrcat_test(char * s1, char * s2, char * expected) {
  /// 쉬운 비교를 위해서 string.h > strcmp 를 사용하도록 한다.
  /// 만약 두 string이 같다면 strcmp는 0을 리턴한다.

  printf("[%s] strcat(\"%s\", \"%s\") should return \"%s\"\n",
      !strcmp( mystrcat(s1,s2), expected) ? "SUCCESS" : "FAILED", s1, s2, expected );
}

void mystrcat_tests(void) {
  char hello[100] = "hello";
  char happy[100] = "happy";
  char my_name_is[100] = "My name is";

  printf("---test---\n");
  mystrcat_test(hello, "world", "hello world");
  mystrcat_test(happy, "programming", "happy programming");
  mystrcat_test(my_name_is, "dobestan", "My name is dobestan");
  printf("----------\n");
}

/**
 * @fn void mystrcat_exec(void)
 * @todo
 * ---result---
 *  warning: this program uses gets(), which is unsafe.
 *  Enter first string : hello
 *  Enter second string : world
 *  result is [hello world]
 * ------------
 *  gets()는 위험하다고 한다. fgets로 수정해보자.
 */
void mystrcat_exec(void) {
  char foo[100] = {'\0'};
  char bar[100] = {'\0'};

  printf("Enter first string : ");
  gets(foo);

  printf("Enter second string : ");
  gets(bar);

  printf("result is [%s]\n", mystrcat(foo, bar) );
}

/* --- result ---
 * ---test---
 *  [SUCCESS] strcat("hello world", "world") should return "hello world"
 *  [SUCCESS] strcat("happy programming", "programming") should return "happy programming"
 *  [SUCCESS] strcat("My name is dobestan", "dobestan") should return "My name is dobestan"
 *  ----------
 *  warning: this program uses gets(), which is unsafe.
 *  Enter first string : hello
 *  Enter second string : world
 *  result is [hello world]
 * --------------
 */

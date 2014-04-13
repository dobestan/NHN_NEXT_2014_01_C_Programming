#include <stdio.h>
#include <string.h>

char get_max_char(char *, int);
void get_max_char_test(char *, int, char);
void get_max_char_tests(void);

int main() {
  get_max_char_tests();

  char user_input_string[20];
  printf("enter a string : ");
  scanf("%s", user_input_string);
  printf("max char = %c\n", get_max_char(user_input_string, strlen(user_input_string)));

}

char get_max_char(char * string, int size) {
  char max_char = 'a';
  for ( int i = 0 ; i < size ; i++ ) {
    max_char = ( max_char > string[i] ) ? max_char : string[i];
  }
  return max_char;
}

void get_max_char_test(char * string, int size, char expected) {
  if ( get_max_char(string, size) == expected )
    printf("success : get_max_char(%s, %d) == %c\n", string, size, expected);
  else
    printf("failed : get_max_char(%s, %d) != %c, result was %c\n", string, size, expected, get_max_char(string, size));
}

void get_max_char_tests(void) {
  get_max_char_test("hello", strlen("hello"), 'o');
  get_max_char_test("programming", strlen("programming"), 'r');
  get_max_char_test("helloworld", strlen("helloworld"), 'w');
  get_max_char_test("ruby", strlen("ruby"), 'y');
  get_max_char_test("python", strlen("python"), 'y');
}

/* --- result ---
 * success : get_max_char(hello, 5) == o
 * success : get_max_char(programming, 11) == r
 * success : get_max_char(helloworld, 10) == w
 * success : get_max_char(ruby, 4) == y
 * success : get_max_char(python, 6) == y
 * enter a string : hello
 * max char = o
 */

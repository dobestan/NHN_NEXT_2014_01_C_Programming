/**
 * @file hw09.c
 * @brief Palindrome checker
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char * string, int size);
void is_palindrome_test(char * string, int size, int expected);
void is_palindrome_tests(void);

void reverse_string(char * src, char * dest, int size);

int main() {
  is_palindrome_tests();

  char user_input[20];
  printf("Enter a string : ");
  scanf("%s", user_input);

  printf("\"%s\" is %sa palindrome\n",
      user_input,
      ( is_palindrome(user_input, strlen(user_input)) ) ? "" : "not ");

  return 0;
}

/**
 * @fn int is_palindrome(char * string, int size)
 * @return
 * - true(1) : is palindrome
 * = false(0) : is not palindrome
 */
int is_palindrome(char * string, int size) {
  int is_valid = 1; // default : true(1)
  char * string_reverse = ( char * ) malloc ( sizeof(char) * size );

  reverse_string(string, string_reverse, size);
  for ( int i = 0 ; i < size ; i++ ) {
    if ( string[i] != string_reverse[i] ) is_valid = 0;
  }

  free(string_reverse);
  return is_valid;
}

void reverse_string(char * src, char * dest, int size) {
  for ( int i = 0 ; i < size ; i++ ) { dest[size-1-i] = src[i]; }
}

void is_palindrome_test(char * string, int size, int expected) {
  printf("[%s] \"%s\" is %sa palindrome\n",
      ( is_palindrome(string, size) == expected) ? "Success" : "Failed",
      string,
      ( expected ) ? "" : "not ");
}

void is_palindrome_tests(void) {
  is_palindrome_test("programming", strlen("programming"), 0);
  is_palindrome_test("dobestan", strlen("dobestan"), 0);
  is_palindrome_test("noon", strlen("noon"), 1);
  is_palindrome_test("level", strlen("level"), 1);
}

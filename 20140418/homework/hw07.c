/**
 * @file hw07.c
 * @brief 십진수 -> 이진수
 */

#include <stdio.h>
#include <stdlib.h>

int get_user_input(void);

int * convert_10_to_2(int input);
void convert_10_to_2_test(int input, int * expected);
void convert_10_to_2_tests(void);

void print_result(int input, int * binary);

int get_digits_needed(int input);
void get_digits_needed_test(int input, int expected);
void get_digits_needed_tests(void);


int main() {
  get_digits_needed_tests();
  convert_10_to_2_tests();

  int user_input = get_user_input();
  print_result(user_input, convert_10_to_2(user_input));

  return 0;
}

int get_user_input(void) {
  int user_input = 0;
  printf("enter a integer(10) : ");
  scanf("%d", &user_input);
  return user_input;
}

int * convert_10_to_2(int input) {
  int size = get_digits_needed(input);
  int * binary = (int *) malloc ( sizeof(int) * size );

  for ( int i = size-1 ; i >= 0 ; i-- ) {
    binary[i] = input%2;
    input /= 2;
  }

  return binary;
}


/**
 * @fn int get_digits_needed(int input)
 * @details
 * - 2진수를 표현하기 위해서 필요한 자리수를 리턴한다.
 * - 예를 들어서, 8(1000) = 4를 리턴한다.
 * - 예를 들어서, 18(10010) = 5를 리턴한다.
 */
int get_digits_needed(int input) {
  int size = 1;
  while ( input /= 2 ) {
    size++;
  }
  return size;
}

void get_digits_needed_test(int input, int expected) {
  printf("[%s] get_digits_needed(%d) should be [%d], and result is [%d]\n",
      (get_digits_needed(input) == expected) ? "Success" : "Failed",
      input, expected, get_digits_needed(input));
}

void get_digits_needed_tests(void) {
  get_digits_needed_test(1, 1);
  get_digits_needed_test(8, 4);
  get_digits_needed_test(19, 5);
}

void print_result(int input, int * binary) {
  int size = get_digits_needed(input);
  for ( int i = 0 ; i < size ; i++ ) { printf("%d", binary[i]); }
}

void convert_10_to_2_test(int input, int * expected) {
  int size = get_digits_needed(input);
  int * binary = convert_10_to_2(input);

  int is_valid = 1; // default : true(1)
  for ( int i = 0 ; i < size ; i++ ) {
    if ( binary[i] != expected[i] ) is_valid = 0;
  }
  free(binary);

  // pretty result form
  printf("[%s] ", (is_valid) ? "Success" : "Failed");
  printf("%d(10) should be ", input);
  print_result(input, expected);
  printf("(2)\n");
}

void convert_10_to_2_tests(void) {
  int foo[1] = {1}; // 1(10) = 1(2)
  convert_10_to_2_test(1, foo);

  int bar[4] = {1, 0, 0, 0}; // 8(10) = 1000(2)
  convert_10_to_2_test(8, bar);

  int baz[5] = {1, 0, 0, 1, 1}; // 19(10) = 10011(2)
  convert_10_to_2_test(19, baz);
}

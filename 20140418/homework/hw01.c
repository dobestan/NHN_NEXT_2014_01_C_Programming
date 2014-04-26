/**
 * @mainpage NHN NEXT > C Programming > 20140418 Homework
 * @author dobestan ( Suchan An )
 */

/**
 * @file hw01.c
 * @brief 이차원 배열을 선언하고 구구단을 출력하세요.
 * @details
 * int gugu[8][9]; \n
 * 다음 함수를 이용하여 구구단을 출력하세요. \n\n
 *
 * void gugu_func2(int* arr, int n); \n
 * void func2_print(int* arr, int n); \n
 */

#include <stdio.h>

void set_8x9_array(int * arr, int n);
void print_8x9_array(int * arr, int n);

int main() {
  int foo[8][9] = {0}; // init as [ 0, 0, 0, ... , 0 ]

  for ( int i = 0 ; i < 8 ; i++ ) {
    set_8x9_array(foo[i], i+2);
    print_8x9_array(foo[i], i+2);
  }

  return 0;
}

/**
 * @fn void set_8x9_array(int * arr, int n)
 * @brief
 * - int arr[9] 포인터를 받고 특정 정수를 입력받는다.
 * - 배열에다 특정 구구단 행을 넣는다.
 * @return void
 */
void set_8x9_array(int * arr, int n) {
  for ( int i = 0 ; i < 9 ; i++ ) {
    arr[i] = n * ( i + 1 );
  }
}

/**
 * @fn void print_8x9_array(int * arr, int n)
 * @brief
 * - int arr[9] 포인터를 받고 특정 정수를 입력받는다.
 * - 특정 구구단행을 출력한다.
 * @return void
 */
void print_8x9_array(int * arr, int n) {
  for ( int i = 0 ; i < 9 ; i++ ) {
    printf("%d x %d = %2d\n", n, i+1, arr[i]);
  }
}

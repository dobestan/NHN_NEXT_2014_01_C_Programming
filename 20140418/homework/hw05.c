/**
 * @file hw05.c
 * @brief Gray Code with Recursion
 */

#include <stdio.h>

void print_gray_code(int * gray_code, int start_bit, int end_bit, int bit);

int main() {
  int gray_code[10];
  print_gray_code(gray_code, 0, 3, 0);
  return 0;
}

/**
 * @fn void print_gray_code(int * gray_code, int start_bit, int end_bit, int bit)
 */
void print_gray_code(int * gray_code, int start_bit, int end_bit, int bit) {
  /// print_gray_code(int * gray_code, 0, BIT_SIZE, 0)으로 시작한다.
  /// bit refers to result of XOR(bit, gray_code[start_bit])

  /**
   * 시작하기에 앞서 십진수(이진수 -> 그레이코드)로 표시하기로 한다.\n
   * 코드를 시작하기에 앞서 몇 가지 예시를 통해서 쉽게 구하는 방법을 살펴보자.
   *
   *
   * ### 3(11 -> 10)을 통해서 재귀적으로 7(111 -> ?)을 구하는 과정
   * 11 -> 111, 즉 마지막 자리에 1이 생겼다.\n
   * XOR(1 , 1) = 0 이므로 10에다가 0만 붙여주면 된다.\n
   * 7(111 -> 100)
   *
   * ### 3(11 -> 10)을 통해서 재귀적으로 6(110 -> ?)을 구하는 과정
   * 11 -> 110, 즉 마지막 자리에 0이 생겼다.\n
   * XOR(1, 0) = 1이므로 10에다가 1만 붙여주면 된다.\n
   * 6(110 -> 101)
   */

  /// start_bit == end_bit 인 경우,
  /// 우리가 원하는 graycode를 얻었으므로 출력하면 된다.
  if ( start_bit == end_bit) {
    for ( int i = 0 ; i < end_bit ; i++ )
      printf("%d", gray_code[i]);
    printf("\n");
  }

  /// start_bit != end_bit 인 경우,
  /// 계속 진행한다.
  else {
    if ( bit == 0 ) {
      /// bit는 이진수의 bit 값을 의미한다.\n
      /// 출력 순서는 bit 값을 통해서 조정하자.\n\n
      ///
      /// 만약에 end_bit == 2 경우, bit 값에 따른 출력 순서는 다음과 같다.\n
      /// 0 0 0\n
      /// 0 0 1\n
      /// 0 1 0\n
      /// 0 1 1\n

      gray_code[start_bit] = 0; /// 초기값 설정 0(0 -> 0)
                                /// XOR(0, 0) = 0
      print_gray_code(gray_code, start_bit+1, end_bit, 0);

      gray_code[start_bit] = 1; /// 초기값 설정 1(1 -> 1)
                                /// XOR(0, 1) = 1
      print_gray_code(gray_code, start_bit+1, end_bit, 1);
    }

    else if ( bit == 1 ) {
      /// XOR(bit, next_bit) = gray_code[start_bit] 를 구할 수 있다.
      gray_code[start_bit] = 1; /// XOR(1, 0) = 1
      print_gray_code(gray_code, start_bit+1, end_bit, 0);

      gray_code[start_bit] = 0; /// XOR(1, 1) = 0
      print_gray_code(gray_code, start_bit+1, end_bit, 1);
    }
  }
}

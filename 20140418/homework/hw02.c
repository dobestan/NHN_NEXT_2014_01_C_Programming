/**
 * @file hw02.c
 *
 * @brief
 * Call by Value / Call by Reference Example
 *
 * @details
 * 변수 num에 저장된 값의 제곱을 계산하는 함수를 정의하고, 이를 호출하는 main함수를 작성해보자. 단, 여기서는 다음 두 가지 형태로 함수를 정의해야 한다. \n\n
 * call-by-value기반의 SquareByValue\n
 * Call-by-reference기반의 SquareByReferce\n\n
 * SquareByValue 함수는 인자로 젂달된 값의 제곱을 반홖해야 하면, SquareByReference 함수는 정수가 저장되어 있는 변수의 주소값을 인자로 받아서 해당 변수에 저장된 값의 제곱을 그 변수에 다시 저장한다.
 *
 * @todo
 * - 항상 테스트를 먼저 작성하라.
 * - 테스트를 할 때는 비용을 생각하라.
 *
 * - 주석은 얼마나 상세해야하나?
 * - 지금 내 상황에서 문서화가 필요한가?
 *
 * - 각목이 내게 던진 질문을 떠올려보자. "너가 문서화가 필요한 이유가 뭔데?"
 */

#include <stdio.h>

double square_by_value(double);
void square_by_reference(double *);

void square_by_value_test(double, double);
void square_by_reference_test(double, double);
void square_tests(void);

int main() {
  square_tests();
  return 0;
}

/**
 * @fn double square_by_value(double num)
 * @return
 * 포인터로 직접 값을 수정할 수 없으므로, Square값을 반환해야한다.
 */
double square_by_value(double num) {
  return num * num;
}

/**
 * @fn void square_by_reference(double * num)
 * @return
 * 포인터(Reference)를 통하여 직접 값을 수정하므로 리턴할 필요가 없다.
 */
void square_by_reference(double * num) {
  *num = (*num) * (*num);
}

/**
 * @fn void square_by_value_test(double num, double expected)
 * @brief unit test
 */
void square_by_value_test(double num, double expected) {
  printf("[%s] square_by_value(%lf) should return %lf\n",
      ( square_by_value(num) == expected ) ? "SUCCESS" : "FAILED", num, expected);
}

/**
 * @fn void square_by_reference_test(double num, double expected)
 * @brief unit test
 */
void square_by_reference_test(double num, double expected) {
  /**
   * square_by_reference 함수 같은 경우에는 실제로 값을 바꾼다.
   * 따라서 바뀌기 전의 원본값(double origin)을 저장해두고 시작하자.
   */

  double original = num; // original value
  square_by_reference(&num);
  double result = num; // new value

  printf("[%s] square_by_reference(%lf) should change num to %lf\n",
      ( result == expected ) ? "SUCCESS" : "FAILED", original, expected);
}

/**
 * @fn void square_tests(void)
 * @brief integration test
 */
void square_tests(void) {
  square_by_value_test(4, 16);
  square_by_value_test(5, 25);
  square_by_value_test(-7, 49);
  square_by_value_test(2.5, 6.25);

  square_by_reference_test(4, 16);
  square_by_reference_test(5, 25);
  square_by_reference_test(-7, 49);
  square_by_reference_test(2.5, 6.25);
}

/* --- result ---o
 * [SUCCESS] square_by_value(4.000000) should return 16.000000
 * [SUCCESS] square_by_value(5.000000) should return 25.000000
 * [SUCCESS] square_by_value(-7.000000) should return 49.000000
 * [SUCCESS] square_by_value(2.500000) should return 6.250000
 * [SUCCESS] square_by_reference(4.000000) should change num to 16.000000
 * [SUCCESS] square_by_reference(5.000000) should change num to 25.000000
 * [SUCCESS] square_by_reference(-7.000000) should change num to 49.000000
 * [SUCCESS] square_by_reference(2.500000) should change num to 6.250000
 */

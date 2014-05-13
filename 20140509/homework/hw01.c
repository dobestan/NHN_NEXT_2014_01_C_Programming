/**
 * @file hw01.c
 * @details
 * - 구조체를 사용한다.
 * - 복소수 구조체를 구현하라.
 * - 복소수의 합, 차, 곱을 구하라.
 */

#include <stdio.h>

typedef struct complex {
  /// Complex = real + (imaginary)i
  double real;
  double imaginary;
}Complex;

void print_complex(Complex c1);
Complex add(Complex c1, Complex c2);
Complex sub(Complex c1, Complex c2);
Complex mul(Complex c1, Complex c2);

int main() {
  Complex c1 = {1, 2};
  Complex c2 = {3, 4};

  print_complex(add(c1,c2));
  print_complex(sub(c1,c2));
  print_complex(mul(c1,c2));

  return 0;
}

void print_complex(Complex c1) {
  printf("%lf + %lfi\n", c1.real, c1.imaginary);
}

Complex add(Complex c1, Complex c2) {
  Complex result;

  result.real = c1.real + c2.real;
  result.imaginary = c1.imaginary + c2.imaginary;

  return result;
}

Complex sub(Complex c1, Complex c2) {
  Complex result;

  result.real = c1.real - c2.real;
  result.imaginary = c1.imaginary - c2.imaginary;

  return result;
}

Complex mul(Complex c1, Complex c2) {
  Complex result;

  result.real = ( c1.real * c2.real ) + (-1) * ( c1.imaginary * c2.imaginary );
  result.imaginary = ( c1.real * c2.imaginary ) + ( c2.real * c1.imaginary );

  return result;
}

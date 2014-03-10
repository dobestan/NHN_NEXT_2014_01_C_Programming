#include <stdio.h>

int main() {
  int num1 = 10; // 10(10)
  int num2 = 0xA; // A(8)=10(10)
  int num3 = 012; // 12(8)=10(10)

  printf("NUM1(10) = NUM2(10) = NUM3(10) = %d\n", num1);
  printf("NUM1(8) = NUM2(8) = NUM3(8) = %o\n", num1);
  printf("NUM1(16) = NUM2(16) = NUM3(16) = %X\n", num1);
  
  // %d for decimal output
  // %o for octar output
  // %X for hexadecimal output with Upper Case
  // %x for hexadecimal output with Lower Case

  return 0;
}

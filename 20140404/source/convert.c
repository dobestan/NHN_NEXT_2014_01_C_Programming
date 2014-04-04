#include <stdio.h>

double convert_C_to_F(double C); // 섭씨를 화씨로 변환한다.
double convert_F_to_C(double F); // 화씨를 섭씨로 변환한다.

int main() {
  char user_input_char = 0;

  double C = 0; // 섭씨 온도
  double F = 0; // 화씨 온도

  printf("변환할 온도 타입을 선택하세요 ( C / F ) : ");
  scanf("%s", &user_input_char);
  printf("온도를 입력하세요 : ");

  if ( user_input_char == 'C' ) {
    scanf("%lf", &C);
    F = convert_C_to_F(C);
  }

  else if ( user_input_char == 'F' ) {
    scanf("%lf", &F);
    F = convert_F_to_C(F);
  }


  printf("---결과---\n");
  printf("섭씨 : %lf\n", C);
  printf("화씨 : %lf\n", F);

  return 0;
}

double convert_C_to_F(double C) {
  return ( C * 1.8 ) + 32;
}

double convert_F_to_C(double F) {
  return ( F - 32 ) / 1.8;
}

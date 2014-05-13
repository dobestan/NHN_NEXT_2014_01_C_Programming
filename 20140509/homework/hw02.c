/**
 * @file hw02.c
 * @details
 * - 원뿔 : 반지름 + 높이
 * - N개의 원뿔에 대한 정보를 읽는다.
 * - 각 원뿔의 부피를 출력하는 프로그램을 작성하시오.
 */

#include <stdio.h>
#include <math.h>

typedef struct cone {
  double radius;
  double height;
}Cone;

double get_volume(Cone c1);
void print_volumes(Cone * cones, int num_of_cones);

int main() {
  // printf("%lf\n", M_PI);
  // M_PI is implemented in math.h
  Cone cones[3] = { { 1, 2 },
                    { 3, 4 },
                    { 5, 6 } };

  print_volumes(cones, sizeof(cones)/sizeof(cones[0]));
  return 0;
}

double get_volume(Cone c1) {
  return (double)1/3 * M_PI * c1.radius * c1.height;
}

void print_volumes(Cone * cones, int num_of_cones) {
  for ( int i = 0 ; i < num_of_cones ; i++ ) {
    printf("Volume(%d) = %lf\n", i+1, get_volume(*(cones+i)));
  }
}

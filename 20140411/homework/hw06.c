#include <stdio.h>
#define SIZE 5

void set_array_by_rule_1(int (*)[SIZE]);
void set_array_by_rule_2(int (*)[SIZE]);
void set_array_by_rule_3(int (*)[SIZE]);

void print_array(int (*)[SIZE]);


int main() {
  int foo[SIZE][SIZE] = {0};
  int bar[SIZE][SIZE] = {0};
  int baz[SIZE][SIZE] = {0};

  // set_array_by_rule_1(foo);
  // print_array(foo);

  set_array_by_rule_2(bar);
  print_array(bar);

  return 0;
}

void print_array(int (*foo)[SIZE]) {
  for ( int i = 0 ; i < SIZE ; i++ ) {
    for ( int j = 0 ; j < SIZE ; j++ ) {
      printf("%3d ", foo[i][j]);
    }
    printf("\n");
  }
}

void set_array_by_rule_1(int (*foo)[SIZE]) {
  int bar = 0;
}

void set_array_by_rule_2(int (*foo)[SIZE]) {
  int bar = 0;

  // 크게 두 부분으로 나누어서 생각해보자.
  // 1. 대각선을 기준으로 왼쪽 상단부
  // 2. 대각선을 기준으로 아래쪽 하단부
  //
  // 초기화 순서는 다음과 같아야 한다. ( 5x5 의 경우 )
  //
  // 1. 왼쪽 상단부
  // (0, 0)
  // (1, 0), (0, 1)
  // (2, 0), (1, 1), (0, 2)
  // (3, 0), (2, 1), (1, 2), (0, 3)
  // (4, 0), (3, 1), (2, 2), (1, 3), (0, 4)
  //
  // 2. 오른쪽 하단부
  // (4, 1), (3, 2), (2, 3), (1, 4)
  // (4, 2), (3, 3), (2, 4)
  // (4, 3), (3, 4)
  // (4, 4)
}
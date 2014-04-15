#include <stdio.h>
#include "hw06_test.h"

void set_array_by_rule_1(int (*)[SIZE]);
void set_array_by_rule_2(int (*)[SIZE]);
void set_array_by_rule_3(int (*)[SIZE]);

void print_array(int (*)[SIZE]);


int main() {
  int foo[SIZE][SIZE] = {0};
  int bar[SIZE][SIZE] = {0};
  int baz[SIZE][SIZE] = {0};

  set_array_by_rule_1(foo);
  print_array(foo);
  set_array_by_rule_1_test(foo);

  set_array_by_rule_2(bar);
  print_array(bar);
  set_array_by_rule_2_test(bar);

  set_array_by_rule_3(baz);
  print_array(baz);
  set_array_by_rule_3_test(baz);

  return 0;
}

void print_array(int (*foo)[SIZE]) {
  printf("--- print array ---\n");
  for ( int i = 0 ; i < SIZE ; i++ ) {
    for ( int j = 0 ; j < SIZE ; j++ ) {
      if ( foo[i][j] == 0 ) printf("    ");
      else printf("%3d ", foo[i][j]);
    }
    printf("\n");
  }
  printf("-------------------\n");
}

void set_array_by_rule_1(int (*foo)[SIZE]) {
  int bar = 1;  // 일단 bar++를 계속적으로 진행하면서 출력하자.
                // 이제 프로그래머가 신경써야할 부분은 출력 순서에 대한 부분이다.


  // 규칙성이 인간을 위한 규칙성이다.
  // 크게 두 부분으로 나누어서 생각해보자.
  //
  // 1. 중간열을 포함한 왼쪽 부분 ( 0행 - (SIZE-1)/2행 )
  // 2. 중간열을 포함하지 않는 오른쪽 부분 ( (SIZE+1)/2행 - SIZE-1행 )


  // 1. 중간열을 포함한 왼쪽 부분 ( 0행 - (SIZE-1)/2행 )
  for ( int i = 0 ; i < (SIZE+1)/2 ; i++ ) {
    for ( int j = i ; j < SIZE-i ; j++ ) {
      foo[j][i] = bar++;
    }
  }

  // 2. 중간열을 포함하지 않는 오른쪽 부분 ( (SIZE+1)/2행 - SIZE-1행 )
  for ( int i = (SIZE+1)/2 ; i < SIZE ; i++ ) {
    for ( int j = (SIZE-1)-i ; j < i+1 ; j++ ) {
      foo[j][i] = bar++;
    }
  }
}

void set_array_by_rule_2(int (*foo)[SIZE]) {
  int bar = 1;

  // 크게 두 부분으로 나누어서 생각해보자.
  // 1. 대각선을 기준으로 나눈 대각선을 포함한 왼쪽 상단부
  // 2. 대각선을 기준으로 나눈 대각선을 포함하지 않는 아래쪽 하단부
  //
  // 초기화 순서는 다음과 같아야 한다. ( 5x5 의 경우 )
  //
  // 1. 대각선을 기준으로 나눈 대각선을 포함한 왼쪽 상단부
  // (0, 0)
  // (1, 0), (0, 1)
  // (2, 0), (1, 1), (0, 2)
  // (3, 0), (2, 1), (1, 2), (0, 3)
  // (4, 0), (3, 1), (2, 2), (1, 3), (0, 4)
  //
  // 2. 대각선을 기준으로 나눈 대각선을 포함하지 않는 아래쪽 하단부
  // (4, 1), (3, 2), (2, 3), (1, 4)
  // (4, 2), (3, 3), (2, 4)
  // (4, 3), (3, 4)
  // (4, 4)

  // 1. 대각선을 기준으로 나눈 대각선을 포함한 왼쪽 상단부
  for ( int i = 0 ; i < SIZE ; i++ ) {
    for ( int j = 0 ; j < i+1 ; j++ ) {
      foo[i-j][j] = bar++;
    }
  }

  // 2. 대각선을 기준으로 나눈 대각선을 포함하지 않는 아래쪽 하단부
  for ( int i = 0 ; i < SIZE-1 ; i++ ) {
    for ( int j = 1+i ; j < SIZE ; j++ ) {
      foo[SIZE+i-j][j] = bar++;
    }
  }
}

void set_array_by_rule_3(int (*foo)[SIZE]) {

  // 굉장히 특이한 규칙성은 방향이 정해져있다는 것이다.
  // 오른쪽 -> 아래쪽 -> 왼쪽 -> 위쪽 -> 오른쪽 -> ... ( 반복 )
  //
  // 이 규칙성을 direction으로 정의한다.
  //
  // direction :
  // 0 stands for "right"
  // 1 stands for "down"
  // 2 stands for "left"
  // 3 stands for "up"

  int direction = 0;

  for ( int i = 0, j = 0, bar = 1 ; bar < SIZE*SIZE+1 ; bar++ ) {
    switch ( direction ) {
      case 0 :
        foo[i][j++] = bar;
        if ( j == SIZE || foo[i][j] != 0 ) {
          i++; j--;
          direction = (direction+1)%4;
        }
        break;

      case 1 :
        foo[i++][j] = bar;
        if ( i == SIZE || foo[i][j] != 0 ) {
          i--; j--;
          direction = (direction+1)%4;
        }
        break;

      case 2 :
        foo[i][j--] = bar;
        if ( j == -1 || foo[i][j] != 0 ) {
          i--; j++;
          direction = (direction+1)%4;
        }
        break;

      case 3 :
        foo[i--][j] = bar;
        if ( i == -1 || foo[i][j] != 0 ) {
          i++; j++;
          direction = (direction+1)%4;
        }
        break;
    }
  }
}



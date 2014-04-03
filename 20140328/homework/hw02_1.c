#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REPETITION 10000

/*  몬티홀 문제의 경우 조건부 확률로 계산하면 굉장히 쉽게 수학적인 확률을 알 수 있다.
 */

int get_random_1_to_n(int);
void init_door(int *);


int main() {
  int door[3];
  int user_select_door = 0;

  int door_change = 0;
  int door_proceed = 0;

  srand ( time(NULL) ); // initialize random seed

  for ( int i = 0 ; i < REPETITION ; i++) {

    // init door
    init_door(door);
    door[get_random_1_to_n(3) - 1] = 1;

    // init user_select_door
    user_select_door = get_random_1_to_n(3);

    // 여기서 우리는 두 가지 가능성이 있다.
    // 여기서 사용자가 고른 문에는
    //    - 1. 자동차가 있는 경우
    //    - 2. 염소가 있는 경우

    // 1. 처음 선택한 문에 자동차가 있는 경우
    if ( door[user_select_door - 1] == 1) {
      // 사회자는 아무 문이나 연다. ( p = 1 )

      // 문을 바꾸면 패배한다.
      // 문을 바꾸지 않으면 승리한다.
      door_change += 0;
      door_proceed += 1;
    }

    else {
      // 사회자는 아무 문이나 열지 못한다.
      // 즉, 남아 있는 2개의 문 중에서 자동차가 있지 않은 곳의 문을 연다.
      // 즉, 열리지 않은 나머지 문에는 반드시 자동차가 있다.

      // 문을 바꾸면 승리한다.
      // 문을 바꾸지 않으면 패배한다.
      door_change += 1;
      door_proceed += 0;
    }
  }

  printf("선택 변경 시 맞추는 경우 = %lf\n", (double)door_change/REPETITION);
  printf("선택 유지 시 맞추는 경우 = %lf\n", (double)door_proceed/REPETITION);
  return 0;
}

int get_random_1_to_n(int n) {
  return rand() % n + 1;
}

void init_door(int * door) {
  for ( int i = 0 ; i < 3 ; i++) {
    door[i] = 0;
  }
  return;
}

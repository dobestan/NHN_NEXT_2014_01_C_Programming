/**
 * @file hw04.c
 * @details
 * - 야구 게임
 * - 컴퓨터는 0-9 사이의 숫자 중에서 3개를 고른다.
 * - 순서까지 고른다.
 * - 단, 사용자가 예상한 숫자를 입력하면 얼마나 비슷한지 알려준다.
 * - 3 Strike / 0 Ball 이면 게임 종료
 *
 * ### Example
 * - (1, 4, 9) by Computes
 * - (4, 0, 9) by User
 * - Output should be 1 Strike, 1 Ball
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_srand_seed();
int get_randon_number();

void init_answer(int * answer);

void print_array(int * array);

void get_user_choice(int * array);
int get_user_input();

void get_result(int * answer, int * choice, int * result);
void print_result(int * result);

void play_a_game();

int main() {
  init_srand_seed();
  play_a_game();
  return 0;
}

void init_srand_seed() {
  srand(time(NULL));
}

int get_randon_number() {
  return rand() % 10; // return 0 - 9
}

void init_answer(int * answer) {
  int duplicated = 0;
  for ( int i = 0 ; i < 3 ; i++ ) {

    duplicated = 0; // init duplicated
    answer[i] = get_randon_number();

    for ( int j = 0 ; j < i ; j++ ) {
      if ( answer[i] == answer[j] ) duplicated = 1;
    }

    if ( duplicated ) i--;
  }
}

void print_array(int * array) {
  printf("[ ");
  for ( int i = 0 ; i < 3 ; i++ ) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}

int get_user_input() {
  int user_input = 0;
  fflush(stdin);
  scanf("%d", &user_input);
  return user_input;
}

void get_user_choice(int * array) {
  int is_duplicated = 0;
  for ( int i = 0 ; i < 3 ; i++ ) {
    is_duplicated = 0; // init
    printf("choice(%d) = ", i+1);
    array[i] = get_user_input();

    for ( int j = 0 ; j < i ; j++ ) {
      if ( array[i] == array[j] ) is_duplicated = 1;
    }

    if ( is_duplicated ) {
      printf("ERROR : Duplicated Input\n");
      i--;
    }
  }
}

void get_result(int * answer, int * choice, int * result) {
  // int * result = { num_of_strikes, num_of_balls }
  for ( int i = 0 ; i < 3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
      if ( answer[i] == choice[j] ) {
        // ball or strike
        if ( i == j ) result[0]++;
        else result[1]++;
      }
    }
  }
}

void print_result(int * result) {
  printf("---RESULT---\n");
  printf("STRIKE = %d\n", result[0]);
  printf("  BALL = %d\n", result[1]);
  printf("------------\n");
}

void play_a_game() {
  int answer[3];
  int choice[3];
  int result[2] = { 0 , 0 };
  int turn = 1;

  init_answer(answer);
  while ( result[0] != 3 ) {
    printf("---TURN(%2d)---\n", turn++);
    result[0] = 0;
    result[1] = 0;

    get_user_choice(choice);
    get_result(answer, choice, result);
    print_result(result);
  }
}

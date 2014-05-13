/**
 * @file hw03.c
 * @details
 * - 가위바위보 게임
 * - 사용자로부터 입력받음
 * - 프로그램은 사용자가 질 때까지 게속된다.
 * - 마지막에 결과 출력한다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOSE -1
#define TIE 0
#define WIN 1

int get_user_input(); // 0 or 1 or 2 else? input again!

void init_srand_seed();
int get_randon_number(); // get random number ( 0 or 1 or 2 )

int get_result(int user, int computer);

int what_beats_me(int num);
void play_a_game();

void print_result_in_words(int result);
void print_total_result_in_words(int * total_result);

int main() {
  init_srand_seed();
  play_a_game();

  return 0;
}

int get_user_input() {
  int user_input = -1;
  while ( user_input != 0 && user_input != 1 && user_input != 2 ) {
    fflush(stdin);
    printf("가위(0) / 바위(1) / 보(2) : ");
    scanf("%d", &user_input);
  }
  return user_input;
}

void init_srand_seed() {
  srand(time(NULL));
}

int get_randon_number() {
  return rand()%3;
}

int what_beats_me(int num) {
  return ( num + 1 ) % 3;
}

int get_result(int user, int computer) {
  int result = 0; // init

  if ( user ==  computer )
    result = TIE;
  else if ( user == what_beats_me(computer) )
    result = WIN;
  else result = LOSE;

  return result;
}

void play_a_game() {
  int result = 0;
  int total_result[2] = { 0, 0 };
  while ( (result = get_result(get_user_input(), get_randon_number())) != -1 ) {
    total_result[result]++;
    print_result_in_words(result);
  }
  print_total_result_in_words(total_result);
}

void print_result_in_words(int result) {
  char * word;
  if ( result == WIN ) word = "WIN";
  else if ( result == LOSE ) word = "LOSE";
  else word = "TIE";
  printf("result = %s\n", word);
}

void print_total_result_in_words(int * total_result) {
  printf("---TOTAL RESULT---\n TIE = %d\n WIN = %d\n ------------------\n", total_result[TIE], total_result[WIN]);

}

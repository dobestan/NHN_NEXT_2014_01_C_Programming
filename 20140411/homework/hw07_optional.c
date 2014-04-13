#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 19

// 19x19 사이즈 바둑판 게임입니다.
// 흑을 (-#)로 표시하고 백을 (+#)로 표시합니다.

void init_username(char *, int);
void print_board(int (*)[BOARD_SIZE]);
int put_stone(int, int, int (*)[BOARD_SIZE]);
int get_user_input_integer_with_name(char *);

static int current_turn = 1;
static int current_turn_sign_bit = -1;

int main() {

  char username_1[20]; // user1 = 흙
  char username_2[20]; // user2 = 백

  // init board
  int foo[BOARD_SIZE][BOARD_SIZE] = {0}; // init SIZE*SIZE size

  // init username
  init_username(username_1, 1);
  init_username(username_2, 2);

  while (1) {
    print_board(foo);
    if ( current_turn == BOARD_SIZE * BOARD_SIZE + 1 ) {
      printf("게임을 종료합니다.\n");
      return 0;
    }

    printf("---Turn(%2d)---\n", current_turn);
    printf("[%s]님의 턴입니다.\n", (current_turn%2) ? username_1 : username_2 );
    while( put_stone(get_user_input_integer_with_name("ROW"), get_user_input_integer_with_name("COL"), foo) != 0 ) {
      printf("올바른 위치를 입력하세요.\n");
    }
    print_board(foo);
  }

  return 0;
}

void init_username(char * username, int user_index) {
  printf("USER(%d)의 이름을 입력하세요 : ", user_index);
  fflush(stdin);
  scanf("%s", username);
}

void print_board(int (*board)[BOARD_SIZE]) {
  system("clear"); // system call : clear ( require stdlib.h )

  // 열 번호 출력하기
  printf("  ");
  for ( int i = 0 ; i < BOARD_SIZE ; i++ ) {
    printf("%4d", i+1);
  }
  printf("\n");

  // 열 번호 구분선 출력하기
  printf("  ");
  for ( int i = 0 ; i < BOARD_SIZE ; i++ ) {
    printf("----");
  }
  printf("\n");

  // 행번호 및 실행순서(돌의 위치값) 출력하기
  for ( int i = 0 ; i < BOARD_SIZE ; i++ ) {
    printf("%2d|", i+1); // 행 번호 출력하기

    for ( int j = 0 ; j < BOARD_SIZE ; j++ ) {
      printf("%+3d ", board[i][j]);
    }
    printf("\n");
  }
}

int put_stone(int row, int col, int (*board)[BOARD_SIZE]) {

  // Usage : putStone(get_user_input_integer_with_name("ROW"), get_user_input_integer_with_name("COL"), foo);
  //
  // Exception :
  //  - location validity : 가능한 위치인가? ( 현재의 위치값이 0인가? )

  if ( row == -1 || col == -1 ) return -1;
  if ( board[row-1][col-1] != 0 ) return -1;

  else {
    board[row-1][col-1] = current_turn_sign_bit * current_turn;

    current_turn_sign_bit *= (-1);
    current_turn++;
    return 0;
  }
}


int get_user_input_integer_with_name(char * foo) {

  // Exception :
  //  - 숫자를 입력하였는가? ( scanf의 리턴값이 1인가? )
  //  - BOARD_SIZE에 적합한 값을 입력하였는가? ( 1 <= foo <= BOARD_SIZE )

  int bar = 0;
  printf("%s = ", foo);
  fflush(stdin);
  scanf("%d", &bar);

  if ( bar > BOARD_SIZE || bar < 1 ) return -1;
  else return bar;
}

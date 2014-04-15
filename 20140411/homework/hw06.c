#include <stdio.h>
#define SIZE 5

void set_array_by_rule_1(int (*)[SIZE]);
void set_array_by_rule_2(int (*)[SIZE]);
void set_array_by_rule_3(int (*)[SIZE]);

void set_array_by_rule_1_test(int (*)[SIZE]);
void set_array_by_rule_2_test(int (*)[SIZE]);
void set_array_by_rule_3_test(int (*)[SIZE]);

void print_array(int (*)[SIZE]);
void print_compare_result(int (*)[SIZE], int (*)[SIZE]);


int main() {
  int foo[SIZE][SIZE] = {0};
  int bar[SIZE][SIZE] = {0};
  int baz[SIZE][SIZE] = {0};

  // set_array_by_rule_1(foo);
  // print_array(foo);

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
      printf("%3d ", foo[i][j]);
    }
    printf("\n");
  }
  printf("-------------------\n");
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

void set_array_by_rule_3(int (*foo)[SIZE]) {
}


void set_array_by_rule_1_test(int (*result)[SIZE]) {
  int expected[SIZE][SIZE] = {
    {  1,  0,  0,  0, 13 },
    {  2,  6,  0, 10, 14 },
    {  3,  7,  9, 11, 15 },
    {  4,  8,  0, 12, 16 },
    {  5,  0,  0,  0, 17 },
  };

  print_compare_result(result, expected);
}


void set_array_by_rule_2_test(int (*result)[SIZE]) {
  int expected[SIZE][SIZE] = {
    {  1,  3,  6, 10, 15 },
    {  2,  5,  9, 14, 19 },
    {  4,  8, 13, 18, 22 },
    {  7, 12, 17, 21, 24 },
    { 11, 16, 20, 23, 25 },
  };

  print_compare_result(result, expected);
}


void set_array_by_rule_3_test(int (*result)[SIZE]) {
  int expected[SIZE][SIZE] = {
    {  1,  3,  6, 10, 15 },
    {  2,  5,  9, 14, 19 },
    {  4,  8, 13, 18, 22 },
    {  7, 12, 17, 21, 24 },
    { 11, 16, 20, 23, 25 },
  };

  print_compare_result(result, expected);
}

void print_compare_result(int (*result)[SIZE], int (*expected)[SIZE]) {
  int pass = 0;
  printf("--- comparision result ---\n");
  for ( int i = 0 ; i < SIZE ; i++ ) {
    for ( int j = 0 ; j < SIZE ; j++ ) {
      if ( result[i][j] == expected[i][j] ) pass++;
      printf("%s", ( result[i][j] == expected[i][j]) ? "O" : "X" );
    }
    printf("\n");
  }
  printf("--------------------------\n");
  printf("pass = %2d/%2d ( %.2lf %% )\n", pass, SIZE*SIZE, (double)pass / (SIZE*SIZE) * 100 );
  printf("fail = %2d/%2d ( %.2lf %% )\n", SIZE*SIZE - pass, SIZE*SIZE, (double)(SIZE*SIZE - pass) / (SIZE*SIZE) * 100 );
  printf("result = %s\n", ( pass == SIZE * SIZE ) ? "SUCCESS" : "FAILED" );
  printf("--------------------------\n");
}

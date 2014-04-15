#define SIZE 5

void set_array_by_rule_1_test(int (*)[SIZE]);
void set_array_by_rule_2_test(int (*)[SIZE]);
void set_array_by_rule_3_test(int (*)[SIZE]);
void print_compare_result(int (*)[SIZE], int (*)[SIZE]);

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

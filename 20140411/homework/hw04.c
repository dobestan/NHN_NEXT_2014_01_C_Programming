#include <stdio.h>

// matrix multiply

void get_matrix_2x3(int (*)[3]);
void get_matrix_3x2(int (*)[2]);
void calc_matrix_multiply(int (*)[3], int (*)[2], int (*)[2]);

int main() {
  int foo[2][3];
  int bar[3][2];

  int result[2][2] = {0, 0, 0, 0};

  get_matrix_2x3(foo);
  get_matrix_3x2(bar);
  calc_matrix_multiply(foo, bar, result);

  return 0;
}

void get_matrix_2x3(int (*foo)[3]) {
  printf("---foo(2x3)---\n");
  for ( int i = 0 ; i < 2 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
      printf("foo[%d][%d] = ", i, j);
      scanf("%d", &foo[i][j]);
    }
  }
}

void get_matrix_3x2(int (*bar)[2]) {
  printf("---bar(3x2)---\n");
  for ( int i = 0 ; i < 3 ; i++ ) {
    for ( int j = 0 ; j < 2 ; j++ ) {
      printf("bar[%d][%d] = ", i, j);
      scanf("%d", &bar[i][j]);
    }
  }
}

void calc_matrix_multiply(int (*foo)[3], int (*bar)[2], int (*result)[2]) {
  printf("---result(2x2)---\n");
  for ( int i = 0 ; i < 2 ; i++ ) {
    for ( int j = 0 ; j < 2 ; j++ ) {
      for ( int k = 0 ; k < 3 ; k++ ) {
        result[i][j] += foo[i][k] * bar[k][j];
      }
      printf("%3d ", result[i][j]);
    }
    printf("\n");
  }
}

/* --- result ---
 * ---foo(2x3)---
 *  foo[0][0] = 1
 *  foo[0][1] = 2
 *  foo[0][2] = 3
 *  foo[1][0] = 4
 *  foo[1][1] = 5
 *  foo[1][2] = 6
 *  ---bar(3x2)---
 *  bar[0][0] = 2
 *  bar[0][1] = 4
 *  bar[1][0] = 6
 *  bar[1][1] = 3
 *  bar[2][0] = 5
 *  bar[2][1] = 7
 *  ---result(2x2)---
 *  29  31
 *  68  73
 */

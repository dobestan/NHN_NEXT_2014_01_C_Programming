/* 가로의 길이가 9, 세로의 길이가 3인 int형 2차원 배열을 선언하여,
 * 구구단 중 2단, 3단, 4단을 배열의 1행, 2행, 3행에 저장하시오.
 */

#include <stdio.h>

int main() {
  int foo[9][3]; // init array 9 * 3

  // init array
  for ( int i = 0 ; i < 3 ; i++ ) {
    for ( int j = 0 ; j < 9 ; j++ ) {
      foo[i][j] = ( i + 2 ) * ( j + 1 );
      printf("%3d", foo[i][j]);
    }
    printf("\n");
  }

  return 0;
}

/* --- 출력결과 ---
 * 2  4  6  8 10 12 14 16 18
 * 3  6  9 12 15 18 21 24 27
 * 4  8 12 16 20 24 28 32 36
 */

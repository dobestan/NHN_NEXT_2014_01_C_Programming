/* int형 배열을 선언하고 5개의 숫자를 입력받아서
 * - 제일 큰 수
 * - 제일 작은 수
 * - 합
 * 을 출력하세요
 */

#include <stdio.h>

void get_user_input(int *);
void print_array(int *, int);
int get_max(int *, int);
int get_min(int *, int);
int get_sum(int *, int);

int main() {
  int foo[5];
  get_user_input(foo);
  print_array(foo, sizeof(foo)/sizeof(int));

  printf("\n\n연산 결과는 다음과 같습니다.\n");
  printf("MAX = %d\n", get_max(foo, sizeof(foo)/sizeof(int)));
  printf("MIN = %d\n", get_min(foo, sizeof(foo)/sizeof(int)));
  printf("SUM = %d\n", get_sum(foo, sizeof(foo)/sizeof(int)));
  return 0;
}

void get_user_input(int * foo) {
  for ( int i = 0 ; i < 5 ; i++ ) {
    printf("foo[%d] = ", i);
    scanf("%d", &foo[i]);
  }
}

void print_array(int * foo, int size) {
  printf("\n\n입력받은 배열은 다음과 같습니다.\n");
  for ( int i = 0 ; i < size ; i++ ) {
    printf("foo[%d] = %d\n", i, foo[i]);
  }
}

int get_max(int * foo, int size) {
  int max = foo[0];
  for ( int i = 0 ; i < size ; i++ ) {
    max = ( max > foo[i] ) ? max : foo[i];
  }
  return max;
}

int get_min(int * foo, int size) {
  int min = foo[0];
  for ( int i = 0 ; i < size ; i++ ) {
    min = ( min < foo[i] ) ? min : foo[i];
  }
  return min;
}

int get_sum(int * foo, int size) {
  int sum = 0;
  for ( int i = 0 ; i < size ; i++ ) { sum += foo[i]; }
  return sum;
}

/* --- 출력결과 ---
 * foo[0] = 17
 * foo[1] = 23
 * foo[2] = 7
 * foo[3] = 19
 * foo[4] = 4
 *
 *
 * 입력받은 배열은 다음과 같습니다.
 * foo[0] = 17
 * foo[1] = 23
 * foo[2] = 7
 * foo[3] = 19
 * foo[4] = 4
 *
 *
 * 연산 결과는 다음과 같습니다.
 * MAX = 23
 * MIN = 4
 * SUM = 70
 */

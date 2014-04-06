#include <stdio.h>

int is_prime(int);
int get_sqrt(int, int);
void get_primes(int, int);

int main() {
  get_primes(10, 1);
  return 0;
}

int get_sqrt(int num, int i) {

  // first function call : get_sqrt(num, 0)
  // square root 값을 내림한 정수값을 리턴합니다.
  //
  // get_sqrt(81, 0) = 9
  // get_sqrt(82, 0) = 9
  //
  // 과제 끝내고 실제로 math.h에는 어떻게 구현되어 있는지 살펴보기

  if ( num < i*i ) return i-1;
  return get_sqrt(num, i+1);
}

int is_prime(int num) {
  for ( int i=2 ; i <= get_sqrt(num, 0) ; i++ ) {
    if ( num % i == 0 ) return 0;
  }
  return 1;
}

void get_primes(int n, int current_num) {
  // first function call : get_primes(n, 1)
  if ( n == 0 ) return;

  if ( is_prime(current_num + 1) ) {
    printf("%d\n", current_num + 1);
    get_primes(n-1, current_num + 1);
  }
  else get_primes(n, current_num + 1);
}

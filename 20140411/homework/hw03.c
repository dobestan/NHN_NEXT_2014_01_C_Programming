#include <stdio.h>

int is_prime(int);
int get_sqrt(int, int);
void get_primes(int);

int main() {
  get_primes(200);
  return 0;
}

int get_sqrt(int num, int i) {

  // first function call : get_sqrt(num, 0)
  // square root 값을 내림한 정수값을 리턴합니다.
  //
  // get_sqrt(81, 0) = 9
  // get_sqrt(82, 0) = 9

  if ( num < i*i ) return i-1;
  return get_sqrt(num, i+1);
}

int is_prime(int num) {
  if ( num == 1 ) return 0;
  for ( int i=2 ; i <= get_sqrt(num, 0) ; i++ ) {
    if ( num % i == 0 ) return 0;
  }
  return 1;
}

void get_primes(int num) {
  int count = 0;
  for ( int i = 1 ; i < num ; i++ ) {
    if ( is_prime(i) ) {
      printf("%4d", i);
      if (++count % 10 == 0) printf("\n");
    }
  }
}

/* --- result ---
 *    2   3   5   7  11  13  17  19  23  29
 *   31  37  41  43  47  53  59  61  67  71
 *   73  79  83  89  97 101 103 107 109 113
 *  127 131 137 139 149 151 157 163 167 173
 *  179 181 191 193 197 199
 */

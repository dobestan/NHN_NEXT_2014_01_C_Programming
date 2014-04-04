#include <stdio.h>

int factorial(int);

int main() {
  for ( int i = 0 ; i < 10 ; i++ ) {
    printf("factorial(%d) = %d\n", i+1, factorial(i+1) );
  }


  return 0;
}

int factorial(int num) {
  if ( num == 1) return 1;
  return num * factorial( num - 1 );
}

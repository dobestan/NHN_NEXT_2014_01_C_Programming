#include <stdio.h>

// 9x9 table with for loop
// this is more adequate for 9x9 table
// why? programmer knows when to finish the loop

int main() {
  for ( int i=1 ; i<10 ; i++ ) {
    for ( int j=1 ; j<10 ; j++) {
      printf("%d x %d = %d\n", i, j, i*j);
    }
    printf("\n");
  }

  return 0;
}

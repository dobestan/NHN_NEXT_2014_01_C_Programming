#include <stdio.h>

void print_3x3_array(int **);

int main() {
  int foo[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  int bar[3][3] = {
    {1,},
    {4, 5},
    {7, 8, 9}
  };

  int baz[3][3] = {1, 2, 3, 4, 5, 6, 7};

  print_3x3_array(foo);
  print_3x3_array(bar);
  print_3x3_array(baz);


  return 0;
}

void print_3x3_array(int ** foo) {
  for ( int i = 0 ; i < 3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
      printf("%2d", foo[i][j]);
    }
  }
  printf("\n");
}

#include <stdio.h>

void print_10x10_array(int (*)[10]);
void set_triangle(int (*)[10]);
void set_inverted_triangle(int (*)[10]);

int main() {
  int foo[10][10] = {0}; // init
  int bar[10][10] = {0}; // init

  printf("--- result1 ---\n");
  set_triangle(foo);
  print_10x10_array(foo);

  printf("--- result2 ---\n");
  set_inverted_triangle(bar);
  print_10x10_array(bar);

  return 0;
}

void print_10x10_array(int (*foo)[10]) {
  for ( int i = 0 ; i < 10 ; i++ ) {
    for ( int j = 0 ; j < 10 ; j++ ) {
      if (foo[i][j] == 0) printf("    ");
      else printf("%3d ", foo[i][j]);
    }
    printf("\n");
  }
}

void set_triangle(int (*foo)[10]) {
  int sum = 1;
  for ( int i = 0 ; i < 10 ; i++ ) {
    for ( int j = 10-i-1 ; j < 10 ; j++ ) {
      foo[i][j] = sum++;
    }
  }
}

void set_inverted_triangle(int (*foo)[10]) {
  int sum = 1;
  for ( int i = 0 ; i < 10 ; i++ ) {
    for ( int j = 0 ; j < i+1 ; j++ ) {
      foo[j][i] = sum++;
    }
  }
}

// --- result ---
//--- result1 ---
//                                      1
//                                  2   3
//                              4   5   6
//                          7   8   9  10
//                     11  12  13  14  15
//                 16  17  18  19  20  21
//             22  23  24  25  26  27  28
//         29  30  31  32  33  34  35  36
//     37  38  39  40  41  42  43  44  45
// 46  47  48  49  50  51  52  53  54  55
//--- result2 ---
//  1   2   4   7  11  16  22  29  37  46
//      3   5   8  12  17  23  30  38  47
//          6   9  13  18  24  31  39  48
//             10  14  19  25  32  40  49
//                 15  20  26  33  41  50
//                     21  27  34  42  51
//                         28  35  43  52
//                             36  44  53
//                                 45  54
//                                     55

#include <stdio.h>

// get maximum k
// 2^k <= n

int get_max_k(int, int, int);

int main() {
  int user_input = 0;
  printf("enter a number : ");
  scanf("%d", &user_input);

  printf("%d\n", get_max_k(user_input, 0, 1));
  return 0;
}

int get_max_k(int num, int i, int exp) {
  // first fucntion call : get_max_k(num, 0, 1)
  if ( !(num >= exp) ) return i-1;
  return get_max_k(num, i+1, exp * 2);
}

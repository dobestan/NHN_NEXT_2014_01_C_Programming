#include <stdio.h>

int get_user_input(void);

int main() {
  printf("HEX(16) = %X\n", get_user_input());
  return 0;
}

int get_user_input(void) {
  int user_input = 0;
  printf("DEC(10) = ");
  scanf("%d", &user_input);
  return user_input;
}

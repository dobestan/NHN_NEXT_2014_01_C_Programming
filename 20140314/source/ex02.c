#include <stdio.h>

int main() {
  int user_input_second = 0;
  printf("Enter second(s) : ");
  scanf("%d", &user_input_second);
  printf("%d seconds = %d minutes %d seconds\n", user_input_second, user_input_second/60, user_input_second%60);
  return 0;
}

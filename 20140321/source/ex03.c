#include <stdio.h>

int main() {
  int user_input = 0;
  int result = 1;

  while (user_input < 1) { // validate user_input
    printf("Enter a number : ");
    fflush(stdin);
    scanf("%d", &user_input);
  }

  for (int i=1 ; i<user_input+1 ; i++) {
    result *= i;
  }

  printf("factorial(%d) = %d\n", user_input, result);

  return 0;
}

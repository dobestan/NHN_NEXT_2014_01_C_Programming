#include <stdio.h>

int main() {
  int user_input = 0;
  int sum = 0;

  printf("---SUM---\n");
  printf("enter 0 to finish\n\n");

  do {
    printf("Enter a number : ");
    fflush(stdin); // clear standard input/ouput buffer
    scanf("%d", &user_input);

    sum += user_input; // add user_input to sum
    printf("CURRENT SUM = %d\n", sum);
  }while(user_input != 0); // iterate when user_input is not 0

  printf("\nTOTAL SUM = %d\n", sum);

  return 0;
}

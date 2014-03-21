#include <stdio.h>

int main() {
  int user_input = 0;
  int sum = 0;

  for (int i=0 ; i<5 ; i++) { // iterate 5 times

    while (user_input < 1) {
      printf("Enter number(%d) : ", i+1);
      fflush(stdin); // clear buffer
      scanf("%d", &user_input);
    }
    sum += user_input;
    user_input = 0; // initalize user_input
  }

  printf("SUM = %d\n", sum);

  return 0;
}

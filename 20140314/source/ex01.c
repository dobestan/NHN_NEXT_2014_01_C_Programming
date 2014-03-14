#include <stdio.h>

int main() {
  int user_input[4];
  int biggest = 0;

  int i; // index for loop

  for ( i=0 ; i<4 ; i++ ) {
    printf("Enter (%d) integer : ", i+1);
    scanf("%d", &user_input[i]);

    if (user_input[i] > biggest)
      biggest = user_input[i];
  }

  printf("biggest integer is ... %d\n", biggest);

  return 0;
}

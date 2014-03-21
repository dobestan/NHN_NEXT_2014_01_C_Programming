#include <stdio.h>

int main() {
  int user_input_stars = 0;

  printf("Enter number of stars : ");
  scanf("%d", &user_input_stars);

  for ( int i=0 ; i<user_input_stars ; i++ ) {
    for ( int j=0 ; j<i+1 ; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

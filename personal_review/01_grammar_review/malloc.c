#include <stdio.h>
#include <stdlib.h>

int main() {
  int number_of_students = 0;
  int i;
  printf("Enter number of students : ");
  scanf("%d", &number_of_students);

  int * students_table = malloc(sizeof(int) * number_of_students);
  for (i=0 ; i<number_of_students ; i++) {
    students_table[i]=i;
    printf("%d\n", students_table[i]);
  }
  return 0;
}

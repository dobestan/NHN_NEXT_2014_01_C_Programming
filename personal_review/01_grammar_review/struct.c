#include <stdio.h>
#include <stdlib.h>

typedef struct studnet {
  int s_num;
  char * name;
  int height;
}STUDENT;

int main() {
  STUDENT * s01;
  s01 = (STUDENT *)malloc(sizeof(STUDENT));
  s01->s_num = 23;
  s01->name = "dobestan";
  //s01->height = 183;
  (*s01).height = 183;

  printf("Student Number : %d\n", s01->s_num);
  printf("Student Name : %s\n", s01->name);
  printf("Student Height : %d\n", s01->height);
  return 0;
}

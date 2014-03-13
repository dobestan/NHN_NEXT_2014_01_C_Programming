#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  int s_num;
  char * name;
  int height;
}STUDENT;

int main() {
  STUDENT * s01_p;
  s01_p = (STUDENT *)malloc(sizeof(STUDENT));
  s01_p->s_num = 23;
  s01_p->name = "dobestan";
  //s01_p->height = 183;
  (*s01_p).height = 183;

  printf("Student Number : %d\n", s01_p->s_num);
  printf("Student Name : %s\n", s01_p->name);
  printf("Student Height : %d\n", s01_p->height);

  STUDENT s02 = *s01_p;
  printf("Student Number : %d\n", s02.s_num);
  printf("Student Name : %s\n", s02.name);
  printf("Student Height : %d\n", s02.height);

  free(s01_p);
  return 0;
}

#include <stdio.h>

// { Korean, English, Math, Total }

void get_users_grades(int (*)[4]);
void get_user_grades(int *);

void print_users_grades(int (*)[4]);
void print_user_grades(int *);


int main() {
  int grade[3][4];

  get_users_grades(grade);
  print_users_grades(grade);
  return 0;
}


void get_users_grades(int (*grade)[4]) {
  for ( int i = 0 ; i < 3 ; i++ ) {
    printf("---user(%d)---\n", i+1);
    get_user_grades(grade[i]);
  }
}

void get_user_grades(int * user) {
  char * class[3] = {"Korean", "English", "Math"};

  for ( int i = 0 ; i < 3 ; i++ ) {
    printf("%s = ", class[i]);
    fflush(stdin);
    scanf("%d", &user[i]);

    user[3] += user[i];
  }
}

void print_users_grades(int (*grade)[4]) {
  printf("KOREAN ENGLISH MATH TOTAL\n");
  printf("-------------------------\n");

  for ( int i = 0 ; i < 3 ; i++ ) {
    print_user_grades(grade[i]);
    printf("\n");
  }
}

void print_user_grades(int * user) {
  for ( int i = 0 ; i < 4 ; i++ ) printf("%6d", user[i]);
}

/* --- result ---
 * ---user(1)---
 *  Korean = 80
 *  English = 70
 *  Math = 90
 *  ---user(2)---
 *  Korean = 40
 *  English = 50
 *  Math = 90
 *  ---user(3)---
 *  Korean = 20
 *  English = 40
 *  Math = 90
 *  KOREAN ENGLISH MATH TOTAL
 *  -------------------------
 *      80    70    90   240
 *      40    50    90   180
 *      20    40    90   150
 */


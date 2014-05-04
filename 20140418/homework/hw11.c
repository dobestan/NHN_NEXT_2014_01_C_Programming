/**
 * @file hw11.c
 * @brief n명 죽이는데 살아남는 솔루션 구하기
 *
 * ### 아이디어
 * - 일단 Circular Queue를 이용해서 하면 직관적일 것 같은데 너무 귀찮다.
 * - 그냥 적당한 사이즈 배열을 이용해서 구해보자.
 */

#include <stdio.h>
#include <stdlib.h>

int where_to_survive(int num);
void init_people(int * people, int num);
int next_person_to_kill(int * people, int num, int where);
int next_person_index(int num, int where);
void print_people(int * people, int num);

void where_to_survive_test(int num, int expected);
void where_to_survive_tests(void);

int main() {
  where_to_survive_tests();

  return 0;
}

int where_to_survive(int num) {

  if ( num == 1 ) return 1;

  int where = 1;
  int * people = ( int * ) malloc ( sizeof(int) * num );
  init_people(people, num);

  for ( int i = 0 ; i < num-1 ; i++ ) { // kill n-1 person
    people[where] = 0; // kill one person
    // printf("kill %d\n", where+1);
    where = next_person_to_kill(people, num, where);
  }

  free(people);
  return where+1;
}

int next_person_to_kill(int * people, int num, int where) {
  while ( 1 ) {
    where = next_person_index(num, where);
    if ( people[where] ) { break; }
  }

  while ( 1 ) {
    where = next_person_index(num, where);
    if ( people[where] ) { break; }
  }

  return where;
}

int next_person_index(int num, int where) {
  return (where+1)%num;
}

void print_people(int * people, int num) {
  for ( int i = 0 ; i < num ; i++ ) {
    printf("%s ", people[i] ? "O" : "X");
  }
  printf("\n");
}

void init_people(int * people, int num) {
  for ( int i = 0 ; i < num ; i++ ) {
    people[i] = 1;
  }
}

void where_to_survive_test(int num, int expected) {
  printf("[%s] where_to_survive(%d) should return (%d)\n",
      ( where_to_survive(num) == expected) ? "Success" : "Failed",
      num, expected);
}

void where_to_survive_tests(void) {
  where_to_survive_test(1, 1);
  where_to_survive_test(2, 1);
  where_to_survive_test(3, 3);
  where_to_survive_test(4, 1);
  where_to_survive_test(5, 3);
  where_to_survive_test(6, 5);
  where_to_survive_test(7, 7);
  where_to_survive_test(8, 1);
}

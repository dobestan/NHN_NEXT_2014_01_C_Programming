/**
 * @file hw08.c
 * @brief 짝수/홀수 채워나가기
 * @details
 */

int get_size_of_array(void);
int * init_array(int size);
void print_array(int * array, int size);

#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = get_size_of_array();
  int * array = init_array(size);
  print_array(array, size);

  free(array);
  return 0;
}


int get_size_of_array(void) {
  int size = 0;
  printf("배열의 크기를 입력하세요 : ");
  scanf("%d", &size);
  return size;
}

int * init_array(int size) {
  int * array = (int *) malloc ( sizeof(int) * size );
  int startId = 0;
  int endId = size-1;
  int user_input = 0;

  for ( int i = 0 ; i < size ; i++ ) {
    printf("(%d)번째 요소 : ", i+1);
    fflush(stdin);
    scanf("%d", &user_input);

    // init array
    if ( user_input % 2 ) array[startId++] = user_input;
    else array[endId--] = user_input;
  }

  return array;
}

void print_array(int * array, int size) {
  for ( int i = 0 ; i < size ; i++ ) printf("%d ", array[i]);
  printf("\n");
}

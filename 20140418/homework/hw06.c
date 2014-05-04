/**
 * @file hw06.c
 * @brief 홀수/짝수 구분하기
 */

// void print_even_numbers_in_array(int * array);
void print_numbers_in_array(int * array, int size, int flag);
int get_size_of_array(void);
int * init_array(int size);

#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = get_size_of_array();
  int * array = init_array(size);

  print_numbers_in_array(array, size, 1);
  print_numbers_in_array(array, size, 0);

  free(array);
  return 0;
}

/**
 * @fn void print_numbers_in_array(int * array, int size, int flag)
 * @details
 * - flag를 입력받아 홀수를 출력하거나 짝수를 출력한다.
 * - flag == 0 : 짝수를 출력한다.
 * - flag == 1 : 홀수를 출력한다.
 */
void print_numbers_in_array(int * array, int size, int flag) {
  printf("배열에서 %s를 출력합니다...\n",
      (flag) ? "홀수" : "짝수");
  for ( int i = 0 ; i < size ; i++ ) {
    if ( array[i]%2 == flag ) printf("%2d ", array[i]);
  }
  printf("\n");
}

int get_size_of_array(void) {
  int size = 0;
  printf("배열의 크기를 입력하세요 : ");
  scanf("%d", &size);
  return size;
}

int * init_array(int size) {
  int * array = (int *) malloc ( sizeof(int) * size );
  for ( int i = 0 ; i < size ; i++ ) {
    printf("array[%d] = ", i);
    fflush(stdin);
    scanf("%d", &array[i]);
  }

  return array;
}

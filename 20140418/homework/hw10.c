/**
 * @file hw10.c
 * @brief Selection Sort
 */

#include <stdio.h>

void selection_sort(int * array, int size);
int get_min_index(int * array, int size);
void swap_int(int * foo, int * bar);
void print_array(int * array, int size);

void selection_sort_test(int * array, int * expected, int size);
void selection_sort_tests(void);

int main() {
  selection_sort_tests();
  return 0;
}

void selection_sort(int * array, int size) {
  for ( int i = 0 ; i < size ; i++ ) {
    swap_int(&array[i], &array[get_min_index(array+i, size-i) + i]);
  }
}

int get_min_index(int * array, int size) {
  int min_index = 0;
  for ( int i = 0 ; i < size ; i++ ) {
    if ( array[min_index] > array[i] ) min_index = i;
  }
  return min_index;
}

void swap_int(int * foo, int * bar) {
  int temp = *foo;
  *foo = *bar;
  *bar = temp;
}

void print_array(int * array, int size) {
  for ( int i = 0 ; i < size ; i++ ) { printf("%d ", array[i]); }
  printf("\n");
}

void selection_sort_test(int * array, int * expected, int size) {
  int is_valid = 1;
  print_array(array, size);
  selection_sort(array, size);
  print_array(array, size);

  for ( int i = 0 ; i < size ; i++ ) {
    if ( array[i] != expected[i] ) is_valid = 0;
  }

  printf("[%s]\n", is_valid ? "Success" : "Failed" );
}

void selection_sort_tests(void) {
  int foo[5] = {3, 5, 4, 8, 7};
  int foo_sorted[5] = {3, 4, 5, 7, 8};
  selection_sort_test(foo, foo_sorted, 5);

  int bar[3] = {5, 3, 1};
  int bar_sorted[3] = {1, 3, 5};
  selection_sort_test(bar, bar_sorted, 3);
}

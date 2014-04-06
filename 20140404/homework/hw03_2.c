#include <stdio.h>

void print_9x9_table(int);
void print_9x9_tables(int, int);

int get_user_input_with_custom_msg(char *);

int main() {
  int foo, bar;
  foo = get_user_input_with_custom_msg("foo = ");
  bar = get_user_input_with_custom_msg("bar = ");
  print_9x9_tables( ( foo < bar ) ? foo : bar , ( foo > bar ) ? foo : bar );
  return 0;
}

int get_user_input_with_custom_msg(char * msg) {
  int user_input = 0;
  printf("%s", msg);
  fflush(stdin);
  scanf("%d", &user_input);
  return user_input;
}

void print_9x9_table(int num) {
  for ( int i = 0 ; i < 9 ; i++ ) printf("%2d x %2d = %2d\n", num, i+1, num * ( i + 1 ) );
}

void print_9x9_tables(int foo, int bar) {
  for ( int i = foo ; i <= bar ; i++ ) print_9x9_table(i);
}

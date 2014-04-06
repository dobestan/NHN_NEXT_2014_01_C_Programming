#include <stdio.h>

int get_second(void);
void print_time(int);

int main() {
  print_time(get_second());
  return 0;
}

int get_second(void) {
  int second;
  printf("second = ");
  scanf("%d", &second);
  return second;
}

void print_time(int second) { printf("%d시간 %d분 %d초\n", (second/60)/60 , (second/60)%60 , (second%60) ); }

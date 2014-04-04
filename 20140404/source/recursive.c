#include <stdio.h>

void recursive(int num);

int main() {
  recursive(3);
  return 0;
}

void recursive(int num) {
  if ( num < 0 ) { return; }
  printf("Recursive Call(%d)\n", num);
  recursive(num-1);
  printf("Recursive Exit(%d)\n", num); // recursive 함수의 시작 시점과 종료 시점을 잘 파악하세요.
}

/* ---출력결과---
 * Recursive Call(3)
 * Recursive Call(2)
 * Recursive Call(1)
 * Recursive Call(0)
 * Recursive Exit(0)
 * Recursive Exit(1)
 * Recursive Exit(2)
 * Recursive Exit(3)
 * */

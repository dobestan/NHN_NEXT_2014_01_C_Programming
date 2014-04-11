#include <stdio.h>

int Add(int);
int num = 1; // static variable

int main() {
  int num = 5; // local variable
  printf("num : %d\n", Add(3)); // 9 + 3 = 12
  printf("num : %d\n", num + 9); // 5 + 9 = 14
  return 0;
}

int Add(int val) {
  int num = 9;
  num += val;
  return num;
}

/* --- 출력결과 ---
 * num : 12
 * num : 14
 */

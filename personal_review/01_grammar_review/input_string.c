#include <stdio.h>

// difference between SCANF() and GETS()
// escape character : space, tab, enter

int main() {
  char name[20];
  printf("Enter your name : ");
  scanf("%s", name);
  // gets(name);
  printf("%s\n", name);
  fflush(stdin); // should clear input buffer

  printf("Enter your girlfriend name : ");
  scanf("%s", name);
  printf("%s\n", name);
  return 0;
}

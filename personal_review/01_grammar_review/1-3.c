#include <stdio.h>
#include <string.h>

int main() {
  char first_name[10];
  char last_name[10];

  printf("Enter your FirstName : ");
  scanf("%s", first_name);

  printf("Enter your LastName : ");
  scanf("%s", last_name);

  printf("%s %s\n", first_name, last_name);
  for (int i=0 ; i<strlen(first_name)-1 ; i++) printf(" ");
  printf("%d ", strlen(first_name));
  for (int i=0 ; i<strlen(last_name)-1 ; i++) printf(" ");
  printf("%d\n", strlen(last_name));
  return 0;
}

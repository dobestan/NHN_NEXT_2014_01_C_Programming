#include <stdio.h>

int main() {
  char *com[] = { "monitor",
                  "pointer",
                  "speaker",
                  "mouse" };
  char **ptr[] = { com+3, com+2, com+1, com };
  char *** root = ptr;

  printf("[%s]\n", **++root);
  printf("[%s]\n", *--*++root + 2); // the last pointer is [char *]
  return 0;
}

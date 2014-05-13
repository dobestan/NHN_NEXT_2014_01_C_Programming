#include <stdio.h>

int main(void) {
  struct Point {
    int xpos;
    int ypos;
  };

  struct Circle {
    double radius;
    struct Point * center;
  };

  struct Point center = { 2, 7 };
  struct Circle ring = { 5.5, &center };

  printf("radius = %lf\n", ring.radius);
  printf("xpos = %d\n", ring.center->xpos);
  return 0;

}

#include <stdio.h>

  extern long Compute();

int main() {

  printf("The main C program will now call the .asm program.\n\n" );
  int x;
  x = Compute();

  printf("\nThe integer %d will be returned to the calling program. \n", x);
  return 0;
}

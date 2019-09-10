#include <stdio.h>

  extern int Compute();

int main() {

  printf("The main C program will now call the .asm program.\n" );
  int x;
  x = Compute();

  printf("The integer %d will be returned to the calling program. \n", x);
  return 0;
}

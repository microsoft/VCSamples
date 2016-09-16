//Copyright (c) Microsoft Corporation.  All rights reserved.

#include <stdio.h>
#include <stdlib.h>

int euclid(int, int);
void usage(char*);

int main(int argc, char* argv[])
{
  int i, j;

// prompt with usage if command line arguments are not present
  if (argc<3)
    usage(argv[0]);

// retrieve command line arguments
  i = atoi(argv[1]);
  j = atoi(argv[2]);

// prompt with usage if command line arguments are not non-zero,
// positive integers
  if (!(i>0) || !(j>0)) {
    printf("%s %d %d\n", argv[0], i, j);
    usage(argv[0]);
  }

// call function that implements Euclid's algorithm, in this case a C
// function, and print result
  printf("The greatest common divisor of %d and %d: %d\n", i, j, euclid(i, j));
  return 0;
}

// Euclid's algorithm finds the greatest common divisor by repeatedly
// subtracting the smaller number from the larger number until zero
// reached. The number remaining is the greatest common divisor.
int euclid(int x, int y)
{
  int t;

  do {
    if (x<y) {
      t=x;
      x=y;
      y=t;
    }
    x -= y;
  } while (x);

  return y;
}

void usage(char* str)
{
    printf("usage: %s num1 num2\n", str);
    printf("  for non-zero, positive num1 and num2\n");
    exit(1);
}

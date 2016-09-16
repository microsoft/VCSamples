//Copyright (c) Microsoft Corporation.  All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

char *p;           // global char array used to track primes
unsigned int sz;   // range in which to search for primes (size of array)

void sieve(void);  // prototype for Sieve of Eratosthenes function
void usage(char*); // display usage and exit

int main(int argc, char* argv[])
{
  unsigned int i;

// prompt with usage if command line argument is not present
  if (argc<2)
    usage(argv[0]);

// retrieve command line argument
  sz = atoi(argv[1]);

// prompt with usage if command line argument is not a non-zero,
// positive integer
  if (!(sz>0)) {
    printf("%s %d\n", argv[0], sz);
    usage(argv[0]);
  }

// allocate memory for and zero global array used to track primes
  if ((p=malloc(sz))==NULL) {
    printf("failed to allocate %d bytes of memory.\n", sz);
    usage(argv[0]);
  }
  #pragma warning (suppress: 6387)
  memset(p, 0, sz);

// call function that implements Sieve of Eratosthenes, in this case,
// a C function.
  sieve();

// print result
  printf("primes up to %d\n", sz);
  for (i=0; i<sz; i++)
  #pragma warning (suppress: 6011)
	  if (p[i]==0)
      printf("%d\n", i+1);

  return 0;
}

// The Sieve of Eratosthenes uses an array of an integral type to 
// track prime numbers where the index into the array represents the 
// number and the value stored is its 'prime-ness' -- 0 for prime, 
// 1 for not prime.  Non-primes are calculated by exhaustively 
// multiplying pairs of integers together from 2 to N, N being chosen 
// based on range of primes desired, to calculate non-primes. This 
// implementation uses an array of chars to reduce memory usage.
void sieve(void)
{
  unsigned int i, j;

  for (i=2; i<=sz/2; i++)
    for (j=2; j<=sz/i; j++)
      p[i*j-1]=1;
}

void usage(char* str)
{
  printf("usage: %s num\n", str);
  printf("  for a non-zero, positive num\n");
  exit(1);
}

// Euler41.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


__int64 llTotal = 0;

bool isDivisible( const int *v, int nDivisor, int n1, int n2, int n3 ) {
	int nInside = v[n1-1] * 100 + v[n2-1] * 10 + v[n3-1];

	if ( 0 == nInside % nDivisor )
		return true;
	return false;
}

void print(const int *v, const int size)
{
  if (v != 0) {
    for (int i = 0; i < size; i++) {
      printf("%4d", v[i] );
    }
    printf("\n");
  }
} // print

void test( const int *v, const int size)
{
	// quick test to see if it's even
	if ( ( v[size-1] & 1 ) == 0 )
		return;

	// build a number from the digits
	__int64 mult = 1;
	__int64 n = 0;
		
	for (int m = 0; m < size; m++ ) {
		n += v[size-1-m] * mult;
		mult *= 10;
	}

	if ( n == 2143LL ) {
		printf ("%lld\n", n );
	}

	bool isPrime = true;

	for ( __int64 divisor = 3; divisor <= sqrt((double) n); divisor += 2 ) {
		if ( n % divisor == 0 ) {
			isPrime = false;
			break;
		}
	}

	if ( isPrime ) {
		if ( n > llTotal ) {
			llTotal = n;
			printf("%lld\n", n );
		}
	}
}


void swap(int *v, const int i, const int j)
{
  int t;
  t = v[i];
  v[i] = v[j];
  v[j] = t;
}


void rotateLeft(int *v, const int start, const int n)
{
  int tmp = v[start];
  for (int i = start; i < n-1; i++) {
    v[i] = v[i+1];
  }
  v[n-1] = tmp;
} // rotateLeft


void permute(int *v, const int start, const int n)
{
   // print(v, n);
	test(v, n);
  if (start < n) {
    int i, j;
    for (i = n-2; i >= start; i--) {
      for (j = i + 1; j < n; j++) {
    swap(v, i, j);
    permute(v, i+1, n);
      } // for j
      rotateLeft(v, i, n);
    } // for i
  }
} // permute


void init(int *v, int N)
{
  for (int i = 0; i < N; i++) {
    v[i] = i+1;
  }
} // ini

int _tmain(int argc, _TCHAR* argv[])
{
	int v[100];

	for ( int nLength = 6; nLength <= 9; nLength++ ) {
	    init(v, nLength);
		permute(v, 0, nLength);
	}
}

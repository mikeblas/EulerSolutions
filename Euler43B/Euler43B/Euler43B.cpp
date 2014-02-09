// Euler43B.cpp : Defines the entry point for the console application.
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
	if ( isDivisible( v, 2, 2, 3, 4 ) &&
		isDivisible( v, 3, 3, 4, 5 ) &&
		isDivisible( v, 5, 4, 5, 6 ) && 
		isDivisible( v, 7, 5, 6, 7 ) &&
		isDivisible( v, 11, 6, 7, 8 ) &&
		isDivisible( v, 13, 7, 8, 9 ) && 
		isDivisible( v, 17, 8, 9, 10 ) )
	{
		__int64 mult = 1;
		__int64 n = 0;
		
		for (int m = 0; m < size; m++ ) {
			n += v[size-1-m] * mult;
			mult *= 10;
		}

		llTotal += n;
		printf( "%lld: %lld\n", n, llTotal );
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
    v[i] = i;
  }
} // ini

int _tmain(int argc, _TCHAR* argv[])
{
	int *v = (int*) malloc(sizeof(int)*10);
    init(v, 10);
    permute(v, 0, 10);
    free(v);
}


// Euler100.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*


b/n * n-1 / n-1 == 1/2

b     b-1     210
-  *  ---  == ---
n     n-1     420 


http://www.alpertron.com.ar/QUAD.HTM


*/


int _tmain(int argc, _TCHAR* argv[])
{

	__int64 b = 85;
	__int64 n = 120;
	__int64 minimum = 1000000000000;
 
	while ( n < minimum ){
	    __int64 newb = 3 * b + 2 * n - 2;
		__int64 newn = 4 * b + 3 * n - 3;
 
		b = newb;
		n = newn;

		printf("%lld: %lld, %lld\n", b+n, b, n );
	}


	return 0;

}


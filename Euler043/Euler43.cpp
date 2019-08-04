// Euler43.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int toInteger( char ch ) {
	return ch - '0';
}

bool isPandigital( const char *pstr )
{
	bool b[10];
	for ( int n = 0; n < 10; n++ )
		b[n] = 0;

	for ( const char *p = pstr; *p != 0; p++ ) {
		int n = toInteger( *p );
		if ( n >= 10 || n < 0 ) {
			printf("%s error!!!\n", pstr );
			exit(1);
		}
		if ( b[n] == true )
			return false;
		b[n] = true;
	}

	for ( int n = 0; n < 10; n++ ) {
		if ( b[n] == false )
			return false;
	}
	return true;
}

bool isDivisible( const char *pstr, int nDivisor, int n1, int n2, int n3 ) {
	int nInside = toInteger(pstr[n1-1]) * 100 + toInteger(pstr[n2-1]) * 10 + toInteger(pstr[n3-1]);

	if ( 0 == nInside % nDivisor )
		return true;
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	__int64 llTotal = 0;
	char szCurrent[20];

	for ( int n = 1234567890; n <= 9876543210; n++ ) {
		_itoa( n, szCurrent, 10 );

		if ( ! isPandigital( szCurrent ) ) 
			continue;
		// printf( "%s\n", szCurrent );

		if ( isDivisible( szCurrent, 2, 2, 3, 4 ) &&
			 isDivisible( szCurrent, 3, 3, 4, 5 ) &&
			 isDivisible( szCurrent, 5, 4, 5, 6 ) && 
			 isDivisible( szCurrent, 7, 5, 6, 7 ) &&
			 isDivisible( szCurrent, 11, 6, 7, 8 ) &&
			 isDivisible( szCurrent, 13, 7, 8, 9 ) && 
			 isDivisible( szCurrent, 17, 8, 9, 10 ) )
		{
			llTotal += n;
			printf( "%s: %lld\n", szCurrent, llTotal );
		}
	}

	return 0;
}


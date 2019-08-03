// Euler1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"





typedef unsigned char byte;

template <int C>
class CFibo 
{
public:
	int nLength;
	int nMaxLength;
	byte* bDigits;


	CFibo()
	{
		nMaxLength = C;
		bDigits = new byte[C];
	}

	~CFibo()
	{
		delete [] bDigits;
	}

	void set( int n )
	{
		nLength = 0;
		bDigits[0] = 0;

		while ( n > 0 )
		{
			bDigits[nLength++] = n % 10;
			n = n / 10;
		}
	}

	static void add( CFibo &sum, CFibo &a, CFibo &b )
	{
		int nMax = ( a.nLength > b.nLength ) ? a.nLength : b.nLength;
		byte carry = 0;
		for ( int n = 0; n < nMax; n++ )
		{
			byte tsum = 0;
			if ( n < a.nLength ) tsum += a.bDigits[n];
			if ( n < b.nLength ) tsum += b.bDigits[n];
			tsum += carry;
			if ( tsum >= 10 ) { tsum -= 10; carry = 1; }
			else carry = 0;

			sum.bDigits[n] = tsum;
		}

		if ( carry == 0 )
			sum.nLength = nMax;
		else
		{
			sum.nLength = nMax + 1;
			sum.bDigits[nMax] = carry;
		}

		if (sum.nMaxLength <= sum.nLength) {
			printf("Max length exceeded %d\n", sum.nMaxLength);
			exit(1);
		}
	}

	static void multiply( CFibo &product, CFibo &factor, byte b )
	{
		byte carry = 0;
		for ( int n = 0; n < factor.nLength; n++ )
		{
			byte tprod = factor.bDigits[n] * b;
			tprod += carry;
			if ( tprod >= 10 ) { carry = tprod / 10; tprod = tprod % 10; }
			else carry = 0;

			product.bDigits[n] = tprod;
		}

		if ( carry == 0 )
			product.nLength = factor.nLength;
		else
		{
			product.nLength = factor.nLength + 1;
			product.bDigits[factor.nLength] = carry;
		}
	}

	static void shift( CFibo &target, int nPositions )
	{
		if ( nPositions == 0 )
			return;
		if ( target.isZero() )
			return;

		for ( int n = target.nLength -1; n >= 0; n-- )
		{
			target.bDigits[n+nPositions] = target.bDigits[n];
		}
		for ( int n = 0; n < nPositions; n++ )
		{
			target.bDigits[n] = 0;
		}
		target.nLength = target.nLength + nPositions;

		if ( target.nMaxLength <= target.nLength )
			DebugBreak();

		return;
	}

	bool isZero()
	{
		if ( nLength == 0 )
			return true;
		if ( nLength == 1 && bDigits[0] == 0 )
			return true;
		return false;
	}

	static void multiply( CFibo &product, CFibo &a, CFibo &b )
	{
		product.set(0);
		CFibo temp;
		for ( int nb = 0; nb < b.nLength; nb++ )
		{
			multiply( temp, a, b.bDigits[nb] );
			shift( temp, nb );
			add( product, product, temp );
		}
	}
};

typedef CFibo<2000> CFibo2K;
typedef CFibo<1000000> CFibo1M;

void Problem25()
{
	CFibo2K f1; CFibo2K f2; CFibo2K f3;
	CFibo2K *p1 = &f1;
	CFibo2K *p2 = &f2;
	CFibo2K *p3 = &f3;

	f1.set(1);
	f2.set(1);
	int nTerm = 1;

	while ( p1->nLength < 1000 )
	{
		CFibo2K::add( *p3, *p1, *p2 );
		CFibo2K *pTemp = p1;
		p1 = p2;
		p2 = p3;
		p3 = pTemp;

		nTerm++;
	}

	printf("%d\n", nTerm );
}



void Problem20()
{
	CFibo2K f1; CFibo2K f2; CFibo2K f3;

	CFibo2K *p1 = &f1;
	CFibo2K *p2 = &f2;
	CFibo2K *p3 = &f3;

	p1->set(1);
	for ( int n = 1; n <= 100; n++ )
	{
		p2->set(n);
		CFibo2K::multiply( *p3, *p1, *p2 );

		CFibo2K *pTemp = p1;
		p1 = p3;
		p3 = pTemp;
	}

	int nSum = 0;

	for ( int n = 0; n < p1->nLength; n++ )
	{
		nSum += p1->bDigits[n];
	}

	printf("%d\n", nSum );
}




#define ELEMENTS(x) (sizeof(x) / sizeof(x[0]) )



void Problem31()
{
	int ways = 1;

	for ( int p = 0; p <= 200; p++ )
	{
		for ( int t = 0; t <= 100; t++ )
		{
			printf("%d\n", ways);
			for ( int n = 0; n <= 40; n++ )
			{
				for ( int d = 0; d <= 20; d++ )
				{
					for ( int dd = 0; dd <= 10; dd++ )
					{
						for ( int h = 0; h <= 4; h++ )
						{
							for ( int ps1 = 0; ps1 <= 2; ps1++ )
							{
								int total = p + t*2 + n*5 + d*10 + dd*20 + h*50 + ps1*100;
								if ( total == 200 )
									ways++;
							}
						}
					}
				}
			}
		}
	}

	printf("%d\n", ways );
}


bool pandigital( byte *b )
{
	bool bits[9] = { false };

	for ( int n = 0; n < 9; n++ )
	{
		if ( b[n] == 0 )
			return false;
		if ( b[n] > 9 )
			printf("!\n");
		if ( bits[b[n]-1] == true )
			return false;
		bits[b[n]-1] = true;
	}

	return true;
}

void Problem104()
{
	CFibo1M f1; CFibo1M f2; CFibo1M f3;
	CFibo1M *p1 = &f1;
	CFibo1M *p2 = &f2;
	CFibo1M *p3 = &f3;

	f1.set(1);
	f2.set(1);
	int nTerm = 1;

	while (1)
	{
		CFibo1M::add(*p3, *p1, *p2);
		CFibo1M *pTemp = p1;
		p1 = p2;
		p2 = p3;
		p3 = pTemp;
		nTerm++;

		// number is in p1
		if (p1->nLength < 9)
			continue;
		/*
		if ( nTerm == 2749 )
			printf( "!\n" );

		if ( nTerm == 541 )
			printf("!\n");
		*/
		if (nTerm == 329468)
			printf("!\n");

		bool last = pandigital(p1->bDigits);
		bool first = pandigital(p1->bDigits + p1->nLength - 9);

		if (last) {
			printf("last pandigital at %d (length is %d)\n", nTerm, p1->nLength);
		}
		if (first) {
			printf("first pandigital at %d (length is %d)\n", nTerm, p1->nLength);
		}


		if ( first && last )
		{
			printf( "answer = %d\n", nTerm );
			break;
		}
	}
}

void Problem34()
{
	int factorials[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

	char sz[100];
	int nFound = 0;

	for ( int n = 0; n < 1000000000; n++ )
	{
		_itoa( n, sz, 10 );
		bool bWorked = true;
		int nSum = 0;

		for ( char *pstr = sz; *pstr != 0; pstr++ )
		{
			nSum += factorials[ *pstr - '0' ];
			if ( nSum > n )
			{
				bWorked = false;
				break;
			}
		}

		if ( bWorked && nSum == n )
		{
			nFound++;
			printf("%d: %d\n", nFound, n );
		}
	}

	printf("%d\n", nFound );
}



int Roll6()
{
	// RAND_MAX is 32767

	while (1)
	{
		int n = rand();
		if ( n >= 32766 )
			return 1 + ( n % 6 );
	}
}

int Roll4()
{
	// RAND_MAX is 32767

	while (1)
	{
		int n = rand();
		if ( n >= 32760 )
			return 1 + ( n % 4 );
	}
}


void Problem205()
{
	int nFourWins = 0;
	int nSixWins = 0;
	int nGames = 0;

	for ( int nRounds = 0; nRounds < 1000000; nRounds++ )
	{
		for ( int nGame = 0; nGame < 1000; nGame++ )
		{
			int nSixHand = Roll6() + Roll6() + Roll6() + Roll6() + Roll6() + Roll6();
			int nFourHand = Roll4() + Roll4() + Roll4() + Roll4() + Roll4() + Roll4() + Roll4() + Roll4() + Roll4();

			if ( nSixHand > nFourHand )
				nSixWins++;
			else
				nFourWins++;
			nGames++;
		}

		printf("%d: %g\n", nGames, nFourWins / (double) nGames );
	}
}

void Problem205a()
{
	int waysRoll6[36];
	int waysRoll4[36];

	for ( int n = 0; n < 36; n++ )
	{
		waysRoll4[n] = 0;
		waysRoll6[n] = 0;
	}

	for ( int d1 = 1; d1 <= 4; d1++ )
	{
		for ( int d2 = 1; d2 <= 4; d2++ )
		{
			for ( int d3 = 1; d3 <= 4; d3++ )
			{
				for ( int d4 = 1; d4 <= 4; d4++ )
				{
					for ( int d5 = 1; d5 <= 4; d5++ )
					{
						for ( int d6 = 1; d6 <= 4; d6++ )
						{
							for ( int d7 = 1; d7 <= 4; d7++ )
							{
								for ( int d8 = 1; d8 <= 4; d8++ )
								{
									for ( int d9 = 1; d9 <= 4; d9++ )
									{
										int nRoll = d9 + d8 + d7 + d6 + d5 + d4 + d3 + d2 + d1;
										waysRoll4[nRoll-1] += 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}


	for ( int d1 = 1; d1 <= 6; d1++ )
	{
		for ( int d2 = 1; d2 <= 6; d2++ )
		{
			for ( int d3 = 1; d3 <= 6; d3++ )
			{
				for ( int d4 = 1; d4 <= 6; d4++ )
				{
					for ( int d5 = 1; d5 <= 6; d5++ )
					{
						for ( int d6 = 1; d6 <= 6; d6++ )
						{
							int nRoll = d6 + d5 + d4 + d3 + d2 + d1;
							waysRoll6[nRoll-1] += 1;
						}
					}
				}
			}
		}
	}

	for ( int n = 0; n < 36; n++ )
	{
		printf( "%2d: %6d %6d\n", n+1, waysRoll4[n], waysRoll6[n] );
	}
}	


class CSieve
{
public:
	CSieve( int nMaximum )
	{
		nMax = nMaximum;
		pFlags = new bool[nMax];

		for ( int n = 0; n < nMax; n++ )
		{
			pFlags[n] = true;
		}

		pFlags[0] = false;
		pFlags[1] = false;
		pFlags[2] = true;
		pFlags[3] = true;

		walkInterval( 2 );

		for ( int nInterval = 3; nInterval <= nMax/2; nInterval += 2 )
		{
			walkInterval( nInterval );
		}
	}

	void walkInterval( int nInterval )
	{
		for ( int n = nInterval*2; n < nMax; n += nInterval )
		{
			pFlags[n] = false;
		}
	}

	bool isPrime( int n )  
	{
		if ( n >= nMax || n < 0 )
			DebugBreak();

		return pFlags[n];
	}

	int nMax;
	bool *pFlags;
};


void Problem35()
{
	CSieve s(1200000);

	int nFound = 0;

	for ( int n = 2; n < 1000000; n++ )
	{
		if ( !s.isPrime(n) )
			continue;

		char szThis[15];
		_itoa( n, szThis, 10 );
		size_t nLen = strlen( szThis );

		bool bAllPrime = true;

		for ( size_t x = 1; x < nLen; x++ )
		{
			char szRotated[15];
			memcpy( szRotated, szThis + x, nLen - x );
			memcpy( szRotated + nLen - x, szThis, x );
			szRotated[nLen] = 0;

			int nRotated = atoi( szRotated );
			if ( !s.isPrime( nRotated ) )
			{
				bAllPrime = false;
				break;
			}
		}

		if ( bAllPrime )
		{
			printf("%d\n", n );
			nFound++;
		}
	}

	printf(" Found %d\n", nFound);
}

void Problem37()
{
	CSieve s(1200000);

	int nFound = 0;
	int nSum = 0;

	for ( int n = 10; n < 1000000; n++ )
	{
		if ( !s.isPrime(n) )
			continue;

		char szThis[15];
		_itoa( n, szThis, 10 );
		size_t nLen = strlen( szThis );

		bool bAllPrime = true;

		for ( size_t x = 1; x < nLen; x++ )
		{
			int nCurrent = atoi( szThis+x );
			if ( !s.isPrime( nCurrent ) )
			{
				bAllPrime = false;
				break;
			}
		}

		if ( bAllPrime )
		{
			for ( int x = (int) nLen-1; x > 0; x-- )
			{
				szThis[x] = 0;

				int nCurrent = atoi( szThis );
				if ( !s.isPrime( nCurrent ) )
				{
					bAllPrime = false;
					break;
				}
			}
		}


		if ( bAllPrime )
		{
			printf("%d\n", n );
			nFound++;
			nSum += n;
		}
	}

	printf("Sum is %d\n", nSum );
}



int _tmain(int argc, _TCHAR* argv[])
{
	// Problem7();
	// Problem10();
	// Problem5();
	// Problem6();
	// Problem8();
	// Problem11();
	// Problem25();

	// Problem4();
	// Problem9();
	// Problem20();

	// Problem12();
	// Problem14();
	// collatzSteps( 837799 );
	// Problem16();

	// Problem18();

	// Problem145();

	// Problem31();
	Problem104();
	// Problem34();

	// Problem21();
	// Problem30();


	// Incomplete
	// Problem205a();

	// Problem35();

	// Problem37();

	}


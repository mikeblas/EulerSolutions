// Euler1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void Problem7()
{
	int candidate = 3;
	int primeCount = 1;


	while ( primeCount < 10001 )
	{
		bool isPrime = true;

		for ( int nDivisor = 2; nDivisor < candidate / 2; nDivisor++ )
		{
			if ( candidate % nDivisor == 0 )
			{
				isPrime = false;
				break;
			}
		}

		if ( isPrime )
		{
			primeCount++;
			printf( "%d, %d\n", primeCount, candidate );
		}

		candidate += 2;
	}
}

void Problem10()
{
	__int64 sum = 2;
	int candidate = 3;


	while ( 1 )
	{
		bool isPrime = true;

		for ( int nDivisor = 2; nDivisor < candidate / 2; nDivisor++ )
		{
			if ( candidate % nDivisor == 0 )
			{
				isPrime = false;
				break;
			}
		}

		if ( isPrime )
		{
			if ( candidate >= 2000000 )
				break;
			sum += candidate;
		}

		candidate += 2;
	}

	printf("%lld\n", sum);
}


void Problem5()
{
	int candidate = 20;
	for ( bool satisfied = false; !satisfied; candidate += 2 )
	{
		satisfied = true;
		for ( int n = 2; n <= 20; n++ )
		{
			if ( candidate % n != 0 )
			{
				satisfied = false;
				break;
			}
		}

		if ( satisfied )
			printf("%d\n", candidate );
	}

}

void Problem8()
{
	char s[] = 
		"73167176531330624919225119674426574742355349194934"
	"96983520312774506326239578318016984801869478851843"
	"85861560789112949495459501737958331952853208805511"
	"12540698747158523863050715693290963295227443043557"
	"66896648950445244523161731856403098711121722383113"
	"62229893423380308135336276614282806444486645238749"
	"30358907296290491560440772390713810515859307960866"
	"70172427121883998797908792274921901699720888093776"
	"65727333001053367881220235421809751254540594752243"
	"52584907711670556013604839586446706324415722155397"
	"53697817977846174064955149290862569321978468622482"
	"83972241375657056057490261407972968652414535100474"
	"82166370484403199890008895243450658541227588666881"
	"16427171479924442928230863465674813919123162824586"
	"17866458359124566529476545682848912883142607690042"
	"24219022671055626321111109370544217506941658960408"
	"07198403850962455444362981230987879927244284909188"
	"84580156166097919133875499200524063689912560717606"
	"05886116467109405077541002256983155200055935729725"
	"71636269561882670428252483600823257530420752963450";

	int maxproduct = 0;
	for ( size_t n = 0; n < strlen(s) - 5; n++ )
	{
		int nDigit1 = s[n + 0] - '0';
		int nDigit2 = s[n + 1] - '0';
		int nDigit3 = s[n + 2] - '0';
		int nDigit4 = s[n + 3] - '0';
		int nDigit5 = s[n + 4] - '0';

		if ( nDigit5 == 0 )
		{
			n += 5;
			continue;
		}

		int product = nDigit1 * nDigit2 * nDigit3 * nDigit4 * nDigit5;
		if ( product > maxproduct )
			maxproduct = product;
	}

	printf("%d\n", maxproduct);

}

void Problem6()
{
	int sum = 0;
	int squares = 0;

	for ( int n = 1; n <= 100; n++ )
	{
		sum += n;
		squares += (n * n);
	}

	printf("square of sums = %d\n", sum * sum);
	printf("Sum of squares = %d\n", squares );
	printf("diff = %d\n", (sum * sum) - squares);
}

void Problem11()
{
	char sz[] = 
	"08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 "
	"49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 "
	"81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 "
	"52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 "
	"22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 "
	"24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 "
	"32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 "
	"67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 "
	"24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 "
	"21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 "
	"78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 "
	"16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 "
	"86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 "
	"19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 "
	"04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 "
	"88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 "
	"04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 "
	"20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 "
	"20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 "
	"01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48 ";

	int n[20][20];

	{
		int nRow = 0;
		int nCol = 0;
		for ( size_t x = 0; x < strlen(sz); x += 3 )
		{
			int temp = atoi(&sz[x]);
			n[nRow][nCol] = temp;
			nCol += 1;
			if ( nCol == 20 ) { nCol = 0; nRow++;  }
		}
	}

	int maxproduct = 0;

	for ( int nRow = 0; nRow < 20; nRow++ )
	{
		for ( int nCol = 0; nCol < 17; nCol++ )
		{
			int nProduct = n[nRow][nCol+0] * n[nRow][nCol+1] * n[nRow][nCol+2] * n[nRow][nCol+3];
			if ( maxproduct < nProduct )
				maxproduct = nProduct;
		}
	}

	for ( int nRow = 0; nRow < 17; nRow++ )
	{
		for ( int nCol = 0; nCol < 20; nCol++ )
		{
			int nProduct = n[nRow+0][nCol] * n[nRow+1][nCol] * n[nRow+2][nCol] * n[nRow+3][nCol];
			if ( maxproduct < nProduct )
				maxproduct = nProduct;
		}
	}

	for ( int nRow = 0; nRow < 17; nRow++ )
	{
		for ( int nCol = 0; nCol < 17; nCol++ )
		{
			int nProduct = n[nRow+0][nCol+0] * n[nRow+1][nCol+1] * n[nRow+2][nCol+2] * n[nRow+3][nCol+3];
			if ( maxproduct < nProduct )
				maxproduct = nProduct;
		}
	}

	for ( int nRow = 0; nRow < 17; nRow++ )
	{
		for ( int nCol = 4; nCol < 20; nCol++ )
		{
			int nProduct = n[nRow+0][nCol-0] * n[nRow+1][nCol-1] * n[nRow+2][nCol-2] * n[nRow+3][nCol-3] ;
			if ( maxproduct < nProduct )
				maxproduct = nProduct;
		}
	}

	printf("%d\n", maxproduct);


}

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

		if ( sum.nMaxLength <= sum.nLength )
			DebugBreak();
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


bool isPalindrome( const char *pstr )
{
	const char *pstrFirst = pstr;
	const char *pstrLast = pstr;
	while ( pstrLast[1] != 0 )
		pstrLast++;

	while ( pstrFirst <= pstrLast )
	{
		if ( *pstrFirst != *pstrLast )
			return false;
		pstrFirst++;
		pstrLast--;
	}

	return true;
}


void Problem4()
{
	char sz[100];
	int nLargest = 0;

	for ( int k = 100; k <= 999; k++ )
	{
		for ( int j = 100; j <= 999; j++ )
		{
			_itoa( k*j, sz, 10 );
			if ( isPalindrome( sz ) )
			{
				if (nLargest < k*j)
					nLargest = k*j;
			}
		}
	}

	printf("%d\n", nLargest);
}

void Problem9()
{
	for ( int a = 1; a <= 1000; a++ )
	{
		int aSquared = a*a;
		for ( int b = 1; b <= 1000; b++ )
		{
			int c = 1000 - a -b;
			if ( b*b + aSquared == c*c )
			{
				printf( "%d\n", a*b*c);
				break;
			}
		}
	}
	
	return;
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

void Problem12()
{
	bool found = false;
	int candidate = 7;
	int tnumber = 28;

	while ( !found )
	{
		/*
		int tnumber = 0;
		for ( int n = 1; n <= candidate; n++ )
		{
			tnumber += n;
		}
		*/

		// itself and one, plus ...
		int divisors = 2;
		for ( int n = 2; n <= tnumber/2; n++ )
		{
			if ( tnumber % n == 0 )
				divisors += 1;
		}

		printf("%d: %d\n", candidate, divisors );

		if ( divisors > 500 )
		{
			printf("Value is %d\n", tnumber);
			found = true;
		}

		candidate++;
		tnumber += candidate;
	}
}

int collatzSteps( int n )
{
	int steps = 1;
	__int64 worker = n;
	while ( worker > 1 )
	{
		printf( "%d: %lld\n", steps, worker);
		if ( worker%2 == 0 )
			worker = worker / 2;
		else
			worker = (3*worker) + 1;
		steps++;
	}

	return steps;
}


void Problem14()
{
	int longest = 0;
	int which = 0;
	for ( int n = 1; n < 1000000; n++ )
	{
		int steps = collatzSteps( n );
		if ( steps > longest )
		{
			longest = steps;
			which = n;
			printf( "%d: %d\n", which, steps );
		}
	}
}


void Problem16()
{
	const char sz[] = "1071508607186267320948425049060001810561404811705533607443750388370351"
"0511249361224931983788156958581275946729175531468251871452856923140435"
"9845775746985748039345677748242309854210746050623711418779541821530464"
"7498358194126739876755916554394607706291457119647768654216766042983165"
"2624386837205668069376";

	int nSum = 0;
	for ( const char *pstr = sz; *pstr != 0; pstr++ )
	{
		nSum += ( *pstr - '0' );
	}

	printf("%dn", nSum );
}



class TriangleTree{
public:

	TriangleTree( const char *pstr )
	{
		nElements = 0;
		for ( const char *pstrWalker = pstr; ; pstrWalker++)
		{
			if ( *pstrWalker == ' ' )
				nElements++;
			else if ( *pstrWalker == 0 )
			{
				nElements++;
				break;
			}
		}


	}

	int nLevels;
	int nElements;

};

class TreeNode {
public:
	int nValue;
	TreeNode *pLeft;
	TreeNode *pRight;
};

#define ELEMENTS(x) (sizeof(x) / sizeof(x[0]) )

void Problem18()
{
	const char sz[] = 
		"75 "
		"95 64 "
		"17 47 82 "
		"18 35 87 10 "
		"20 04 82 47 65 "
		"19 01 23 75 03 34 "
		"88 02 77 73 07 63 67 "
		"99 65 04 28 06 16 70 92 "
		"41 41 26 56 83 40 80 70 33 "
		"41 48 72 33 47 32 37 16 94 29 "
		"53 71 44 65 25 43 91 52 97 51 14 "
		"70 11 33 28 77 73 17 78 39 68 17 57 "
		"91 71 52 38 17 14 91 43 58 50 27 29 48 "
		"63 66 04 68 89 53 67 30 73 16 69 87 40 31 "
		"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

}

void Problem145()
{
	int nFound = 0;

	for ( int n = 1; n < 1000000000; n++ )
	{
		// if it ends in 0, it's not reversible
		if ( n % 10  == 0 )
			continue;

		// reverse it
		char sz[100];
		_itoa( n, sz, 10 );
		_strrev( sz );
		int r = atoi(sz);

		char szSum[100];
		_itoa( n + r, szSum, 10 );

		bool bReversible = true;
		for ( char *pstr = szSum; *pstr != 0; pstr++ )
		{
			if ( (*pstr & 1) == 0 )
			{
				bReversible = false;
				break;
			}
		}

		if ( bReversible )
		{
			++nFound;
			printf("%d: %d\n", nFound, n );
		}
	}

	printf("%d\n", nFound);

	return;
}


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
	bool bits[9] = { false, false, false, false, false, false, false, false, false };

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

	while ( 1 )
	{
		CFibo1M::add( *p3, *p1, *p2 );
		CFibo1M *pTemp = p1;
		p1 = p2;
		p2 = p3;
		p3 = pTemp;
		nTerm++;

		// number is in p1
		if ( p1->nLength < 9 )
			continue;
		/*
		if ( nTerm == 2749 )
			printf( "!\n" );

		if ( nTerm == 541 )
			printf("!\n");
		*/
		if ( nTerm == 329468 )
			printf("!\n");

		if ( !pandigital( p1->bDigits ) )
			continue;

		if ( pandigital( p1->bDigits + p1->nLength - 9 ) )
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


void Problem21()
{
	int nDivSum[10000];
	int nFound = 0;
	int nTotalSum = 0;

	for ( int n = 1; n < 10000; n++ )
	{
		nDivSum[n] = 1;
		for ( int d = 2; d < n; d++ )
		{
			if ( n % d == 0 ) nDivSum[n] += d;
		}
	}

	for ( int n = 0; n < 10000; n++ )
	{
		if ( nDivSum[n] != 0 && nDivSum[n] > n && nDivSum[n] < 10000 )
		{
			if ( n == nDivSum[nDivSum[n]] )
			{
				printf( "%d, %d\n", n, nDivSum[n] );
				nFound++;
				nTotalSum += n;
				nTotalSum += nDivSum[n];
			}
		}
	}

	printf("%d\n", nTotalSum);
}


long pow5( int n )
{
	return (long) n * (long) n * (long) n * (long) n * (long) n;
}


void Problem30()
{
	int nTotalSum = 0;

	for ( int n = 2; n < 10000000; n++ )
	{
		char sz[100];
		_itoa( n, sz, 10 );

		int nPowSum = 0;
		for ( char *pstr = sz; *pstr != 0; pstr++ )
		{
			nPowSum += pow5( *pstr - '0' );
		}

		if ( nPowSum == n )
		{
			printf("%d\n", n );
			nTotalSum += n;
		}
	}

	printf("%d\n", nTotalSum);
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
	// Problem104();
	// Problem34();

	// Problem21();
	// Problem30();


	// Incomplete
	// Problem205a();

	// Problem35();

	Problem37();

	}


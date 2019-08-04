// Euler104.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

bool pandigital(CFibo1M::byte *b)
{
	bool bits[9] = { false };

	for (int n = 0; n < 9; n++)
	{
		if (b[n] == 0)
			return false;
		if (b[n] > 9)
			printf("!\n");
		if (bits[b[n] - 1] == true)
			return false;
		bits[b[n] - 1] = true;
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


		if (first && last)
		{
			printf("answer = %d\n", nTerm);
			break;
		}
	}
}

int main()
{
	Problem104();
}

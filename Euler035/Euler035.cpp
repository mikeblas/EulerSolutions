// Euler035.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"


void Problem35()
{
	CSieve s(1200000);

	int nFound = 0;

	for (int n = 2; n < 1000000; n++)
	{
		if (!s.isPrime(n))
			continue;

		char szThis[15];
		_itoa_s(n, szThis, 10);
		size_t nLen = strlen(szThis);

		bool bAllPrime = true;

		for (size_t x = 1; x < nLen; x++)
		{
			char szRotated[15];
			memcpy(szRotated, szThis + x, nLen - x);
			memcpy(szRotated + nLen - x, szThis, x);
			szRotated[nLen] = 0;

			int nRotated = atoi(szRotated);
			if (!s.isPrime(nRotated))
			{
				bAllPrime = false;
				break;
			}
		}

		if (bAllPrime)
		{
			printf("%d\n", n);
			nFound++;
		}
	}

	printf(" Found %d\n", nFound);
}



int main()
{
	Problem35();
}

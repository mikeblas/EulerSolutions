// Euler037.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"



void Problem37()
{
	CSieve s(1200000);

	int nFound = 0;
	int nSum = 0;

	for (int n = 10; n < 1000000; n++)
	{
		if (!s.isPrime(n))
			continue;

		char szThis[15];
		_itoa_s(n, szThis, 10);
		size_t nLen = strlen(szThis);

		bool bAllPrime = true;

		for (size_t x = 1; x < nLen; x++)
		{
			int nCurrent = atoi(szThis + x);
			if (!s.isPrime(nCurrent))
			{
				bAllPrime = false;
				break;
			}
		}

		if (bAllPrime)
		{
			for (int x = (int)nLen - 1; x > 0; x--)
			{
				szThis[x] = 0;

				int nCurrent = atoi(szThis);
				if (!s.isPrime(nCurrent))
				{
					bAllPrime = false;
					break;
				}
			}
		}


		if (bAllPrime)
		{
			printf("%d\n", n);
			nFound++;
			nSum += n;
		}
	}

	printf("Sum is %d\n", nSum);
}


int main()
{
	Problem37();
}


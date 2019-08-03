// Euler145.cpp : Solution for problem #145 at Project Euler
//

#include "pch.h"


void Problem145()
{
	int nFound = 0;

	for (int n = 1; n < 1000000000; n++)
	{
		// if it ends in 0, it's not reversible
		if (n % 10 == 0)
			continue;

		// reverse it
		char sz[100];
		_itoa(n, sz, 10);
		_strrev(sz);
		int r = atoi(sz);

		char szSum[100];
		_itoa(n + r, szSum, 10);

		bool bReversible = true;
		for (char *pstr = szSum; *pstr != 0; pstr++)
		{
			if ((*pstr & 1) == 0)
			{
				bReversible = false;
				break;
			}
		}

		if (bReversible)
		{
			++nFound;
			printf("%d: %d\n", nFound, n);
		}
	}

	printf("%d\n", nFound);

	return;
}


int main()
{
	Problem145();
}


// Euler034.cpp : Soultion for problem #34 at Project Euler
//

#include "pch.h"


void Problem34()
{
	int factorials[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

	char sz[100];
	int nFound = 0;

	for (int n = 0; n < 1000000000; n++)
	{
		_itoa(n, sz, 10);
		bool bWorked = true;
		int nSum = 0;

		for (char *pstr = sz; *pstr != 0; pstr++)
		{
			nSum += factorials[*pstr - '0'];
			if (nSum > n)
			{
				bWorked = false;
				break;
			}
		}

		if (bWorked && nSum == n)
		{
			nFound++;
			printf("%d: %d\n", nFound, n);
		}
	}

	printf("%d\n", nFound);
}



int main()
{
	Problem34();
}

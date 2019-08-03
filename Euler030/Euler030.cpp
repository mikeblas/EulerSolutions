// Project030.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"



long pow5(int n)
{
	return (long)n * (long)n * (long)n * (long)n * (long)n;
}


void Problem30()
{
	int nTotalSum = 0;

	for (int n = 2; n < 10000000; n++)
	{
		char sz[100];
		_itoa(n, sz, 10);

		int nPowSum = 0;
		for (char *pstr = sz; *pstr != 0; pstr++)
		{
			nPowSum += pow5(*pstr - '0');
		}

		if (nPowSum == n)
		{
			printf("%d\n", n);
			nTotalSum += n;
		}
	}

	printf("%d\n", nTotalSum);
}

int main()
{
	Problem30();
}

// Euler021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"


void Problem21()
{
	int nDivSum[10000];
	int nFound = 0;
	int nTotalSum = 0;

	for (int n = 1; n < 10000; n++)
	{
		nDivSum[n] = 1;
		for (int d = 2; d < n; d++)
		{
			if (n % d == 0) nDivSum[n] += d;
		}
	}

	for (int n = 0; n < 10000; n++)
	{
		if (nDivSum[n] != 0 && nDivSum[n] > n && nDivSum[n] < 10000)
		{
			if (n == nDivSum[nDivSum[n]])
			{
				printf("%d, %d\n", n, nDivSum[n]);
				nFound++;
				nTotalSum += n;
				nTotalSum += nDivSum[n];
			}
		}
	}

	printf("%d\n", nTotalSum);
}




int main()
{
	Problem21();
}


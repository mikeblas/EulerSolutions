// Euler010.cpp : Solution to Project Euler problem 10
//
// Brute force -- so this runs for a while.
//

#include "pch.h"

void Problem10()
{
	__int64 sum = 2;
	int candidate = 3;


	while (1)
	{
		bool isPrime = true;

		for (int nDivisor = 2; nDivisor < candidate / 2; nDivisor++)
		{
			if (candidate % nDivisor == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			if (candidate >= 2000000)
				break;
			sum += candidate;
		}

		candidate += 2;
	}

	printf("%lld\n", sum);
}

int main()
{
	Problem10();
}

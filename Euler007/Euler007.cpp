// Euler007.cpp : Solution for Project Euler problem #7
//

#include "pch.h"

void Problem7()
{
	int candidate = 3;
	int primeCount = 1;


	while (primeCount < 10001)
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
			primeCount++;
			printf("%d, %d\n", primeCount, candidate);
		}

		candidate += 2;
	}
}


int main()
{
	Problem7();
}


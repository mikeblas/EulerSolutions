// Euler014.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"


int collatzSteps(int n)
{
	int steps = 1;
	__int64 worker = n;
	while (worker > 1)
	{
		printf("%d: %lld\n", steps, worker);
		if (worker % 2 == 0)
			worker = worker / 2;
		else
			worker = (3 * worker) + 1;
		steps++;
	}

	return steps;
}


void Problem14()
{
	int longest = 0;
	int which = 0;
	for (int n = 1; n < 1000000; n++)
	{
		int steps = collatzSteps(n);
		if (steps > longest)
		{
			longest = steps;
			which = n;
			printf("%d: %d\n", which, steps);
		}
	}
}


int main()
{
	Problem14();

}


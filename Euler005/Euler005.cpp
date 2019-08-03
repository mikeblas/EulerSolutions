// Euler005.cpp : solution for Problem 5 at Project Euler
//

#include "pch.h"


void Problem5()
{
	int candidate = 20;
	for (bool satisfied = false; !satisfied; candidate += 2)
	{
		satisfied = true;
		for (int n = 2; n <= 20; n++)
		{
			if (candidate % n != 0)
			{
				satisfied = false;
				break;
			}
		}

		if (satisfied)
			printf("%d\n", candidate);
	}

}

int main()
{
	Problem5();

}

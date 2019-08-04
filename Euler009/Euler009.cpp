// Euler009.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"



void Problem9()
{
	for (int a = 1; a <= 1000; a++)
	{
		int aSquared = a * a;
		for (int b = 1; b <= 1000; b++)
		{
			int c = 1000 - a - b;
			if (b*b + aSquared == c * c)
			{
				printf("%d\n", a*b*c);
				break;
			}
		}
	}

	return;
}
int main()
{
	Problem9();
}


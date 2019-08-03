// Euler006.cpp : Solution for Project Euler problem #6
//

#include "pch.h"
#include <iostream>


void Problem6()
{
	int sum = 0;
	int squares = 0;

	for (int n = 1; n <= 100; n++)
	{
		sum += n;
		squares += (n * n);
	}

	printf("square of sums = %d\n", sum * sum);
	printf("Sum of squares = %d\n", squares);
	printf("diff = %d\n", (sum * sum) - squares);
}

int main()
{
	Problem6();
}

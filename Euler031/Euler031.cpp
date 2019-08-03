// Euler031.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


void Problem31()
{
	int ways = 1;

	for (int p = 0; p <= 200; p++)
	{
		for (int t = 0; t <= 100; t++)
		{
			printf("%d\n", ways);
			for (int n = 0; n <= 40; n++)
			{
				for (int d = 0; d <= 20; d++)
				{
					for (int dd = 0; dd <= 10; dd++)
					{
						for (int h = 0; h <= 4; h++)
						{
							for (int ps1 = 0; ps1 <= 2; ps1++)
							{
								int total = p + t * 2 + n * 5 + d * 10 + dd * 20 + h * 50 + ps1 * 100;
								if (total == 200)
									ways++;
							}
						}
					}
				}
			}
		}
	}

	printf("%d\n", ways);
}




int main()
{
	Problem31();
}

// Euler033.cpp : A solution for Euler Problem #33


#include "pch.h"
#include <iostream>

int main()
{
	int nProd = 1;
	int dProd = 1;

	for (int n1 = 1; n1 <= 9; n1++)
	{
		for (int n2 = 1; n2 <= 9; n2++)
		{
			if (n1 == n2)
				continue;

			double n = n1 * 10 + n2;

			for (int d1 = 1; d1 <= 9; d1++)
			{
				for (int d2 = 1; d2 <= 9; d2++)
				{
					if (d1 == d2)
						continue;

					double d = d1 * 10 + d2;

					if (n >= d)
						continue;

					if (d1 == n2)
					{
						double t = n1 / (double)d2;
						if (t == n / d)
						{
							printf("%d%d / %d%d\n", n1, n2, d1, d2);
							nProd *= (n1 * 10 + n2);
							dProd *= (d1 * 10 + d2);
						}
					}
					else if (n1 == d2)
					{
						double t = n2 / (double)d1;
						if (t == n / d)
						{
							printf("%d%d / %d%d\n", n1, n2, d1, d2);
							nProd *= (n1 * 10 + n2);
							dProd *= (d1 * 10 + d2);
						}
					}
				}
			}
		}
	}

	printf("%d\n", nProd);
	printf("%d\n", dProd);
}

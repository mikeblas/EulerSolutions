// Euler004.cpp : solution to Project Euler problem #4
//

#include "pch.h"


bool isPalindrome(const char *pstr)
{
	const char *pstrFirst = pstr;
	const char *pstrLast = pstr;
	while (pstrLast[1] != 0)
		pstrLast++;

	while (pstrFirst <= pstrLast)
	{
		if (*pstrFirst != *pstrLast)
			return false;
		pstrFirst++;
		pstrLast--;
	}

	return true;
}


void Problem4()
{
	char sz[100];
	int nLargest = 0;

	for (int k = 100; k <= 999; k++)
	{
		for (int j = 100; j <= 999; j++)
		{
			_itoa(k*j, sz, 10);
			if (isPalindrome(sz))
			{
				if (nLargest < k*j)
					nLargest = k * j;
			}
		}
	}

	printf("%d\n", nLargest);
}

int main()
{
	Problem4();
}


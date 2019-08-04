// Euler020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"


void Problem20()
{
	CFibo2K f1;
	CFibo2K f2;
	CFibo2K f3;

	CFibo2K *p1 = &f1;
	CFibo2K *p2 = &f2;
	CFibo2K *p3 = &f3;

	p1->set(1);
	for (int n = 1; n <= 100; n++)
	{
		p2->set(n);
		CFibo2K::multiply(*p3, *p1, *p2);

		CFibo2K *pTemp = p1;
		p1 = p3;
		p3 = pTemp;
	}

	int nSum = 0;

	for (int n = 0; n < p1->nLength; n++)
	{
		nSum += p1->bDigits[n];
	}

	printf("%d\n", nSum);
}



int main()
{
    std::cout << "Hello World!\n"; 
}

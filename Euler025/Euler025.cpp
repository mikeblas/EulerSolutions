// Euler025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

void Problem25()
{
	CFibo2K f1; CFibo2K f2; CFibo2K f3;
	CFibo2K *p1 = &f1;
	CFibo2K *p2 = &f2;
	CFibo2K *p3 = &f3;

	f1.set(1);
	f2.set(1);
	int nTerm = 1;

	while (p1->nLength < 1000)
	{
		CFibo2K::add(*p3, *p1, *p2);
		CFibo2K *pTemp = p1;
		p1 = p2;
		p2 = p3;
		p3 = pTemp;

		nTerm++;
	}

	printf("%d\n", nTerm);
}


int main()
{
	Problem25();
}

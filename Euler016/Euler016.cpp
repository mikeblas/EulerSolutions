// Euler016.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

void Problem16()
{
	const char sz[] =
		"1071508607186267320948425049060001810561404811705533607443750388370351"
		"0511249361224931983788156958581275946729175531468251871452856923140435"
		"9845775746985748039345677748242309854210746050623711418779541821530464"
		"7498358194126739876755916554394607706291457119647768654216766042983165"
		"2624386837205668069376";

	int nSum = 0;
	for (const char *pstr = sz; *pstr != 0; pstr++)
	{
		nSum += (*pstr - '0');
	}

	printf("%dn", nSum);
}

int main()
{
	Problem16();

}
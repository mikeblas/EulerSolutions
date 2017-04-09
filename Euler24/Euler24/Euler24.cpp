// Euler24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	char numerals[] = "0123456789";
	size_t len = strlen(numerals);

	int n = 1;
	do {

		string s(numerals);
		// printf("%s\n", numerals);

		if (n++ == 1000000) {
			printf("%s\n", numerals);
			break;
		}

	} while (next_permutation(numerals, numerals + len));

    return 0;
}


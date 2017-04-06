// Euler36.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



bool isPalindrome(const char *pstr) {

	size_t len = strlen(pstr);
	size_t front = 0;
	size_t back = len - 1;

	while (front < back) {
		if (pstr[front] != pstr[back]) {
			return false;
		}
		front++;
		back--;
	}

	return true;
}

int main()
{
	int sum = 0;

	for (int n = 1; n < 1000000; n++) {

		char sz10[100];
		_itoa(n, sz10, 10);

		if (isPalindrome(sz10)) {
			char sz2[100];
			_itoa(n, sz2, 2);

			if (isPalindrome(sz2)) {
				printf("%s (%s)\n", sz10, sz2);
				sum += n;
			}
		}
	}

	printf("Sum is %d\n", sum);

    return 0;
}


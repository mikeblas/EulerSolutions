// Euler63.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*

First attempt was to simply evaluate powers and count digits. This falls over
for __uint64, which is limited to 2**64, something like 1.8 * 10**19. Around
9**20 or 9**21, we can't continue evaluating candidates because it's a greater
quantity than can be represented in __uint64.

Turns out we can use a logrithm identity to evaluate the number of digits in
the power:

	digits = 1 + floor(power * log10(base) );

This is far simplier, a bunch faster, and just as accurate.

*/

set<__int64> matches;

void method1() {

	int count = 0;

	for (int n = 1; n <= 20; n++) {

		char sz[35];

		long base = 1;
		while (true) {

			unsigned __int64 power = base;
			for (int raise = 2; raise <= n; raise++) {
				power *= base;
			}

			// printf("%d ^ %d == %d\n", base, n, power);

			_ui64toa(power, sz, 10);

			int len = strlen(sz);

			if (len == n) {
				matches.insert(power);
				printf("%d ^ %d == %lld\n", base, n, power);
				count++;
			}
			else if (len > n) {
				printf("too long: %lld = %d ^ %d\n", power, base, n);
				break;
			}
			base++;

		}

	}

	printf("%d\n", matches.size());
	printf("count is %d\n", count);
}


int main()
{
	
	int count = 0;
	for (int power = 1; power < 25; power++) {
		for (int base = 1; base < 100; base++) {

			int digits = 1 + (power * log10(base));
			printf("%d ^ %d == %d digits\n", base, power, digits);
			if (digits == power) {
				count++;
			}
			else if (digits > power) {
				break;
			}
		}
	}

	printf("count == %d\n", count);
	return 0;
}



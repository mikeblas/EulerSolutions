// Euler23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int findDivisors(int n) {

	int limit = n/2;

	// printf("%d: 1 ", n);
	int sum = 1;

	for (int d = 2; d <= limit; d++) {
		if (n % d == 0) {
			// printf("%d ", d);
			sum += d;
		}
	}

	// printf("\n");

	return sum;
}

set<int> abundantSet;

int main()
{
	// populate
	for (int n = 1; n <= 30000; n++) {

		int sum = findDivisors(n);
		if (sum > n) {
			// printf("%d %d\n", n, sum);
			abundantSet.insert(n);
		}
	}

	long totalSum = 0;

	for (int n = 1; n < 28123; n++) {

		bool solved = false;
		for (int a : abundantSet) {
			if (a > n) break;
			set<int>::const_iterator iter = abundantSet.find(n - a);
			if (iter != abundantSet.end()) {
				// printf("%d + %d = %d\n", a, *iter, n);
				solved = true;
				break;
			}
		}

		if (!solved) {
			printf("couldn't find %d\n", n);
			totalSum += n;
		}
	}

	printf("totalSum = %d\n", totalSum);

    return 0;
}


// Euler95.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct SumInfo {

	int divisorSum;
	int chainLength;

	SumInfo() {
	}

	SumInfo(int divisorSum)
		: divisorSum(divisorSum),
		chainLength(-1) {
	}

};


unordered_map<int, SumInfo> numberSums;

int findDivisors(int n) {

	int limit = (int)sqrt((double)n);

	// printf("%d: 1 ", n);
	int sum = 1;

	for (int d = 2; d <= limit; d++) {
		if (n % d == 0) {
			// printf("%d ", d);
			sum += d;
			sum += (n / d);
		}
	}

	// printf("\n");

	return sum;
}

int findLength(int n, bool show) {

	unordered_set<int> found;

	int next = n;
	int totalFound = 0;
	while (true) {

		unordered_map<int, SumInfo>::const_iterator iter = numberSums.find(next);
		if (iter == numberSums.end()) {
			break;
		}

		int temp = iter->second.divisorSum;
		if (show) {
			printf("%d -> %d\n", next, temp);
		}

		if (temp == 1 || temp > 1000000) {
			return 0;
		}

		if (temp == n) {
			break;
		}

		if (found.find(temp) == found.end()) {
			found.insert(temp);
			next = temp;
			totalFound++;
		}
		else {
			if (show) {
				printf("%d already found\n", temp);
			}
			return 0;
		}
	}

	if (show) {
		printf("%d\n", totalFound);
	}
	return totalFound;
}


int findLength(int n) {
	return findLength(n, false);
}

int main()
{

	findDivisors(28);

	printf("Sum = %d\n", findDivisors(220));
	printf("Sum = %d\n", findDivisors(284));

	// populate
	for (int n = 1; n <= 1000000; n++) {
		int sum = findDivisors(n);
			SumInfo si(sum);
		numberSums[n] = si;
		if (n % 10000 == 0) {
			printf("%d ... ", n);
		}
	}
	printf("\n");

	// test example value
	findLength(12496, true);

	// search for longest
	int longest = -1;
	int longestAt;

	for (int n = 1; n <= 1000000; n++) {
		int length = findLength(n);
		if (length > longest) {
			longestAt = n;
			longest = length;
		}
		if (n % 10000 == 0) {
			printf("%d ... ", n);
		}
	}
	printf("\n");

	printf("longest = %d, at = %d\n", longest, longestAt);
	findLength(longestAt, true);

    return 0;
}


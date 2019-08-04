// Euler46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

set<long> primes;

void populatePrimes(long max) {

	primes.insert(2);
	primes.insert(3);

	for (long candidate = 5; candidate < max; candidate += 2) {
		long limit = (long) sqrt(candidate);
		bool prime = true;
		for (long divisor = 3; divisor <= limit; divisor += 2) {
			if (candidate % divisor == 0) {
				prime = false;
				break;
			}
		}

		if (prime) {
			primes.insert(candidate);
		}
	}
}

bool isPrime(long candidate) {
	
	auto iter = primes.find(candidate);
	return (iter != primes.end());
}

int main()
{
	populatePrimes(100000);

	for (long candidate = 5; candidate < 1000000L; candidate += 2) {

		// only consider composites
		if (isPrime(candidate)) {
			// printf("Skipping %d\n", candidate);
			continue;
		}

		bool solved = false;

		for (long square = 1; square < 10000; square++) {

			long squared = square*square * 2;
			long difference = candidate - squared;
			if (difference <= 0) {
				break;
			}

			if (isPrime(difference)) {
				solved = true;

				printf("%d == %d + 2 * %d ^2\n", candidate, difference, square);
				break;
			}
		}

		if (!solved) {
			printf("%d not solved!\n", candidate);
			break;
		}
	}

    return 0;
}


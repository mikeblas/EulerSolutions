// Euler58.cpp : Defines the entry point for the console application.
//


/*
First attepmt was to build the spiral, since I had code to do that from a previous
exercise. But then I noticed that it took a while, since my spiral code was'nt in
any condition to add another row.  And the vast majoriy of the work in building
the spiral wasn't necessary, since only the corner numbers are different for
each additional ring.

It's easy to come up with a formula for the corner numbers. In doing so, we notice
the bottom right number is always a square and therefore never prime. We can
test the three values and accumulate a count of prime and not prime values,
then check to see if we've fallen under the threhhold.

*/

#include "stdafx.h"

bool isPrime(__int64 candidate) {

	if (candidate == 2 || candidate == 3) {
		return true;
	}
	if (candidate < 2) {
		return false;
	}
	if (candidate % 2 == 0) {
		return false;
	}

	__int64 limit = 1 + sqrt(candidate);

	for (__int64 divisor = 3; divisor <= limit; divisor += 2) {
		if (candidate % divisor == 0) {
			return false;
		}
	}

	// printf("%I64d is prime\n", candidate);
	return true;
}


int main()
{
	int size = 3;
	int prime = 0;
	int notPrime = 1;		// #1 at the center counts only once ,and is not prime

	while (true) {

		// figure out each of the corners
		__int64 bottomRight = size*(__int64)size;
		__int64 bottomLeft = bottomRight - size + 1;
		__int64 topLeft = bottomLeft - size + 1;
		__int64 topRight = topLeft - size + 1;

		// bottom right is never prime
		notPrime += 1;

		if (isPrime(bottomLeft)) {
			prime++;
		}
		else {
			notPrime++;
		}

		if (isPrime(topLeft)) {
			prime++;
		}
		else {
			notPrime++;
		}

		if (isPrime(topRight)) {
			prime++;
		}
		else {
			notPrime++;
		}

		double ratio = prime / (double)(prime + notPrime);
		if (ratio < 0.10) {
			printf("size: %d, prime = %d, not prime = %d, ratio = %3.6f\n", size, prime, notPrime, ratio);
			break;
		}

		/*
		if (size > 46953) {
			printf("size == %d, bottomRight = %d\n", size, bottomRight);
		}
		*/

		if (size % 333 == 0) {
			printf("size: %d, prime = %d, not prime = %d, ratio = %3.6f\n",
				size, prime, notPrime, ratio);
		}

		size += 2;
	}


    return 0;
}


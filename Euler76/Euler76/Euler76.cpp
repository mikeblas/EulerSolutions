// Euler76.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#define LIMIT 100

int main()
{
	int iterations = 0;
	long ways[LIMIT+1];
	for (int n = 0; n <= LIMIT; n++) {
		ways[n] = 0;
	}
	ways[0] = 1;

	for (int populate = 1; populate <= LIMIT - 1; populate++) {
		for (int enumerate = populate; enumerate <= LIMIT; enumerate++) {
			// printf("w[%d] += w[%d]\n", enumerate, enumerate - populate);
			iterations++;
			ways[enumerate] += ways[enumerate - populate];
		}
	}

	/*
	for (int n = 0; n <= LIMIT; n++) {
		printf("w[%d] = %d\n", n, ways[n]);
	}
	*/

	printf("%d iterations\n", iterations);
	printf("%d\n", ways[LIMIT]);

    return 0;
}


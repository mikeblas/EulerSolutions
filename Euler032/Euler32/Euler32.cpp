// Euler32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



bool usable(const char *pstr) {
	bool each[10] = { false };

	for (const char *walker = pstr; *walker != '\0'; walker++) {
		if (*walker == '0') {
			return false;
		}

		int index = *walker - '0';
		if (each[index]) {
			return false;
		}
		each[index] = true;
	}

	return true;
}

bool test(const char *a, long b, long c) {

	bool each[10] = { false };

	char szB[20];
	char szC[20];

	_ltoa(b, szB, 10);
	_ltoa(c, szC, 10);

	const char *pstr[3] = { a, szB, szC };

	for (int n = 0; n < 3; n++) {

		for (const char *walker = pstr[n]; *walker != '\0'; walker++) {
			if (*walker == '0') {
				return false;
			}

			int index = *walker - '0';
			if (each[index]) {
				return false;
			}
			each[index] = true;

		}
	}

	return true;
}


void partition(char *pstr, int one, int two, long &a, long &b, long &c) {
	
	a = b = c = 0;

	int index = 0;
	for (; index < one; index++) {
		a = (a * 10) + (pstr[index] - '0');
	}

	for (; index < two + one; index++) {
		b = (b * 10) + (pstr[index] - '0');
	}

	for (; index < 9; index++) {
		c = (c * 10) + (pstr[index] - '0');
	}
}


int count = 0;
int matching = 0;

std::set<long> sets;

long sum = 0;

void evaluate(char *pstr) {

//	printf("%s\n", pstr);
	count++;

	// 1234567,8,9

	for (int one = 1; one < 7; one++) {
		for (int two = 1; two < 8 - one; two++) {

			long a;
			long b;
			long c;
			partition(pstr, one, two, a, b, c);
			
			if (a < b) {
				if (a * b == c) {
					printf("%d * %d = %d\n", a, b, c);
					sets.insert(c);
				}
			}
		}
	}

}

void swap(char *pstr, int one, int other) {
	char temp = pstr[one];
	pstr[one] = pstr[other];
	pstr[other] = temp;
}


void permute(char *pstr, int left, int right) {

	if (left == right) {
		evaluate(pstr);
	}
	else {
		for (int index = left; index <= right; index++) {
			swap(pstr, left, index);
			permute(pstr, left + 1, right);
			swap(pstr, left, index);
		}
	}
}


int main()
{

	char sz[] = "123456789";
	permute(sz, 0, 8);

	/*
	char sz[] = "ABC";
	permute(sz, 0, 2);
	*/

	printf("Count is %d\n", count);

	for (long member : sets) {
		sum += member;
	}
	printf("Sum is %d\n", sum);

    return 0;
}


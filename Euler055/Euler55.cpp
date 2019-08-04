// Euler55.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class BigNumber {
private:
	__int8 * pb;
	int length;
	int usedLength;

public:
	BigNumber(int n) {
		length = n;
		usedLength = 1;
		pb = new __int8[n];
		for (int x = 0; x < n; x++) {
			pb[x] = 0;
		}
	}

	BigNumber(BigNumber &other) {
		length = other.length;
		usedLength = other.usedLength;
		pb = new __int8[length];
		memcpy(pb, other.pb, length);
	}

	~BigNumber() {
		delete[] pb;
	 }

public:
	static BigNumber zeroWithLength(int n) {
		BigNumber bn(n);
		return n;
	}

	static BigNumber zero() {
		return zeroWithLength(2);
	}

	static BigNumber fromInteger(__int64 n) {

		unsigned char sz[22];
		if (n == 0) {
			return zero();
		}

		int index = 0;
		while (n > 0) {
			sz[index++] = n % 10;
			n /= 10;
		}

		BigNumber bn(index);
		bn.usedLength = index;

		for (int place = 0; place < index; place++) {
			bn.pb[place] = sz[place];
		}

		return bn;
	}

	bool isPalindrome() const {

		int left = 0;
		int right = usedLength - 1;
		while (left < right) {
			if (pb[left] != pb[right]) {
				return false;
			}
			left++;
			right--;
		}

		return true;
	}

	void selfAddReverse() {

		__int8 * result = new __int8[usedLength + 1];

		bool carry = false;
		for (int index = 0; index < usedLength; index++) {
			result[index] = pb[index] + pb[usedLength - index -1];
			if (carry) result[index]++;
			if (result[index] >= 10) {
				carry = true;
				result[index] -= 10;
			}
			else {
				carry = false;
			}
		}

		if (carry) {
			result[usedLength] = 1;
		}

		delete[] pb;

		pb = result;
		length = usedLength + 1;
		usedLength = carry ? (usedLength + 1) : usedLength;
	}

	string toString() {

		char * sz = new char[usedLength + 1];
		for (int n = 0; n < usedLength; n++) {
			sz[usedLength - n -1] = pb[n] + '0';
		}
		sz[usedLength] = '\0';

		return string(sz);
	}

};

void tests() {
	BigNumber b1 = BigNumber::zero();
	printf("%s, %d\n", b1.toString().c_str(), b1.isPalindrome());

	BigNumber b2 = BigNumber::fromInteger(735);
	printf("%s, %d\n", b2.toString().c_str(), b2.isPalindrome());

	BigNumber b3 = BigNumber::fromInteger(1441);
	printf("%s, %d\n", b3.toString().c_str(), b3.isPalindrome());

	BigNumber b4 = BigNumber::fromInteger(14541);
	printf("%s, %d\n", b4.toString().c_str(), b4.isPalindrome());

	b4.selfAddReverse();
	printf("%s, %d\n", b4.toString().c_str(), b4.isPalindrome());

	BigNumber b5 = BigNumber::fromInteger(349);
	printf("%s, %d\n", b5.toString().c_str(), b5.isPalindrome());
	b5.selfAddReverse();
	printf("%s, %d\n", b5.toString().c_str(), b5.isPalindrome());
	b5.selfAddReverse();
	printf("%s, %d\n", b5.toString().c_str(), b5.isPalindrome());
	b5.selfAddReverse();
	printf("%s, %d\n", b5.toString().c_str(), b5.isPalindrome());
	b5.selfAddReverse();


}


int main()
{
	int foundCount = 0;

	for (int candidate = 1; candidate < 10000; candidate++) {

		int iterations = 0;
		bool found = false;
		BigNumber bnCandidate = BigNumber::fromInteger(candidate);
		while (iterations <= 50) {

			iterations++;
			bnCandidate.selfAddReverse();
			if (bnCandidate.isPalindrome()) {
				found = true;
				break;
			}
		}

		if (!found) {
			foundCount++;
			printf("%d is Lychel\n", candidate);
		}
	}

	printf("found count is %d\n", foundCount);

    return 0;
}


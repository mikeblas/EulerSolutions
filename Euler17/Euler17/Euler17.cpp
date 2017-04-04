// Euler17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class BoundsException {
	string function;
	int value;

public:
	BoundsException(char* function, int n)
	: function(function), value(n) {
		printf("BoundsException: %s, %d\n", function, n);
	}
};

int unitLength(int n) {

	assert(n >= 0);
	assert(n <= 10);

	switch (n) {
	case 0: return 0;
	case 1: return 3;
	case 2: return 3;
	case 3: return 5;
	case 4: return 4;
	case 5: return 4;
	case 6: return 3;
	case 7: return 5;
	case 8: return 5;
	case 9: return 4;
	case 10: return 3;
	}

	throw new BoundsException("unitLength", n);
}

int teenLength(int n) {

	assert(n < 20);
	assert(n > 10);
	switch(n) {
	case 11: return 6; // eleven
	case 12: return 6; // twelve
	case 13: return 8; // thirteen
	case 14: return 8; // fourteen
	case 15: return 7; // fifteen
	case 16: return 7; // sixteen
	case 17: return 9; // seventeen
	case 18: return 8; // eighteen
	case 19: return 8; // nineteen
	}

	throw new BoundsException("teenLength", n);
}

int decadeLength(int n) {
	assert(n >= 20);
	assert(n <= 100);

	int total = unitLength(n % 10);
	switch (n / 10) {
	case 2: total += 6; break; // twenty
	case 3: total += 6; break; // thirty
	case 4: total += 5; break; // forty
	case 5: total += 5; break; // fifty
	case 6: total += 5; break; // sixty
	case 7: total += 7; break; // seventy
	case 8: total += 6; break; // eighty
	case 9: total += 6; break; // ninety
	}

	return total;
}


int charactersForNumber(int n) {

	if (n == 1000) {
		return 11; // one thousand
	}

	if (n <= 10) {
		return unitLength(n);
	}
	if (n > 10 && n < 20) {
		return teenLength(n);
	}

	if (n < 100) {
		return decadeLength(n);
	}

	if (n >= 100) {
		int total = unitLength(n / 100);
		total += 7; //  "hundred"
		int next = n % 100;
		if (next != 0) {
			total += 3; // "and"
			total += charactersForNumber(n % 100);
		}
		return total;
	}

	throw new BoundsException("charactersForNumbers", n);
}


const char* unitNames[] = {
	"zero", 
	"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
	"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const char* tensNames[] = {
	"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

string makeString(int n) {
	if (n >= 1000) {
		string temp = makeString(n / 1000) + " thousand";
		int next = n % 1000;
		if (next == 0) {
			return temp;
		}
		else {
			return temp + " and " + makeString(next);
		}
	}
	else if (n >= 100) {
		string temp(unitNames[n / 100]);
		temp.append(" hundred");
		int next = n % 100;
		if (next == 0) {
			return temp;
		}
		else {
			return temp + " and " + makeString(next);
		}
	}
	else if (n >= 20) {
		string temp(tensNames[n / 10]);
		int next = n % 10;
		if (next == 0) {
			return temp;
		}
		else {
			string s = temp + "-" + makeString(next);
			return s;
		}
	}
	else {
		return string(unitNames[n]);
	}


}

int simpleLength(string str) {
	int count = 0;
	for (unsigned int n = 0; n < str.length(); n++) {
		if (str[n] >= 'a' && str[n] <= 'z') {
			count++;
		}
	}

	return count;
}

int charactersForNumber2(int n) {
	string s = makeString(n);
//	printf("%d = %s\n", n, s.c_str());
	return simpleLength(s);
}


int main()
{
	printf("45 = %d\n", charactersForNumber(45));
	printf("115 = %d\n", charactersForNumber(115));
	printf("342 = %d\n", charactersForNumber(342));

	printf("45 = %d\n", charactersForNumber2(45));
	printf("115 = %d\n", charactersForNumber2(115));
	printf("342 = %d\n", charactersForNumber2(342));

	for (int n = 1; n <= 1000; n++) {
		int one = charactersForNumber(n);
		int two = charactersForNumber2(n);
		if (one != two) {
			printf("at %d, %d != %d (%s)\n", n, one, two, makeString(n).c_str());
		}
	}

	int grandTotal = 0;
	for (int n = 1; n <= 5; n++) {
		grandTotal += charactersForNumber(n);
	}
	printf("%d\n", grandTotal);

	grandTotal = 0;

	for (int n = 1; n <= 1000; n++) {
		grandTotal += charactersForNumber(n);
	}
	printf("method1: %d\n", grandTotal);

	grandTotal = 0;

	for (int n = 1; n <= 1000; n++) {
		grandTotal += charactersForNumber2(n);
	}
	printf("method2: %d\n", grandTotal);

    return 0;
}


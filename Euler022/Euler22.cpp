// Euler22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


vector<string> names;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("Usage: euler22 <file_name>\n");
		return 1;
	}

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("couldn't open %s\n", argv[1]);
		return 1;
	}
	char sz[1000];
	int index = 0;
	char c;
	while (EOF != (c = fgetc(f))) {
		
		if (c == '"') continue;
		if (c == ',') {
			sz[index] = 0;
			string s(sz);
			names.push_back(s);
			index = 0;
		}
		else {
			sz[index++] = c;
		}
	}

	if (index != 0) {
		sz[index] = 0;
		string s(sz);
		names.push_back(s);

	}

	fclose(f);

	printf("%lld\n", names.size());

	sort(names.begin(), names.end());

	long long totalScore = 0;

	for (size_t n = 0; n < names.size(); n++) {

		if (n == 938-1) {
			printf("%s\n", names.at(n).c_str());
		}
		int score = 0;
		for (size_t m = 0; m < names.at(n).size(); m++) {
			char c = names.at(n).at(m);
			if (c >= 'A' && c <= 'Z') {
				score += c - 'A' + 1;
			}
		}

		totalScore += score * (n + 1);
	}

	printf("%lld\n", totalScore);


}



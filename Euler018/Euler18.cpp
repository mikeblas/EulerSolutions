// Euler18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
 
/*
   0
  0 1
 0 1 2
0 1 2 3
*/

class Cell {
	int value;
	int accumulatedValue;

public:
	Cell(int value) :
	value(value),
	accumulatedValue(0) {
	}

	int getValue() const {
		return value;
	}

	int getAccumulatedValue() const {
		return accumulatedValue;
	}

	void setAccumulatedValue(int n) {
		accumulatedValue = n;
	}
};

class Line {
	vector<Cell> v;

public:
	Line(const char* pstr) {

		int current = 0;
		bool inNumber = false;
		for (const char* walker = pstr; *walker != '\0'; walker++) {
			if (*walker >= '0' && *walker <= '9') {
				current *= 10;
				current += (*walker - '0');
				inNumber = true;
			}
			else {
				if (inNumber) {
					Cell cell(current);

					v.push_back(cell);
					current = 0;
					inNumber = false;
				}
			}

		}
	}

	size_t size() const {
		return v.size();
	}

	Cell & get(int index) {
		return v.at(index);
	}

	void print() {
		for (size_t n = 0; n < v.size(); n++) {
			printf("%d(%d) ", v.at(n).getValue(), v.at(n).getAccumulatedValue());
		}
		printf("\n");
	}
};

vector<Line> lines;
int calls = 0;

int traverseAll(int row, int index) {

	calls++;

	// printf("%d, %d, %d\n", row, index, lines.size());
	if (row == lines.size() - 1) {
		return lines[row].get(index).getValue();
	}

	int leftSum = lines[row].get(index).getValue() + traverseAll(row + 1, index);
	int rightSum = 0;
	rightSum = lines[row].get(index).getValue() + traverseAll(row + 1, index + 1);

	return (leftSum > rightSum) ? leftSum : rightSum;
}

void method1() {
	int result = traverseAll(0, 0);
	printf("%d\n", result);
	printf("%d calls\n", calls);
}


void dumpLines() {
	for (size_t n = 0; n < lines.size(); n++) {
		lines[n].print();
	}
}

void method2() {


	for (int v = 0; v < lines.at(lines.size() - 1).size(); v++) {
		lines.at(lines.size() - 1).get(v).setAccumulatedValue(
			lines.at(lines.size() - 1).get(v).getValue());
	}

	dumpLines();
	
	for (int n = (int)lines.size() - 2; n >= 0; n--) {

		/*
		printf("%d: size = %d, next size = %d\n", n, lines.at(n).size(),
			lines.at(n + 1).size());
		*/

		Line & thisLine = lines.at(n);

		for (int v = 0; v < thisLine.size(); v++) {

			Line & nextLine = lines.at(n + 1);
			int left = nextLine.get(v).getAccumulatedValue();
			int right = nextLine.get(v + 1).getAccumulatedValue();
			int accumulate = thisLine.get(v).getValue();

			if (left > right) {
				// printf("%d + %d\n", accumulate, left);
				accumulate += left;
			}
			else {
				// printf("%d + %d\n", accumulate, right);
				accumulate += right;
			}

			thisLine.get(v).setAccumulatedValue(accumulate);

		}
		// dumpLines();
	}

	printf("Result is %d\n", lines.at(0).get(0).getAccumulatedValue());
}


int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("Usage: euler18 <file_name>\n");
		return 1;
	}

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("couldn't open %s\n", argv[1]);
		return 1;
	}
	char sz[1000];
	while (fgets(sz, sizeof(sz), f) != NULL) {
		
		Line line(sz);
		if (line.size() > 0) {
			lines.push_back(line);
		}
	}
	fclose(f);

	/*
	for (size_t n = 0; n < lines.size(); n++) {
		lines[n].print();
	}
	*/
	printf("%lld lines read\n", lines.size());

	method2();

    return 0;
}


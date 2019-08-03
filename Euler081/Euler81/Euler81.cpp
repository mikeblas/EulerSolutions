// Euler81.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


vector<long> readLine(const char* pstr) {

	vector<long> row;

	bool inNumber = true;
	long current = 0;
	for (const char* walker = pstr; *walker != '\0'; walker++) {
	
		if (inNumber) {
			if (*walker <= '9' && *walker >= '0') {
				current *= 10;
				current += *walker - '0';
			}
			else {
				row.push_back(current);
				current = 0;
				inNumber = false;
			}
		}
		else {
			if (*walker <= '9' && *walker >= '0') {
				inNumber = true;
				current = *walker - '0';
			}
		}
	}

	// printf("Row has %d entires\n", row.size());
	return row;
}

int main(int argc, char **argv)
{

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("Couldn't open file %s\n", argv[1]);
		return 1;
	}

	vector<vector<long>> matrix;
	vector<vector<long>> solution;

	char sz[1000];
	int squareSize = -1;
	while (NULL != fgets(sz, 1000, file)) {
		vector<long> current = readLine(sz);
		matrix.push_back(current);
		if (squareSize == -1) {
			squareSize = current.size();
		}
		else {
			if (squareSize != current.size()) {
				fclose(file);
				printf("Epxected row size %d, not %d\n", squareSize, current.size());
				return 1;
			}
		}
	}

	fclose(file);

	if (squareSize != matrix.size()) {
		printf("Expected number of rows (%d) to equal number of columns (%d)\n", matrix.size(), squareSize);
		return 1;
	}

	printf("Square size is %d\n", squareSize);

	long * blankRow = new long[squareSize];
	for (int n = 0; n < squareSize; n++) {
		blankRow[n] = 0;
	}

	for (int n = 0; n < squareSize; n++) {
		vector<long> blankVector;
		for (int m = 0; m < squareSize; m++) {
			blankVector.push_back(0);
		}
		solution.push_back(blankVector);
	}

	delete[] blankRow;

	// initialize the edges
	for (int n = squareSize - 2; n >= 0; n--) {
		solution[squareSize-1][n] = matrix[squareSize-1][n + 1] + matrix[squareSize-1][n];
		// printf("%d\n", solution[squareSize - 1][n]);
		solution[n][squareSize-1] = matrix[n + 1][squareSize-1] + matrix[n][squareSize-1];
	}

	printf("%d\n", solution[0][squareSize - 1]);
	printf("%d\n", solution[squareSize - 1][0]);

	/*
	int row = squareSize - 1;
	int column = squareSize - 1;

	int sum = 0;
	while (row >= 0 && column >= 0) {

		printf("row == %d, column == %d\n", row, column);
		sum += matrix[row][column];

		if (row == 0 && column == 0) {
			printf("chose %d\n", matrix[row][column]);
			break;
		} else if (row == 0) {
			column--;
			printf("chose %d\n", matrix[row][column]);
		}
		else if (column == 0) {
			row--;
			printf("chose %d\n", matrix[row][column]);
		}
		else {
			int left = matrix[row][column-1];
			int up = matrix[row-1][column];
			
			if (left > up) {
				row--;
				printf("chose %d\n", up);
			}
			else {
				column--;
				printf("chose %d\n", left);
			}
		}
	}

	printf("%d\n", sum);
	*/

	// work back and up finding max path
	for (int n = squareSize - 2; n >= 0; n--) {
		for (int m = squareSize - 2; m >= 0; m--) {

			int right = solution[n][m + 1];
			int left = solution[n + 1][m];
			int choice = (right < left) ? right : left;

			solution[n][m] = choice + matrix[n][m];
		}
	}

	printf("answer is %d\n", solution[0][0]);


	for (int n = 0; n < squareSize; n++) {
		for (int m = 0; m < squareSize; m++) {
			printf("%4d ", matrix[n][m]);
		}
		printf("\n");
	}

	printf("---\n");

	for (int n = 0; n < squareSize; n++) {
		for (int m = 0; m < squareSize; m++) {
			printf("%4d ", solution[n][m]);
		}
		printf("\n");
	}

    return 0;
}


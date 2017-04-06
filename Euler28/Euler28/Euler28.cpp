// Euler28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


class BigArray
{
	int size;
	int **array;

	enum Direction {
		LEFT,
		RIGHT,
		UP,
		DOWN
	};


public:
	BigArray(int size) : 
		size(size) {

		assert(size % 2 == 1);

		array = new int*[size];

		for (int n = 0; n < size; n++) {

			array[n] = new int[size];
			for (int m = 0; m < size; m++) {
				array[n][m] = -1;
			}
		}
	}

	void print() {

		for (int n = 0; n < size; n++) {

			for (int m = 0; m < size; m++) {
				printf("%5d ", array[n][m]);
			}
			putchar('\n');
		}
	}

	void initSpiral() {

		int y = 0;
		int x = size - 1;

		int rightLimit = size - 1;
		int leftLimit = 0;
		int upLimit = 0;
		int downLimit = size - 1;

		Direction dir = LEFT;

		for (int counter = size * size; counter > 0; counter--) {

			// printf("[%d][%d] = %d\n", y, x, counter);
			assert(array[y][x] == -1);
			array[y][x] = counter;

			switch (dir) {

			case LEFT:
				if (x == leftLimit) {
					dir = DOWN;
					y++;
					upLimit++;
				}
				else {
					x--;
				}
				break;

			case DOWN:
				if (y == downLimit) {
					dir = RIGHT;
					leftLimit++;
					x++;
				}
				else {
					y++;
				}
				break;

			case RIGHT:
				if (x == rightLimit) {
					dir = UP;
					downLimit--;
					y--;
				}
				else {
					x++;
				}
				break;

			case UP:
				if (y == upLimit) {
					dir = LEFT;
					rightLimit--;
					x--;
				}
				else {
					y--;
				}
				break;

			}
		}

	}

	int crossSum() {

		int total = 0;

		for (int n = 0; n < size; n++) {

			printf("[%d][%d] = %d\n", n, n, array[n][n]);
			total += array[n][n];

			printf("[%d][%d] = %d\n", n, size - n - 1, array[n][size - n - 1]);
			total += array[n][size - n -1];

		}

		// double-counted the center square, so adujust
		total -= 1;
		return total;
	}
};

int main()
{
	BigArray a(1001);
	// a.print();

	a.initSpiral();
	// a.print();

	printf("total is %d\n", a.crossSum());

    return 0;
}


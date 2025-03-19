#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

typedef int Element;
#include "ArrayStack.h";

void quickSort(int *s, int left, int right);

// 25.03.19 (수) 배열 스텍 I/O 실습
int main() {

	srand(time(NULL));
	int stackArr[10];
	int size = sizeof(stackArr) / sizeof(stackArr[0]);

	for (int i = 0; i < 10; i++) {
		stackArr[i] = rand() % 10 + 1;
	}

	quickSort(stackArr, 0, size -1);

	init_stack();

	puts("[ quickSortted stack I/O logic ]");
	printf("input data : ");
	for (int i = 0; i < 10; i++) {
		printf(" %d", stackArr[i]);
		push(stackArr[i]);
	}

	puts("");

	printf("output data : ");

	while (!is_empty()) {
		printf(" %d", pop());
	}
	puts("");

	return 0;
}

void quickSort(int* s, int left, int right) {

	if (left >= right) {
		return;
	}

	int pivot = s[(left + right) / 2];
	int checkLeft = left;
	int checkRight = right;
	int temp;

	do {
		while (s[checkLeft] < pivot) {
			checkLeft++;
		}
		while (s[checkRight] > pivot) {
			checkRight--;
		}
		if (checkLeft <= checkRight) {
			temp = s[checkLeft];
			s[checkLeft] = s[checkRight];
			s[checkRight] = temp;
			checkLeft++;
			checkRight--;
		}
		quickSort(s, left, checkRight);
		quickSort(s, checkLeft, right);

	} while (checkLeft <= checkRight);
}
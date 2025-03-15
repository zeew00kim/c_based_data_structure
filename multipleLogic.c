#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void printArr1(int(*p1)[3]);
void printArr2(int(*p2)[2]);
void getResult(int(*p1)[3], int (*p2)[2]);

int main() {

	int arr1[2][3];
	int arr2[3][2];
	int size = sizeof(arr1) / sizeof(arr1[0][0]);

	srand(time(NULL));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			arr1[i][j] = rand() % 10 + 1;
		}
	}
	printArr1(arr1);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			arr2[i][j] = rand() % 10 + 1;
		}
	}
	printArr2(arr2);

	printf("[ result of arr1(row) * arr2(colunm) ]\n");
	getResult(arr1, arr2);

	return 0;
}

void printArr1(int(*p1)[3]) {

	printf("[ initial state of arr1 ]\n");
	for (int i = 0; i < 2; i++) {
		printf("arr1[%d] = { ", i);
		for (int j = 0; j < 3; j++) {
			printf("%d", *(*(p1 + i)+j));
			if (j < 2) {
				printf(", ");
			}
			else {
				printf(" }\n");
			}
		}
	}
	puts("");
}

void printArr2(int(*p2)[2]) {

	printf("[ initial state of arr2 ]\n");
	for (int i = 0; i < 3; i++) {
		printf("arr2[%d] = { ", i);
		for (int j = 0; j < 2; j++) {
			printf("%d", *(*(p2 + i) + j));
			if (j < 1) {
				printf(", ");
			}
			else {
				printf(" }\n");
			}
		}
	}
	puts("");
}

void getResult(int(*p1)[3], int(*p2)[2]) {

	int tempArr[2][2];
	int temp;
	int sum = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			temp = p1[i][j] * p2[j][i];
			sum += temp;
		}
		tempArr[i][i] = sum; // [0][0], [1][1]
		sum = 0;
		
		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				temp = p1[i + 1][j] * p2[j][i];
				sum += temp;
			}
			tempArr[i+1][i] = sum; // [1][0]
			sum = 0;

			for (int j = 0; j < 3; j++) {
				temp = p1[i][j] * p2[j][i + 1];
				sum += temp;
			}
			tempArr[i][i+1] = sum; // [0][1]
			sum = 0;
		}
	}

	for (int i = 0; i < 2; i++) {
		printf("tempArr[%d] = { ", i);
		for (int j = 0; j < 2; j++) {
			printf("%d", tempArr[i][j]);
			if (j < 1) {
				printf(", ");
			}
			else {
				printf(" }\n");
			}
		}
	}
}
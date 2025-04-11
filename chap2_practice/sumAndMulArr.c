#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void printArr1(int(*p1)[3]);
void printArr2(int(*p2)[2]);
void printArr3(int(*p3)[3]);
void getResult(int(*p1)[3], int(*p2)[2]);
void getSum(int(*p1)[3], int(*p2)[2]);

int main() {

	int arr1[2][3];
	int arr2[3][2];
	int arr3[2][3];
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

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			arr3[i][j] = rand() % 10 + 1;
		}
	}
	printArr3(arr3);

	printf("[ result of arr1(row) * arr(colunm) ]\n");
	getResult(arr1, arr2);

	printf("[ result of arr1 + arr2 ]\n");
	getSum(arr1, arr3);

	return 0;
}

void printArr1(int(*p1)[3]) {

	printf("[ initial state of arr1 ]\n");
	for (int i = 0; i < 2; i++) {
		printf("arr1[%d] = { ", i);
		for (int j = 0; j < 3; j++) {
			printf("%d", p1[i][j]);
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
		printf("arr1[%d] = { ", i);
		for (int j = 0; j < 2; j++) {
			printf("%d", p2[i][j]);
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

void printArr3(int(*p3)[3]) {

	printf("[ initial state of arr3 ]\n");
	for (int i = 0; i < 2; i++) {
		printf("arr3[%d] = { ", i);
		for (int j = 0; j < 3; j++) {
			printf("%d", p3[i][j]);
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

void getResult(int(*p1)[3], int(*p2)[2]) {

	int mulArr[2][2];
	int temp;
	int sum = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			temp = p1[i][j] * p2[j][i];
			sum += temp;
		}
		mulArr[i][i] = sum;
		sum = 0;

		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				temp = p1[i+1][j] * p2[j][i];
				sum += temp;
			}
			mulArr[i + 1][i] = sum;
			sum = 0;

			for (int j = 0; j < 3; j++) {
				temp = p1[i][j] * p2[j][i + 1];
				sum += temp;
			}
			mulArr[i][i + 1] = sum;
			sum = 0;
		}
	}

	for (int i = 0; i < 2; i++) {
		printf("mulArr[%d] = { ", i);
		for (int j = 0; j < 2; j++) {
			printf("%d", mulArr[i][j]);
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

void getSum(int(*p1)[3], int(*p2)[2]) {

	int sumArr[2][3];
	int temp;

	for (int i = 0; i < 2; i++) {
		printf("sumArr[%d] = { ", i);
		for (int j = 0; j < 3; j++) {
			temp = p1[i][j] + p2[i][j];
			sumArr[i][j] = temp;
			printf("%d", sumArr[i][j]);
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
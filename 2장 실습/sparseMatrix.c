#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int row; // 행 번호
	int col; // 열 번호
	int value; // 하나의 행렬 요소
} Element;

void printArr(Element *structArr, int size, char *str);
void transportArr(Element* p, int size);

int main() {

	Element structArr[5];
	int size = sizeof(structArr) / sizeof(structArr[0]); // 60 / 12 = 5

	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		structArr[i].row = rand() % 10;
		structArr[i].col = rand() % 10;
		structArr[i].value = rand() % 10;
	}

	printArr(structArr, size, "[ sparse matrix ]");
	transportArr(structArr, size);
	printArr(structArr, size, "[ transported matrix ]");

	return 0;
}

void printArr(Element* structArr, int size, char *str) {
	puts(str);
	for (int i = 0; i < size; i++) {
		printf("structArr[%d] = { ", i);
		printf("%d, ", structArr[i].row);
		printf("%d, ", structArr[i].col);
		printf("%d }\n", structArr[i].value);
	}
	puts("");
}

void transportArr(Element* p, int size) {
	for (int i = 0; i < size; i++) {
		int temp = p[i].row;
		p[i].row = p[i].col;
		p[i].col = temp;
	}
}
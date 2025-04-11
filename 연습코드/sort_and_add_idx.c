#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void insertValue(int* arr, int num);
void selectionSort(int* arr, int num);

int main() {

	int num, strLen;
	char *usingSort;

	srand(time(NULL));

	printf("enter the size of array : ");
	scanf("%d", &num);

	int* arr = (int*)malloc(sizeof(int) * (num + 1));

	for (int i = 0; i < num; i++) {
		arr[i] = rand() % 10 + 1;
	}

	printf("enter the length of string : ");
	scanf("%d", &strLen);

	usingSort = (char*)malloc(sizeof(char) * strLen);

	printf("if you want using selectionSort ? yes : no => ");
	scanf("%s", usingSort);

	if (strcmp(usingSort, "yes") == 0) {
		selectionSort(arr, num);
	}

	insertValue(arr, num);

	free(arr);
	free(usingSort);
	
	return 0;
}

void insertValue(int* arr, int num) {

	int newValue;
	int changeIdx;

	printf("enter the new value : ");
	scanf("%d", &newValue);

	do {
		printf("choose the change idx number : ");
		scanf("%d", &changeIdx);
		if (changeIdx > num) {
			puts("this value is over the array size, retry it...");
		}
	} while (changeIdx > num);
	 
	for (int i = num - 1; i >= changeIdx; i--) {

		arr[i + 1] = arr[i];
	}
	arr[changeIdx] = newValue;
	num++;

	printf("arr = { ");
	for (int i = 0; i < num; i++) {
		printf("%d", arr[i]);
		if (i != num - 1) {
			printf(", ");
		}
		else if (i == num - 1) {
			puts(" }");
		}
	}
}

void selectionSort(int* arr, int num) {

	for (int i = 0; i < num - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < num; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}
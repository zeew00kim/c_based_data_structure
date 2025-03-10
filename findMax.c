#include <stdio.h>
#include <time.h>

void findMax(int* arr, int max);

int main() {

	int arr[5];
	int size = sizeof(arr) / sizeof(arr[0]);

	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
		printf("%d", arr[i]);
		if (i != size - 1) {
			printf(", ");
		}
	}

	puts("");

	int max = arr[0];

	findMax(arr, max);

	return 0;
}

void findMax(int* arr, int max) {

	for (int i = 0; i < 5; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	printf("max = %d\n", max);
}
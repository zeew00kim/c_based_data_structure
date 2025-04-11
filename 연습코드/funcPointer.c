#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int main() {

	int choice;

	do {
		puts("");
		
		printf("[ choose the arithmetic method ]\n");
		printf("1. sum of two integer\n");
		printf("2. mul of two integer\n");
		printf("3. find max\n");
		printf("your choice = ");
		scanf("%d", &choice);
		
		puts("");

		switch (choice) {
		case 1:
			func(sum);
			break;
		case 2:
			func(mul);
			break;
		case 3:
			func(max);
			break;
		default:
			printf("program off...\n");
			break;
		}
	} while (choice != 0 && choice <= 3);

	return 0;
}

void func(int (*fp)(int, int)) {

	int arr[2];
	int len = sizeof(arr) / sizeof(arr[0]);
	int res;

	srand(time(NULL));

	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100 + 1;
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	res = fp(arr[0], arr[1]);
	
	printf("result of clac = %d\n", res);
}

int sum(int a, int b) {

	return (a + b);
}

int mul(int a, int b) {
	
	return (a * b);
}

int max(int a, int b) {
	
	return (a > b ? a : b);
}
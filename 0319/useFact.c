#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int useFact(int num) {
	if (num == 1) {
		return 1;
	}
	else {
		return num * useFact(num - 1);
	}
}

int main() {

	int num;
	int res;

	do {
		printf("enter the one of integer : ");
		scanf("%d", &num);
		if (num < 0) {
			printf("your input is non-positive integer...\n");
		}
	} while (num < 0);

	res = useFact(num);
	printf("result : %d\n", res);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 11
#define Element int
#include "circularDeque.h"

bool check(char* input);

int main() {

	char input[100];

	while (1) {
		printf("\n입력 : ");
		scanf("%s", input);
		if (strcmp(input, "0") == 0) {
			break;
		}
		printf("결과 : %s", check(input) ? "회문" : "비회문");
	}

	return 0;
}

bool check(char* input) {

	int len = strlen(input);
	for (int i = 0; i < len / 2; i++) {
		if (input[i] != input[len - 1 - i]) {
			return false;
		}
	}
	return true;
}
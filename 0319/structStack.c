#include <stdio.h>
#include <stdlib.h>
typedef int Element;
#include "ArrayStack2.h"
#define MAX_SIZE 100

// 25.03.19 (수) 구조체 배열 스텍 저장 실습
int main() {

	int st[7];
	int size = sizeof(st) / sizeof(st[0]);

	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		st[i] = rand() % 10 + 1;
	}

	Stack s1, s2;
	
	init_stack(&s1);
	init_stack(&s2);

	printf("input data : ");
	for (int i = 0; i < size; i++) {
		printf(" %d", st[i]);
		push(&s1, st[i]);
	}
	puts("");
	
	printf("output of s1 : ");
	while (!is_empty(&s1)) {
		printf(" %d", peek(&s1));
		push(&s2, pop(&s1));
	}
	puts("");

	printf("output of s2 : ");
	while (!is_empty(&s2)) {
		printf(" %d", pop(&s2));
	}
	puts("");
}
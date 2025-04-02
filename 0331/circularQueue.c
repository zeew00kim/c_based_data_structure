#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 8
typedef int Element;
#include "circularQueue.h"

void print_queue(char msg[]) {
	printf("%s front = %d, rear = %d --> ", msg, front, rear);
	int size = (rear - front + MAX_SIZE) % MAX_SIZE;

	for (int i = front + 1; i < front + size; i++) {
		printf("%2d", data[i % MAX_SIZE]);
	}
	puts("");
}

int main() {

	init_queue();
	
	for (int i = 0; i < 7; i++) {
		enqueue(i);
	}
	print_queue("enqueue 1 ~ 6 : ");

	for (int i = 0; i < 4; i++) {
		dequeue();
	}
	print_queue("dequeue 4회 : ");

	for (int i = 7; i < 10; i++) {
		enqueue(i);
	}
	print_queue("enqueue 7 ~ 9 : ");

	return 0;
}
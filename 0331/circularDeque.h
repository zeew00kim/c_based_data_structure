#include "circularQueue.h"

void init_deque() {
	
	init_queue();
}

void add_rear(Element val) {

	enqueue(val);
}

Element delete_front() {

	return dequeue();
}

Element get_front() {

	return peek();
}

// 큐에는 없는 새로운 연산들
void add_front(Element val) {

	if (is_full()) {
		error("Overflow Error!!!\n");
	}
	data[front] = val;
	front = (front - 1 + MAX_SIZE) % MAX_SIZE;
}

Element delete_rear() {
	
	if (is_empty()) {
		error("Underflow Error!!!\n");
	}
	int prev = rear;
	rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;

	return data[prev];
}

Element get_rear() {
	
	if (is_empty()) {
		error("Underflow Error!!!\n");
	}
	return data[rear];
}
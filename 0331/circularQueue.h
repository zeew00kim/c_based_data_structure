// Element & MAX_SIZE c파일에 구현
Element data[MAX_SIZE];
int front;
int rear;

void error(char* str) {
	printf("%s\n", str);
	exit(1);
}

// 큐 초기화
void init_queue() {

	front = rear = 0;
}

// 큐가 비어있다면
int is_empty() {
	return front == rear;
}

int is_full() {
	return front == (rear + 1) % MAX_SIZE;
}

// 큐 입력 연산
void enqueue(Element val) {

	if (is_full()) {
		error("Overflow Error!!!\n");
	}
	rear = (rear + 1) % MAX_SIZE;
	data[rear] = val;
}

// 큐 삭제 연산
Element dequeue() {
	
	if (is_empty()) {
		error("Underflow Error!!!\n");
	}
	front = (front + 1) % MAX_SIZE;
	return data[front];
}

// 큐 탐색 연산
Element peek() {
	if (is_empty()) {
		error("Underflow Error!!!\n");
	}
	return data[(front + 1) % MAX_SIZE];
}
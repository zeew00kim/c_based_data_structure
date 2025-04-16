#include <stdio.h>
#include <stdlib.h>

typedef int Element;
Element* data;
int front, rear, MAX_SIZE;

void error(char* str) {
    puts(str);
    exit(-1);
}

// 큐 초기화 시 data 배열 동적 할당
void init_queue() {
    front = rear = 0;
    MAX_SIZE = 2;
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
}

int is_empty() {
    return (front == rear) ? 1 : 0;
}

int is_full() {
    return (front == (rear + 1) % MAX_SIZE) ? 1 : 0;
}

void enqueue(Element e) {
    if (is_full()) {
        MAX_SIZE *= 2;
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE);
        if (rear < front) {
            for (int i = 0; i <= rear; i++) {
                data[MAX_SIZE + i] = data[i];
            }
            rear += MAX_SIZE;
        }
    }
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = e;
}

Element dequeue() {
    if (is_empty()) {
        error("[ underflow error ]");
    }
    front = (front + 1) % MAX_SIZE;
    return data[front];
}

Element peek() {
    if (is_empty()) {
        error("[ underflow error ]");
    }
    return data[(front + 1) % MAX_SIZE];
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define Element int
Element data[MAX_SIZE];

int front, rear, size;

void error(char *str) {
    puts(str);
    exit(-1);
}

void init_queue() {
    front = rear = 0;
}

int is_empty() {
    return (front == rear) ? 1 : 0;
}

int is_full() {
    return (front == (rear + 1) % MAX_SIZE) ? 1 : 0;
}

void enqueue(Element e) {
    if (is_full()) {
        error("[ overflow error ]");
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
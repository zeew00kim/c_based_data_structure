#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
// typedef int Element;
struct Pos2D {
    int r;
    int c;
};
typedef struct Pos2D Element;
Element data[MAX_SIZE];
int front, rear;

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
        error("queue overflow");
    }
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = e;
}

Element dequeue() {
    if (is_empty()) {
        error("queue underflow");
    }
    front = (front + 1) % MAX_SIZE;
    return data[front];
}

Element peek() {
    if (is_empty()) {
        error("queue underflow");
    }
    return data[(front + 1) % MAX_SIZE];
}
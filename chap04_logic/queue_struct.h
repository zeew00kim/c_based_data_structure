#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 8
typedef int Element;
typedef struct Queue {
    Element data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void error(char *str) {
    puts(str);
    exit(-1);
}

void init_queue(Queue *q) {
    q->front = q->rear = 0;
}

int is_empty(Queue *q) {
    return (q->front == q->rear) ? 1 : 0;
}

int is_full(Queue *q) {
    return (q->front == (q->rear + 1) % MAX_SIZE);
}

void enqueue(Queue *q, Element e) {
    if (is_full(q)) {
        error("[ overflow ]");
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = e;
}

Element dequeue(Queue *q) {
    if (is_empty(q)) {
        error("[ underflow ]");
    }
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

Element peek(Queue *q) {
    if (is_empty(q)) {
        error("[ underflow ]");
    }
    return q->data[(q->front + 1) % MAX_SIZE];
}
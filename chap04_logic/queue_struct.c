#include "queue_struct.h"

void print_queue(Queue *q, char *str);

int main() {

    Queue q;

    init_queue(&q);

    for (int i = 1; i < 7; i++) {
        enqueue(&q, i);
    }
    print_queue(&q, "enqueue 1 ~ 6 : ");

    for (int i = 0; i < 4; i++) {
        dequeue(&q);
    }
    print_queue(&q, "dequeue X 4 : ");

    for (int i = 7; i < 10; i++) {
        enqueue(&q, i);
    }
    print_queue(&q, "enqueue 7 ~ 9 : ");

    return 0;
}

void print_queue(Queue *q, char *str) {

    printf("%s, front = %d, rear = %d ==> ", str, q->front, q->rear);

    int size = (q->rear - q->front + MAX_SIZE) % MAX_SIZE;

    for (int i = q->front + 1; i <= q->front + size; i++) {
        printf("%2d ", q->data[i % MAX_SIZE]);
    }

    puts("");
}
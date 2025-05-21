#include "queue_struct.h"

typedef Queue Deque;

void init_deque(Deque* d) {
    init_queue(d);
}

void add_rear(Deque* d, Element e) {
    enqueue(d, e);
}

Element delete_front(Deque* d) {
    dequeue(d);
}

Element get_front(Deque* d) {
    peek(d);
}

void add_front(Deque* d, Element e) {
    if (is_full(d)) {
        error("[ overflow ]");
    }
    d->data[d->front] = e;
    d->front = (d->front - 1 + MAX_SIZE) % MAX_SIZE;
}

Element delete_rear(Deque* d) {
    if (is_empty(d)) {
        error("[ underflow ]");
    }
    int temp = d->rear;
    d->rear = (d->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return d->data[temp];
}

Element get_rear(Deque* d) {
    if (is_empty(d)) {
        error("[ underflow ]");
    }
    return d->data[d->rear];
}
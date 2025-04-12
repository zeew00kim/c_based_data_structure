#include "circular_queue.h"

void init_deque() {
    init_queue();
}

// 전단 삽입/삭제/참조는 큐와 동일
void add_rear(Element val) {
    enqueue(val);
}

Element delete_front() {
    return dequeue();
}

Element get_front() {
    return peek();
}

// 큐에는 없는 새로운 연산
void add_front(Element val) {
    if (is_full()) {
        error("[ overflow error ]");
    }
    data[front] = val;
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    // 전단 삽입은 현재 위치에 요소 삽입 후 front 한 칸 반시계 이동
}

Element delete_rear() {
    if (is_empty()) {
        error("[ underflow error ]");
    }
    int pre = rear;
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    return data[pre];
    // 후단 삭제는 rear 위치 저장 및 반시계 회전 후 이전 rear 위치 반환
}

Element get_rear() {
    if (is_empty()) {
        error("[ underflow error ]");
    }
    return data[rear];
}
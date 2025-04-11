#define _CRT_SECURE_NO_WARNINGS
#include "linked_queue.h"

// 0407 5-11 코드 : 선형 리스트 큐의 삽입/삭제 연산
void print_queue(const char* msg);

int main() {
    init_queue();

    for (int i = 0; i < 7; i++) {
        enqueue(i);
    }
    print_queue("enqueue 0 ~ 6 : ");

    for (int i = 0; i < 4; i++) {
        dequeue();
    }
    print_queue("after dequeue 4 times : ");

    for (int i = 7; i < 10; i++) {
        enqueue(i);
    }
    print_queue("enqueue 7 ~ 9 : ");

    destroy_queue();
    print_queue("after destroy : ");

    return 0;
}

void print_queue(const char* msg) {
    printf("%s ", msg);
    for (Node* p = front; p != NULL; p = p->link) {
        printf("%2d ", p->data);
    }
    puts("");
}

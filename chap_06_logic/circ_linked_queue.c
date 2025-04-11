#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "circ_linked_queue.h"

void print_queue(char* msg);

// 0407 5-9 코드 : 원형으로 연결된 큐의 구현 
int main() {

    init_queue();

    for (int i = 0; i < 7; i++) {
        enqueue(i);
    }
    print_queue("enqueue 1 ~ 6 : ");

    for (int i = 0; i < 4; i++) {
        dequeue();
    }
    print_queue("dequeue try 4 : ");

    for (int i = 7; i < 10; i++) {
        enqueue(i);
    }
    print_queue("enqueue 7 ~ 9 : ");

    destroy_queue();

    return 0;
}

void print_queue(char* msg) {

    printf("%s = ", msg);

    if (rear != NULL) {
        for (Node* p = rear->link; p != rear; p = p->link) {
            printf("%2d ", p->data);
        }
        printf("%2d ", rear->data);
    }
    puts("");
}
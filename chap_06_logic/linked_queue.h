#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// 0407 5-11 코드 : 선형 리스트 큐의 삽입/삭제 연산
typedef int Element;

typedef struct Node {
    Element data;
    struct Node* link;
} Node;

// 전역 포인터
Node* front = NULL;
Node* rear = NULL;

// 오류 처리 함수
void error(char* msg) {
    printf("%s\n", msg);
    exit(1);
}

// 노드 동적 할당
Node* alloc_node(Element e) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) error("memory allocation error!");
    p->data = e;
    p->link = NULL;
    return p;
}

// 노드 해제 및 데이터 반환
Element free_node(Node* p) {
    Element e = p->data;
    free(p);
    return e;
}

// 큐 초기화
void init_queue() {
    front = rear = NULL;
}

// 큐가 비었는지 확인
int is_empty() {
    return front == NULL;
}

// 큐가 가득 찼는지 확인 (항상 false)
int is_full() {
    return 0;
}

// 큐 삽입
void enqueue(Element e) {
    Node* p = alloc_node(e);
    if (is_empty()) {
        front = rear = p;
    } else {
        rear->link = p;
        rear = p;
    }
}

// 큐 삭제
Element dequeue() {
    if (is_empty()) {
        error("underflow error!");
    }

    Node* p = front;
    front = front->link;

    if (front == NULL) {
        rear = NULL;
    }

    return free_node(p);
}

// 큐 맨 앞 데이터 확인
Element peek() {
    if (is_empty()) {
        error("underflow error!");
    }
    return front->data;
}

// 큐 전체 해제
void destroy_queue() {
    while (!is_empty()) {
        dequeue();
    }
}

// 큐 사이즈 계산
int size() {
    int cnt = 0;
    for (Node* p = front; p != NULL; p = p->link) {
        cnt++;
    }
    return cnt;
}

#endif

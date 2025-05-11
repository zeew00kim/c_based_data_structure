#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// 트리 노드 전방 선언
typedef struct TNode TNode;
typedef TNode* Element;

typedef struct Node {
    Element data;
    struct Node* link;
} Node;

static Node* front = NULL;
static Node* rear = NULL;

void error(const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

// 함수 프로토타입 선언
Node* alloc_node(Element e);
Element free_node(Node* p);

// 큐 초기화
void init_queue() {
    front = rear = NULL;
}

// 큐가 비었는지 확인
int is_empty() {
    return (front == NULL);
}

// 큐가 가득 찼는지 확인 (연결 리스트 기반이므로 항상 0)
int is_full() {
    return 0;
}

// 노드 동적 할당
Node* alloc_node(Element e) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) error("Memory allocation failed");
    p->data = e;
    p->link = NULL;
    return p;
}

// 노드 반환
Element free_node(Node* p) {
    Element e = p->data;
    free(p);
    return e;
}

// 큐에 삽입
void enqueue(Element e) {
    Node* p = alloc_node(e);
    if (is_empty()) {
        front = rear = p;
    } else {
        rear->link = p;
        rear = p;
    }
}

// 큐에서 삭제 및 반환
Element dequeue() {
    if (is_empty()) error("[ underflow ]");
    Node* p = front;
    front = front->link;
    if (front == NULL) rear = NULL;
    return free_node(p);
}

// 큐의 맨 앞 요소 확인
Element peek() {
    if (is_empty()) error("[ underflow ]");
    return front->data;
}

// 큐 크기 확인
int size() {
    int count = 0;
    for (Node* p = front; p != NULL; p = p->link)
        count++;
    return count;
}

// 큐 완전 삭제
void destroy_queue() {
    while (!is_empty()) {
        dequeue();
    }
}

#endif  // CIRCULAR_QUEUE_H
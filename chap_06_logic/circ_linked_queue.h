#ifndef CIRC_LINKED_QUEUE_H
#define CIRC_LINKED_QUEUE_H

// 0407 5-9 코드 : 원형으로 연결된 큐의 구현 
typedef struct Node {
    Element data;
    struct Node *link;
} Node;

Node* rear = NULL; // 원형으로 연결된 큐의 유일한 데이터 (후단 노드 가리키는 포인터)

Node *alloc_node(Element e) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->link = NULL;
    return p;
}

Element free_node(Node* p) {
    Element e = p->data;
    free(p);
    return e;
}

void error(char* str) {
    printf("%s\n", str);
    exit(1);
}

int is_empty() {
    return rear == NULL;
}

int is_full() {
    return 0;
}

void init_queue() {
    rear = NULL;
}

int size() {
    if (is_empty()) {
        return 0;
    }

    int cnt = 1;
    for (Node *p = rear->link; p != rear; p = p->link) {
        cnt++;
    }
    return cnt;
}

// 삽입 연산
void enqueue(Element e) {
    Node* p = alloc_node(e);
    
    if (is_empty()) {
        rear = p;
        p->link = p;
    }
    else {
        p->link = rear->link;
        rear->link = p;
        rear = p;
    }
}

// 삭제 연산
Element dequeue() {

    if (is_empty()) {
        error("underflow error!");
    }

    Node* p = rear->link;

    if (rear == p) {
        rear = NULL;
    }
    else {
        rear->link = p->link;
    }

    return free_node(p);
}

// 탐색 연산
Element peek() {

    if (is_empty()) {
        error("underflow error!");
    }

    return rear->link->data;
}

// 모든 요소 삭제(free) 연산
void destroy_queue() {
    while (is_empty() == 0) {
        dequeue();
    }
}

#endif
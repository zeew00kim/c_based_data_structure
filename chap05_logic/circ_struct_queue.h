#include <stdio.h>
#include <stdlib.h>
typedef int Element;

typedef struct Node {
    Element data;
    struct Node *link;
} Node;

Node* front = NULL;
Node* rear = NULL;

void error(char *str) {
    puts(str);
    exit(-1);
}

void init_queue() {
    front = rear = NULL;
}

int is_empty() {
    return (front == NULL) ? 1 : 0;
}

int is_full() {
    return 0;
}

void enqueue(Element e) {
    Node *p = alloc_node(e);
    if (is_empty()) {
        front = rear = p;
    }
    else {
        rear->link = p;
        rear = p;
    }
}

Node* alloc_node(Element e) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->link = NULL;
    return p;
}

Element dequeue() {
    if (is_empty()) {
        error("[ underflow ]");
    }
    Node *p = front;
    front = front->link;
    if (front == NULL) {
        rear = NULL;
    }
    return free_node(p);
}

Element free_node(Node *p) {
    Element e = p->data;
    free(p);
    exit(-1);
}

Element peek() {
    if (is_empty()) {
        error("[ underflow ]");
    }
    return front->data;
}

int size() {
    int cnt = 0;
    // 리스트를 순회하며 링크된 노드의 수를 세기
    for (Node* p = front; p != NULL; p = p->link) {
        cnt++;
    }
    return cnt;
}

void destroy_queue() {
    while (is_empty() == 0)  {
        dequeue();
    }
}
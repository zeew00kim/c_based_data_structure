#include <stdio.h>
#include <stdlib.h>
typedef int Element;

typedef struct DNode {
    Element data;
    struct DNode* pre;
    struct DNode* next;
} DNode;

DNode org; // 시작 노드를 가리킴

DNode* alloc_dnode(Element e) {
    DNode *p = (DNode*)malloc(sizeof(DNode));
    p->data = e; // 데이터 초기화
    p->pre = NULL; // 선행노드 링크 초기화
    p->next = NULL; // 후속노드 링크 초기화
    return p;
}

Element free_dnode(DNode* p) {
    Element e = p->data;
    free(p);
    return e;
}

void error(char *str) {
    puts(str);
    exit(-1);
}

int is_empty() {
    return (org.next == NULL) ? 1 : 0;
}

int is_full() {
    return 0;
}

void init_list() {
    org.next = NULL;
}

DNode* get_node(int pos) {
    DNode* p = &org;
    for (int i = 0; i <= pos; i++, p = p->next) {
        if (p == NULL) {
            return NULL;
        }
    }
    return p;
}

Element get_entry(int pos) {
    DNode* p = get_node(pos);
    if (pos < 0 || p == NULL) {
        error("[ invalid position error ]");
    }
    return p->data;
}

void insert(int pos, Element e) {
    DNode* before = get_node(pos -1);
    if (before == NULL) {
        error("[ invalid position error ]");
    }

    DNode* p = alloc_dnode(e);
    p->next = before->next;
    p->pre = before;
    before->next = p;
    if (p->next != NULL) {
        p->next->pre = p;
    }
}

Element delete_node(int pos) {
    DNode *p = get_node(pos);
    if (pos < 0 || p == NULL) {
        error("[ invalid postion error ]");
    }

    p->pre->next = p->next;

    if (p->next != NULL) {
        p->next->pre = p->pre;
    }

    return free_dnode(p);
}

void destroy_list() {
    while (is_empty() == 0) {
        delete_node(0);
    }
}

int size() {
    int cnt = 0;
    for (DNode* p = org.next; p != NULL; p->next) {
        cnt++;
    }
    return cnt;
}
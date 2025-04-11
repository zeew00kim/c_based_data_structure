#include <stdio.h>
#include <stdlib.h>
typedef int Element;

typedef struct Node {
    Element data;
    struct Node* link;
} Node;

Node* head = NULL;

Node* alloc_node(Element e) {
    Node * p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->link = NULL;
    return p;
}

Element free_node(Node* p) {
    Element  e = p->data;
    free(p);
    return e;
}

void error(char *str) {
    printf("%s\n", str);
    exit(1);
}

int is_empty() {
    return head == NULL;
}

int is_full() {
    return 0;
}

void init_list() {
    head = NULL;
}

Node* get_node(int pos) {
    if (pos < 0) {
        return NULL;
    }
    Node* p = head;
    
    for (int i = 0; i < pos; i++, p = p->link) {
        if (p == NULL) {
            return NULL;
        }
    }

    return p;
}

Element get_entry(int pos) {
    Node* p = get_node(pos);
    if (p == NULL) {
        error("invalid position error!");
    }
    return p->data;
}

void insert(int pos, Element e) {
    Node* p = alloc_node(e);
    if (pos == 0) {
        p->link = head;
        head = p;
    }
    else {
        Node* before = get_node(pos - 1);
        if (before == NULL) {
            error("invalid position error!");
        }
        p->link = before->link;
        before->link = p;
    }
}

Element delete_node(int pos) {
    if (is_empty()) {
        error("underflow error!");
    }

    Node* p = get_node(pos);

    if (p == NULL) {
        error("invalid position error!");
    }
    
    Node* before = get_node(pos - 1);

    if (before == NULL) {
        head = head->link;
    } else {
        before->link = p->link;
    }
    return free_node(p);
}

void destroy_list() {
    while (is_empty() == 0) {
        delete_node(0);
    }
}

int size() {
    int cnt = 0;
    for (Node* p = head; p != NULL; p = p->link) {
        cnt++;
    }
    return cnt;
}
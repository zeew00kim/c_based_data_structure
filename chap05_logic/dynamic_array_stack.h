#include <stdio.h>
#include <stdlib.h>
typedef int Element;

Element* data = NULL;
int top;

int MAX_SIZE = 10;

void error(char* str) {
    puts(str);
    exit(-1);
}

void init_stack() {
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
    top = -1;
}

int is_empty() {
    return (top == -1) ? 1 : 0;
}

int is_full() {
    return (top == MAX_SIZE - 1) ? 1 : 0;
}

void push(Element e) {
    if (is_full()) {
        MAX_SIZE *= 2;
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE);
        printf("[ realloc complete (%d byte) ]\n", MAX_SIZE);
    }
    data[++top] = e;
}

Element pop() {
    if (is_empty()) {
        error("[ underflow ]");
    }
    return data[top--];
}

Element peek() {
    if (is_empty()) {
        error("[ underflow ]");
    }
    return data[top];
}
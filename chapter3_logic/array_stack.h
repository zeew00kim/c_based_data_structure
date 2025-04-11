#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 스택 기능 구현을 위해 만든 헤더 파일
Element data[MAX_SIZE];
int top;

void error(char* str) {
    puts(str);
    exit(-1);
}

void init_stack() {
    top = -1;
}

int is_empty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_full() {
    return (top == (MAX_SIZE - 1));
}

void push(Element e) {
    if (is_full()) {
        error("overflow error!");
    }
    else {
        data[++top] = e;
    }
}

Element pop() {
    if (is_empty()) {
        error("underflow error!");
    }
    return data[top--];
}

Element peek() {
    if (is_empty()) {
        error("underflow error!");
    }
    return data[top];
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Element data[MAX_SIZE];

int top;

void error(char *str) {
    puts(str);
    exit(-1);
}

void init_stack() {
    puts("[ stack initialization complete ]");
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
        error("[ stack overflow error ]");
    }
    else {
        data[++top] = e;
    }
}

int pop() {
    if (is_empty()) {
        error("[ stack underflow error ]");
    }
    else {
        return data[top--];
    }
}

int peek() {
    if (is_empty()) {
        error("[ stack underflow error ]");
    }
    else {
        return data[top];
    }
}
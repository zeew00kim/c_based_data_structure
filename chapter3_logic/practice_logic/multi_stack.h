#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 2중 stack을 사용하기 위한 헤더 로직
typedef int Element2;
#define MAX_SIZE 100
typedef struct {
    Element2 data[MAX_SIZE];
    int top;
} Stack;

void error(char* str) {
    puts(str);
}

void init_stack(Stack* s, int* n) {
    s->top = -1;
    printf("[ no.%d stack initialization complete ]\n", (*n)++);
}

int is_empty(Stack* s) {
    return (s->top == -1) ? 1 : 0;
}

int is_full(Stack* s) {
    return (s->top == MAX_SIZE - 1) ? 1 : 0;
}

void push(Stack* s, Element2 e) {
    if (is_full(s)) {
        error("[ stack overflow error ]");
    }
    else {
        s->data[++s->top] = e;
    }
}

Element2 pop(Stack* s) {
    if (is_empty(s)) {
        error("[ stack underflow error ]");
        exit(-1);
    }
    else {
        return s->data[(s->top)--];
    }
}

Element2 peek(Stack* s) {
    if (is_empty(s)) {
        error("[ stack underflow error ]");
        exit(-1);
    }
    else {
        return s->data[s->top];
    }
}
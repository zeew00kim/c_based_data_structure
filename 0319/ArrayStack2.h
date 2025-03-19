#ifndef ARRAYSTACK2_H
#define ARRAYSTACK2_H

#include <stdio.h>
#include <stdlib.h>

typedef int Element;  // 요소 타입 정의
#define MAX_SIZE 100  // 최대 스택 크기

// 스택 구조체 정의
typedef struct {
    Element data[MAX_SIZE];
    int top;
} Stack;

// 에러 메시지 출력 후 프로그램 종료
void error(const char* str) {
    printf("%s\n", str);
    exit(1);
}

// 스택 초기화 함수
void init_stack(Stack* s) {
    s->top = -1;
}

// 스택이 비어있는지 확인
int is_empty(Stack* s) {
    return (s->top == -1);
}

// 스택이 가득 찼는지 확인
int is_full(Stack* s) {
    return (s->top == (MAX_SIZE - 1));
}

// 스택에 요소 추가 (Push)
void push(Stack* s, Element e) {
    if (is_full(s)) {
        error("Overflow Error! 스택이 가득 찼습니다.");
    }
    s->data[++(s->top)] = e;
}

// 스택에서 요소 제거 (Pop)
Element pop(Stack* s) {
    if (is_empty(s)) {
        error("Underflow Error! 스택이 비어 있습니다.");
    }
    return s->data[(s->top)--];
}

// 스택의 최상단 요소 확인 (Peek)
Element peek(Stack* s) {
    if (is_empty(s)) {
        error("Underflow Error! 스택이 비어 있습니다.");
    }
    return s->data[s->top];
}

#endif // ARRAYSTACK2_H

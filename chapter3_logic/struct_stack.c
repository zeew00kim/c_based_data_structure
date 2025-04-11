#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// 자료구조 3장 : 구조체와 스택을 사용한 값 뒤집기

struct Node {
    char name[32];
    int param;
};

typedef struct Node Element;
#include "array_stack.h"

int main() {

    Element call[4] = {
        { "main()" }, 
        {"factorial()", 3},
        {"factorial()", 2}, 
        {"factorial()", 1}
    };

    init_stack();

    printf("[ squencial function call ]\n");
    for (int i = 0; i < 4; i++) {
        push(call[i]);
        printf("%s, %d\n", call[i].name, call[i].param);
    }

    printf("[ sequencial function return ]\n");
    while (!is_empty()) {
        Element call = pop();
        printf("%s, %d", call.name, call.param);
    }
}
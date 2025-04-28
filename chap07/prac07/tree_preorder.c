#include <stdio.h>
#include <stdlib.h>

// 7장 실습 1 : 트리를 배열 표기법으로 구현하는 preorder() 함수 작성

typedef char TElement;
#define MAX_SIZE 100
TElement tree[MAX_SIZE] = {0, '1', '2', '3', 0, '4', '5'};

void preorder(int index);

int main() {
    preorder(1);
    puts("");

    return 0;
}

void preorder(int index) {
    if (tree[index] != 0) {
        printf("( ");
        printf("%c ", tree[index]);
        preorder(index*2);
        preorder(index*2 + 1);
        printf(") ");
    }
    else printf(".");
}
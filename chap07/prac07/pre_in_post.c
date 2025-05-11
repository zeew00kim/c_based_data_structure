#include <stdio.h>
#include <stdlib.h>

// 7장 실습 2번 문제 : 전위/중위/후위 순회 함수 구현

typedef char TElement;
#define MAX_SIZE 100
TElement tree[MAX_SIZE] = {0, '1', '2', '3', 0, '4', '5'};

void preorder(int idx) {
    if (idx >= MAX_SIZE || tree[idx] == 0) {
        return;
    }
    printf("[%c] ", tree[idx]);
    preorder(idx * 2);
    preorder(idx * 2 + 1);
}

void inorder(int idx) {
    if (idx >= MAX_SIZE || tree[idx] == 0) {
        return;
    }
    inorder(idx * 2);
    printf("[%c] ", tree[idx]);
    inorder(idx * 2 + 1);
}

void postorder(int idx) {
    if (idx >= MAX_SIZE || tree[idx] == 0) {
        return;
    }
    postorder(idx * 2);
    postorder(idx * 2 + 1);
    printf("[%c] ", tree[idx]);
}

int main() {
    
    printf("pre-order : ");
    preorder(1);
    puts("");

    printf("in-order : ");
    inorder(1);
    puts("");

    printf("post-order : ");
    postorder(1);
    puts("");
    
    return 0;
}
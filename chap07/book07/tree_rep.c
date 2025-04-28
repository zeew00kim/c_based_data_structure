#include <stdio.h>
#include <stdlib.h>

// 7장 p.255 : 동적 할당을 이용한 트리의 생성과 해제

typedef char charTree;
typedef struct Tree {
    charTree data;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* create_tree(charTree data, Tree* left, Tree *right);
void delete_tree(Tree*n);
void preorder(Tree *n);

int main() {

    // 첫 번째 트리를 동적 생성
    Tree *d = create_tree('D', NULL, NULL);
    Tree *e = create_tree('E', NULL, NULL);
    Tree *b = create_tree('B', d, e); // d를 left, e를 right 노드로 가짐
    Tree *f = create_tree('F', NULL, NULL);
    Tree *c = create_tree('C', f, NULL);
    Tree *root1 = create_tree('A', b, c);
    preorder(root1);
    puts("");

    // 두 번째 트리를 동적 생성
    Tree *D = create_tree('D', NULL, NULL);
    Tree *C = create_tree('C', D, NULL);
    Tree *B = create_tree('B', C, NULL);
    Tree *root2 = create_tree('A', B, NULL);
    preorder(root2);
    puts("");

    // 트리를 동적 해제
    delete_tree(root1);
    delete_tree(root2);

    return 0;
}

Tree* create_tree(charTree data, Tree* left, Tree *right) {
    Tree * n = (Tree*)malloc(sizeof(Tree)); // 루트 노드
    n->data = data;
    n->left = left;
    n->right = right;
    return n;
}

void delete_tree(Tree*n) {
    if (n != NULL) {
        delete_tree(n->left); // 왼쪽 서브 트리 삭제
        delete_tree(n->right); // 오른쪽 서브 트리 삭제
        free(n);
    }
}

void preorder(Tree *n) {
    if (n != NULL) {
        printf("( ");
        printf("%c ", n->data);
        preorder(n->left);
        preorder(n->right);
        printf(") ");
    }
    else {
        printf(". "); // 자식이 없을 경우(..), 자식이 하나만 있는 경우(.)
    }
}
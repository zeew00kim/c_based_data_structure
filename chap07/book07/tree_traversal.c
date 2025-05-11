#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;

#define VisitNode(n)(printf("[%c] ", (n)->data))

// root -> left(끝까지) -> right
void preorder(TNode *n) { 
    if (n == NULL) {
        return;
    }
    printf("( ");
    printf("%c", n->data);
    // VisitNode(n);
    preorder(n->left);
    preorder(n->right);
    printf(")");
}

// left -> root -> right
void inorder(TNode *n) {
    if (n == NULL) {
        return;
    }
    inorder(n->left);
    VisitNode(n);
    inorder(n->right);
}

// left -> right -> root
void postorder(TNode *n) {
    if (n == NULL) {
        return;
    }
    postorder(n->left);
    postorder(n->right);
    VisitNode(n);
}

#define MAX_SIZE 100
typedef TNode *Element;
#include "circular_queue.h"

void leverorder(TNode* root) {
    if (root != NULL) {
        init_queue();
        enqueue(root);
        while (!is_empty()) {
            TNode *n = dequeue();
            if (n != NULL) {
                VisitNode(n);
                enqueue(n->left);
                enqueue(n->right);
            }
        }
    }
}

int main() {

    TNode d = { 'D', NULL, NULL };
    TNode e = { 'E', NULL, NULL };
    TNode b = { 'B', &d, &e };
    TNode f = { 'F', NULL, NULL };
    TNode c = { 'C', &f, NULL };
    TNode a = { 'A', &b, &c };
    TNode *root = &a;

    printf("\n In-Order : ");
    inorder(root);

    printf("\n Pre-Order : ");
    preorder(root);

    printf("\n Post-Order : ");
    postorder(root);

    printf("\n Lever-Order : ");
    leverorder(root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// 7장 실습 3번 문제 : 전위 순회 / 트리 반전 / 높이 / 레벨

typedef char TElement;
typedef struct BTNode { 
    TElement data;
    struct BTNode* left;
    struct BTNode* right;
} TNode;

void preorder(TNode *root) {
    if (root == NULL) {
        printf(".");
        return;
    }
    printf("( ");
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
    printf(")");
}

int node_cnt(TNode* root) {
    if (root == NULL) return 0;
    return 1 + node_cnt(root->left) + node_cnt(root->right);
    // 루트 + left + right
}

int node_leaf(TNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) {
        return 1; // root의 자식이 없다면 1 리턴
    }
    return node_leaf(root->left) + node_leaf(root->right);
}

int tree_height(TNode *root) {
    if (root == NULL) return 0;
    int left = tree_height(root->left);
    int right = tree_height(root->right);
    return (left > right ? left : right) + 1;
    // left or right 중 길이가 깊은 방향을 선택 후 + 1(루트) 리턴
}

void reverse(TNode* root) {
    if (root == NULL) return;
    TNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    reverse(root->left);
    reverse(root->right);
}

int tree_level(TNode *root, TNode *target, int level) {
    if (root == NULL) return 0;
    if (root == target) return level;
    int l = tree_level(root->left, target, level + 1);
    if (l != 0) return 1;
    return tree_level(root->right, target, level + 1);
}

int main() {

    TNode d = { 'D', NULL, NULL };
    TNode e = { 'E', NULL, NULL };
    TNode b = { 'B', &d, &e };
    TNode f = { 'F', NULL, NULL };
    TNode c = { 'C', &f, NULL };
    TNode a = { 'A', &b, &c };
    TNode *root = &a;

    printf("tree : ");
    preorder(root);
    puts("");
    
    printf("node count : %d\n", node_cnt(root));
    printf("leaf count : %d\n", node_leaf(root));
    printf("tree hright : %d\n", tree_height(root));

    reverse(root);

    printf("reverse tree : ");
    preorder(root);
    puts("");

    printf("level of D : %d\n", tree_level(root, &d, 1));
    printf("level of C : %d\n", tree_level(root, &c, 1));
    printf("level of A : %d\n", tree_level(root, &a, 1));

    return 0;
}
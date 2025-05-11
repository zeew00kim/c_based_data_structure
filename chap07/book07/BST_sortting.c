typedef int TElement;
#include "treelinked.h"
#include "time.h"
#define visitNode(n)(printf("%d ", (n)->data)
#define KEY(n) (n->data)

TNode* search_bst(TNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (KEY(root) == key) {
        return root;
    }
    else if (key < KEY(root)) {
        return search_bst(root->left, key);
    }
    else {
        return search_bst(root->right, key);
    }
}

void insert_bst(TNode* root, TNode *n) {
    if (KEY(n) < KEY(root)) {
        if (root->left == NULL) {
            root->left = n;
        }
        else {
            insert_bst(root->left, n);
        }
    }
    else if (KEY(n) < KEY(root)) {
        if (root->right == NULL) {
            root->right = n;
        }
        else {
            insert_bst(root->right, n);
        }
    }
    else free(n);
}

TNode *delete_bst (TNode* root, int key) {
    TNode *n = root;
    TNode *parent = NULL;
    while (n != NULL && key != KEY(n)) {
        parent = n;
        n = (key < KEY(n)) ? n->left : n->right;
    }
    if (n == NULL) {
        return root;
    }

    if ((n->left == NULL && n->right == NULL)) {
        if (parent == NULL) {
            root = NULL;
        }
        else {
            if (parent->left == n) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        free(n);
    }
    else if (n->left == NULL || n->right == NULL) {
        TNode* child = (n->left != NULL) ? n->left : n->right;
        if (n == root) {
            root = child;
        }
        else {
            if (parent->left == n) {
                parent->left = child;
            }
        }
        free(n);
    }
    else {
        TNode* success = n->right;
        while (success->left != NULL) {
            success = success->left;
        }
        n->data = success->data;
        n->right = delete_bst(n->right, KEY(success));
    }
    return root;
}

void preorder(TNode *n) {
    if (n != NULL) {
        VisitNode(n);
        preorder(n->left);
        preorder(n->right);
    }   
}

int main() {

    srand(time(NULL));

    int key[10];
    
    for (int i = 0; i < 10; i++) {
        key[i] = rand() % 100 + 1;
    }
    TNode* root = create_tree(key[0], NULL, NULL);
    for (int i = 0; i < 10; i++) {
        TNode* n = create_tree(key[i], NULL, NULL);
        insert_bst(root, n);
        printf("insert value %2d : ", key[i]);
        preorder(root);
    }
    puts("");

    TNode *n = search_bst(root, key[3]);
    printf("find %d : %s\n", key[3], (n != NULL) ? "successed" : "failed");
    n = search_bst(root, 25);
    printf("find : %s\n", (n != NULL) ? "successed" : "failed");
    root = delete_bst(root, key[5]);
    printf("case01 : delete %d --> ", key[5]);
    preorder(root);
    root = delete_bst(root, key[0]);
    printf("case02 : root %d --> ", key[0]);
    preorder(root);

    return 0;
}
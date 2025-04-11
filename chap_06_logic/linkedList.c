#include "linkedList.h"

void print_list(char *msg);

int main() {

    init_list();
    insert(0, 10);
    insert(0, 20);
    insert(1, 30);
    insert(size(), 40);
    insert(2, 50);
    print_list("(삽입 * 5)");

    delete_node(2);
    delete_node(size() - 1);
    delete_node(0);
    print_list("(삭제 * 3)");
    destroy_list();

    return 0;
}

void print_list(char *msg) {
    for (Node* p = head; p != NULL; p = p->link) {
        printf("%2d ", p->data);
    }
}
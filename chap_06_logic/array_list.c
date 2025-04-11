#include "array_list.h"

void print_list(char *msg, ArrList list);
void concat(ArrList listA, ArrList listB, ArrList *result);

int main() {

    ArrList listA, listB, listC;

    init_list(&listA);
    init_list(&listB);
    init_list(&listC);

    insert(&listA, 0, 1);
    insert(&listA, 0, 2);

    print_list("listA : ", listA);

    insert(&listB, 0, 10);
    insert(&listB, 1, 20);

    print_list("listB : ", listB);

    concat(listA, listB, &listC);

    print_list("listC : ", listC);

    // delete(2);
    // delete(size - 1);
    // delete(0);
    // print_list("(delete * 3)");

    return 0;
}

void print_list(char *msg, ArrList list) {
    printf("array struct list %s[%2d] : ", msg, list.size);

    for (int i = 0; i < list.size; i++) {
        printf("%2d ", list.data[i]);
    }
    puts("");
}

void concat(ArrList listA, ArrList listB, ArrList *result) {
    for (int i = 0; i < listA.size; i++) {
        insert(result, i, listA.data[i]);
    }

    for (int i = 0; i < listB.size; i++) {
        insert(result, listA.size + i, listB.data[i]);
    }
}
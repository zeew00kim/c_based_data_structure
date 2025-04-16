#include "circ_struct_queue.h"

void print_queue(char *str);

int main() {

    init_queue();

    for (int i = 1; i < 7; i++) {
        enqueue(i);
    }
    print_queue("enqueue 1 ~ 6 : ");

    for (int i = 0; i < 4; i++) {
        dequeue();
    }
    print_queue("dequeue * 4 : ");

    for (int i = 7; i < 10; i++) {
        enqueue(i);
    }
    print_queue("enqueue 7 ~ 10 : ");

    destroy_queue();

    return 0;
}

void print_queue(char *str)  {
    printf("sizeof queue = %d, %s", size(), str);
    if (front != NULL) {   
        for (Node *p = front; p != NULL; p = p->link) {
            printf("%2d ", p->data);
        }
    }
    puts("");
}
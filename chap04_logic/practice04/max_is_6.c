#include "circ_queue.h"

void print_queue(char *str);
int is_size();

// 실습 4-1 : 최대 크기가 6인 큐
int main() {

    init_queue();

    for (int i = 1; i < 5; i++) {
        enqueue(i);
    }
    print_queue("enqueue 1 ~ 4 : ");

    for (int i = 0; i < 3; i++) {
        dequeue();
    }
    print_queue("dequeue X 3 : ");

    for (int i = 5; i < 8; i++) {
        enqueue(i);
    }
    print_queue("enqueue 5 ~ 8 : ");

    return 0;
}

void print_queue(char *str) {
    printf("%s, front = %d, rear = %d ==> ", str, front, rear);

    for (int i = front + 1; i <= front + is_size(); i++) {
        printf("%2d ", data[i % MAX_SIZE]);
    }
    puts("");
}

int is_size() {
    return (rear - front + MAX_SIZE) % MAX_SIZE;
}
#include "circular_queue.h"

void print_queue(char *str);

int main() {

    init_queue();

    for (int i = 1; i < 7; i++) {
        enqueue(i); // front와 rear값을 비워두고 갑을 삽입
    }
    print_queue("enequeue 1 ~ 6 : ");

    for (int i = 0; i < 4; i++) {
        dequeue();
    }
    print_queue("dequeue count 4 : ");

    for (int i = 7; i < 10; i++) {
        enqueue(i);
    }
    print_queue("enqueue 7 ~ 10 : ");

    return 0;
}

void print_queue(char *str) {
    
    printf("%s front : %d, rear : %d --> ", str, front, rear);

    int size = (rear - front + MAX_SIZE) % MAX_SIZE; // 원형 큐 요소의 개수

    for (int i = front + 1; i <= front + size; i++) {
        printf("%2d ", data[i % MAX_SIZE]);
    }
    puts("");
}
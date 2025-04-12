#include "circular_deque.h"

void print_deque(char *str);

int main() {

    init_deque();

    for (int i = 1; i < 10; i++) {
        if (i % 2 != 0) {
            add_front(i);
        } 
        else add_rear(i);
    }

    print_deque("circular deque odd-even : ");
    printf("delete_front() --> %d\n", delete_front());
    printf("delete_rear() --> %d\n", delete_rear());
    printf("delete_front() --> %d\n", delete_front());
    print_deque("delete circular deque odd-even-odd");

    return 0;
}

void print_deque(char *str) {
    printf("%s, front = %d, rear = %d --> ", str, front, rear);

    int size = (rear - front + MAX_SIZE) % MAX_SIZE;

    for (int i = front + 1; i <= front + size; i++) {
        printf("%2d ", data[i % MAX_SIZE]);
    }

    puts("");
}
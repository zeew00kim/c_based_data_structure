#include "dynamic_array_stack.h"

int main() {

    MAX_SIZE = 8;

    init_stack();

    puts("[ input ]");

    for (int i = 0; i < 50; i++) {
        printf("%d ", i);
        push(i);
    }

    puts("");

    puts("[ output ]");

    while (!is_empty()) {
        printf("%d ", pop());
    }

    puts("");

    free(data);

    return 0;
}
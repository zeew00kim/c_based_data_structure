#include "circ_deque.h"

int check(char *input);

int main() {

    char input[100];
    
    while (1) {
        printf("input string : ");
        scanf("%s", input);
        
        if (strcmp(input, "0") == 0) {
            break;
        }
        else printf("result : %s\n", check(input) ? "true" : "false");
    }

    return 0;
}

int check(char *input) {
    
    init_deque();

    for (int i = 0; i < strlen(input); i++) {
        add_rear(input[i]);
    }

    while ((front + 1) % MAX_SIZE != rear && front != rear) {
        char a = delete_front();
        char b = delete_rear();
        if (a != b) return 0;
    }

    return 1;
}
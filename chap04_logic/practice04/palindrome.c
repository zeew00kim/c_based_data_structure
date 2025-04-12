#include <stdbool.h>
#include "circ_queue.h"

bool check(const char *str);

// 실습 4-2 : 큐를 활용해 문자열의 회문 여부를 판단
int main() {

    int num;

    printf("enter the strlen : ");
    scanf("%d", &num);

    char *input = (char*)malloc(sizeof(char) * num);

    while (1) {
        printf("enter the string : ");
        scanf("%s", input);
        if (strcmp(input, "0") == 0) {
            break;
        }
        printf("result : %s\n", check(input) ? "true" : "false");
    }

    free(input);

    return 0;
}

// 큐를 통해 회문 여부를 확인하는 함수
bool check(const char *str) {
    init_queue();

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        enqueue(str[i]);
    }

    for (int i = 0; i < len; i++) {
        char deq = dequeue();
        char back = str[len - 1 - i];
        if (deq != back) {
            return false;
        }
    }
    return true;
}
#define MAX_SIZE 2000
typedef char Element;

#include "array_stack.h"

// 자료구조 3장 : 스택을 이용한 문자열 뒤집기
int main() {

    char *str = (char*)malloc(sizeof(char) * 200);

    init_stack();

    printf("enter the string : ");
    fgets(str, 200, stdin);

    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    printf("print string : ");
    while (!is_empty()) {
        putchar(pop());
    }
    puts("");

    free(str);

    return 0;
}
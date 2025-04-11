#define MAX_SIZE 100
typedef char Element;
#include "array_stack.h"

// 자료구조 3장 : 스택을 활용한 괄호 검사 프로그램

int checkMatch(char *exp);

int main() {

    char exp[4][80] = {
        "{A[(i + 1)] = 0;}", 
        "if((i == 0) && (j == 0)", 
        "while(n < 8)){n++;}", 
        "arr[(i + 1]) = 0;"
    };

    for (int i = 0; i < 4; i++) {
        int errCode = checkMatch(exp[i]);
        if (errCode == 0) {
            printf("%-20s -> no error\n", exp[i]);
        }
        else {
            printf("%-20s -> error(option %d violation)\n", exp[i], errCode);
        }
    }

    return 0;
}

int checkMatch(char *exp) {

    int i = 0;
    int pre;

    init_stack();

    while (exp[i] != '\0') {
        char ch = exp[i++];
        if (ch == '[' || ch == '(' || ch == '{') {
            push(ch); // 열린 괄호 문자일 시 스택에 추가
        }
        else if (ch == ']' || ch == ')' || ch == '}') {
            if (is_empty()) {
                return 2; // 스택이 공백일 시 조건 2 위반
            }

            pre = pop();

            if ((ch == ']' && pre != '[') || (ch == ')' && pre != '(') || (ch == '}' && pre != '{')) {
                return 3; // 괄호의 짝이 맞지 않을 시 조건 3 위반
            }
        }
    }

    if (!is_empty()) {
        return 1; // 반복문 종료 후 스택이 공백이 아니라면 괄호가 닫히지 않은 상태 : 조건 1 위반
    }
    else {
        return 0;
    }
}
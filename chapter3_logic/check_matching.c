#define MAX_SIZE 100
typedef char Element;
#include "array_stack.h"

int check_matching(char *exp);

int main() {

    // 문자열 선언 및 초기화
    char exp[4][80] = {
        "A(i+1) = 0;}",
        "if(i==0)) && (j==0)",
        "while (n < 8)) && (n++)",
        "arr[(i + 1) = 0"
    };

    // 문자열 개수만큼 에러 여부 검사
    for (int i = 0; i < 4; i++) {
        int errorCode = check_matching(exp);
        if (errorCode == 0) {
            printf("%-20s -> no error\n", exp[i]);
        }
        else {
            printf("%-20s -> error no.%d\n", exp[i], errorCode);
        }
    }

    return 0;
}

int check_matching(char *exp) {

    int i = 0;
    int pre;

    while (exp[i] != '\0') {

        char ch = exp[i++]; // ch의 값이 괄호가 아닐 시 continue
        
        if (ch == '[' || ch == '(' || ch == '{') {
            push(ch); // 열린 괄호일 경우 push
        }
        else if (ch == ']' || ch == ')' || ch == '}') {
            if (is_empty()) {
                return 2; // 닫는 괄호와 일치하는 열린 괄호가 없는 경우 2
            }

            pre = pop(); // 스택이 비어있지 않다면 pop;

            if ((ch == ']' && pre != '[') || (ch == ')' && pre != '(') || (ch == '}' && pre != '{')) {
                return 3; // 괄호의 짝이 맞지 않는 경우 3;
            }
        }
    }
    
    if (!is_empty()) {
        return 1; // 스택이 비어있지 않을 시 1 (괄호의 짝이 맞지 않는 문자열)
    }
    
    return 0; // 반복문 종료 후 스택이 비어있을 시 0 (괄호의 짝이 잘 맞는 문자열)
}
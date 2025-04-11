#define MAX_SIZE 100
typedef double Element;
#include "array_stack.h"

double eval_postfix(char *exp);

int main() {

    char exp[2][80] = {
        "2 2 / 3 - 3 2 * +", "1 2 / 4 * 1 4 / *"
    };

    printf("formula %s = %.2lf\n", exp[0], eval_postfix(exp[0]));
    printf("formula %s = %.2lf\n", exp[1], eval_postfix(exp[1]));

    return 0;
}

double eval_postfix(char *exp) {

    int i = 0;

    init_stack();

    while (exp[i] != '\0') {
        
        char c = exp[i++];

        if (c >= '0' && c <= '9') {
            double num = (double)c - '0';
            push(num);
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            double val2 = pop();
            double val1 = pop();
            switch (c) {
                case '+':
                push(val1 + val2);
                break;
                case '-':
                push(val1 - val2);
                break;
                case '*':
                push(val1 * val2);
                break;
                case '/':
                push(val1 / val2);
                break;
            }
        }
    }
    return pop();
}
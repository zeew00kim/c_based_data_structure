#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef double Element;
#include "ArrayStack.h"

double eval_postfix(char* expr);

int main() {

	char expr[2][80] = { "8 2 / 3- 3 2 * +", "1 2 / 4 * 1 4 / *" };

	for (int i = 0; i < 2; i++) {
		printf("수식 : %s = %.2lf\n", expr[i], eval_postfix(expr[i]));
	}

	return 0;
}

double eval_postfix(char* expr) {

	int i = 0;

	init_stack();
	
	while (expr[i] != '\0') {
		char c = expr[i++];
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
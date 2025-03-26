#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef double Element;
#include "ArrayStack.h"

char* infix_to_postfix(char* expr);
int precedence(char op);
void print(char data);
double eval_postfix(char* expr);
char postfix[100] = "";

int main() {

	char expr[2][80] = { "8 / 2 - 3 + (3 * 2)", "1 / 2 * 4 * (1 / 4)" };

	printf("result : %.2lf\n", (double)(eval_postfix(infix_to_postfix("(2+3)*4+9"))));

	return 0;
}

char* infix_to_postfix(char* expr) {

	init_stack();

	int i = 0;
	while (expr[i] != '\0') {
		char c = expr[i++];
		if (c >= '0' && c <= '9') {
			print(c);
		}
		else if (c == '(') {
			push(c);
		}
		else if (c == ')') {
			while (is_empty() == 0) {
				char op = pop();
				if (op == '(') {
					break;
				}
				else {
					print(op);
				}
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (is_empty() == 0) {
				char op = peek();
				if (precedence(c) <= precedence(op)) {
					print(op);
					pop();
				}
				else {
					break;
				}
			}
			push(c);
		}
	}
	while (is_empty() == 0) {
		print(pop());
	}
	return postfix;
}

int precedence(char op) {
	switch (op) {
	case '(': case ')':
		return 0;
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	default:
		return -1;
	}
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

void print(char data) {
	char str[3] = { data, ' ', '\0' };
	strcat(postfix, str);
}
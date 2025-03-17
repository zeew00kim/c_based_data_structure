#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#define MAX_DEGREE 1001

typedef struct {
	int deg; // 지수
	double coef[MAX_DEGREE]; // 계수
} Polynomial;

Polynomial add(Polynomial a, Polynomial b);
void print_polynomial(Polynomial a, char* str);
int deg(Polynomial p);
double coef(Polynomial p, int i);
double evaluate(Polynomial p, double x);

int main() {

	Polynomial a = { 5, {2, 6, 0, 0, 0, 10} };
	Polynomial b = { 4, {7, 0, 5, 0, 1} };
	Polynomial c = add(a, b);
	print_polynomial(a, "A = ");
	print_polynomial(b, "B = ");
	print_polynomial(c, "A + B = ");
	printf("A(1) = %.2lf\n", evaluate(a, 1.0));
	printf("B(1) = %.2lf\n", evaluate(b, 2.0));

	return 0;
}

Polynomial add(Polynomial a, Polynomial b) {
	Polynomial p;
	p.deg = (a.deg > b.deg) ? a.deg : b.deg;

	for (int i = 0; i <= p.deg; i++) {
		p.coef[i] = ((i <= a.deg) ? a.coef[i] : 0) + ((i <= b.deg) ? a.coef[i] : 0);
	}

	return p;
}

void print_polynomial(Polynomial p, char* str) {
	printf("%s", str);
	for (int i = p.deg; i > 0; i--) {
		printf("%3.1lf x^%d + ", p.coef[i], i);
	}
	printf("%3.1lf\n", p.coef[0]);

}

int deg(Polynomial p) {
	return p.deg;
}

double coef(Polynomial p, int i) {
	return p.coef[i];
}

double evaluate(Polynomial p, double x) {
	double res = p.coef[0];
	double mul = 1;
	for (int i = 1; i <= p.deg; i++) {
		mul *= x;
		res += p.coef[i] * mul;
	}
}
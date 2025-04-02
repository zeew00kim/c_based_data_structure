#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX_TERMS 10 // 최대 항의 개수

typedef struct {
	int exponent; // 차수
	double coefficient; // 계수
} Term;

typedef struct {
	int num_terms; // 다항식에 포함된 항의 개수
	Term terms[MAX_TERMS]; // 항 배열
} SparsePoly;

void print_spoly(SparsePoly poly, char* msg);
SparsePoly add(SparsePoly a, SparsePoly b);
SparsePoly sub(SparsePoly a, SparsePoly b);
double evaluate(SparsePoly poly, double x);

int main() {

	// 다항식 A = 10.0 * x^100 + 2.0 * x^50 + 6.0 * x^0
	SparsePoly a = { 3, {{100, 10.0}, {50, 2.0}, {0, 6.0}} };
	SparsePoly b = { 2, {{50, 1.1}, {3, 2.0}} };

	// 다항식 출력
	print_spoly(a, "A = ");
	print_spoly(b, "B = ");

	// 다항식 덧셈 A + B
	SparsePoly c = add(a, b);
	print_spoly(c, "A+B = ");

	// 다항식 뺄셈 A - B
	c = sub(a, b);
	print_spoly(c, "A-B = ");

	// 다항식 값 평가 (x = 1)
	printf("A(1) = %.1lf\n", evaluate(a, 1.0));
	printf("B(1) = %.1lf\n", evaluate(b, 1.0));
	printf("A - B(1) = %.1lf\n", evaluate(c, 1.0));

	return 0;
}

void print_spoly(SparsePoly poly, char* msg) {
	printf("%s", msg);
	for (int i = 0; i < poly.num_terms; i++) {
		if (i > 0) {
			printf(" + ");
		}
		printf("%.1lf x^%d", poly.terms[i].coefficient, poly.terms[i].exponent);
	}
	puts("");
}

SparsePoly add(SparsePoly a, SparsePoly b) {
	SparsePoly result;
	result.num_terms = 0;

	// 각각 다항식 A, B의 현재 항을 가리키는 인덱스
	// 지수를 비교하여 큰 지수를 가진 항을 결과에 추가
	// 동일한 지수를 가지면 계수를 더해서 추가
	// 최종적으로 SparsePoly 형태의 결과 반환
	int i = 0, j = 0;
	while (i < a.num_terms || j < b.num_terms) {
		if (j >= b.num_terms || (i < a.num_terms && a.terms[i].exponent > b.terms[j].exponent)) {
			result.terms[result.num_terms++] = a.terms[i++];
		}
		else if (i >= a.num_terms || (j < b.num_terms && a.terms[i].exponent < b.terms[j].exponent)) {
			result.terms[result.num_terms++] = b.terms[j++];
		}
		else {
			double sum = a.terms[i].coefficient + b.terms[j].coefficient;
			if (sum != 0) {
				result.terms[result.num_terms].exponent = a.terms[i].exponent;
				result.terms[result.num_terms].coefficient = sum;
				result.num_terms++;
			}
			i++, j++;
		}
	}
	return result;
}

SparsePoly sub(SparsePoly a, SparsePoly b) {
	SparsePoly result;
	result.num_terms = 0;

	// 덧셈과 동일한 방식으로 지수 비교
	// B의 항이 A에 없으면 부호 바꿔서 추가
	int i = 0, j = 0;
	while (i < a.num_terms || j < b.num_terms) {
		if (j >= b.num_terms || (i < a.num_terms && a.terms[i].exponent > b.terms[j].exponent)) {
			result.terms[result.num_terms++] = a.terms[i++];
		}
		else if (i >= a.num_terms || (j < b.num_terms && a.terms[i].exponent < b.terms[j].exponent)) {
			result.terms[result.num_terms].exponent = b.terms[j].exponent;
			result.terms[result.num_terms].coefficient = -b.terms[j].coefficient; // 부호 반전
			result.num_terms++;
			j++;
		}
		else {
			double diff = a.terms[i].coefficient - b.terms[j].coefficient;
			if (diff != 0) {
				result.terms[result.num_terms].exponent = a.terms[i].exponent;
				result.terms[result.num_terms].coefficient = diff;
				result.num_terms++;
			}
			i++, j++;
		}
	}
	return result;
}

// 다항식 평가 = 주어진 x 값에 대해 `계수 * x^지수` 계산 후 합산
double evaluate(SparsePoly poly, double x) {
	double result = 0;
	for (int i = 0; i < poly.num_terms; i++) {
		result += poly.terms[i].coefficient * pow(x, poly.terms[i].exponent);
	}
	return result;
}
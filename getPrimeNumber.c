#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int getPrimeNumber(int cnt, int primeCnt);

int main() {

	int cnt = 0;
	int primeCnt = 0;
	clock_t start, end;
	start = clock();

	primeCnt = getPrimeNumber(cnt, primeCnt);

	printf("소수의 개수는 %d개입니다.\n", primeCnt);
	end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("소요 시간 = %.2lf초\n", duration);

	return 0;
}

int getPrimeNumber(int cnt, int primeCnt) {

	for (int i = 2; i < 10000; i++) {
		cnt = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				cnt++;
			}
		}
		if (cnt <= 2) {
			printf("%d ", i);
			primeCnt++;
		}
	}
	puts("");
	return primeCnt;
}
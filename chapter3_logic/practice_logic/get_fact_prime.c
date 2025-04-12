#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n, int div);

// 실습 3-3 : 정수를 입력 받아 순환함수를 통해 소수 구하기
int main() {

    int num;

    do {
        printf("enter the number : ");
        scanf("%d", &num);
        if (num <= 0) {
            puts("retry...");
        }
    } while (num <= 0);

    for (int i = 0; i <= num; i++) {
        if (isPrime(i, i -1)) {
            printf("%d ", i);
        }
    }
    return 0;
}

bool isPrime(int n, int div) {
    if (n <= 1 ) return false;
    if (div == 1) return true;
    if (n % div == 0) return false;
    return isPrime(n, div - 1);
}
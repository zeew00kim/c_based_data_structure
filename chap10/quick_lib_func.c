#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// c언어 라이브러리 qsort() 함수를 사용한 퀵소트

int compare(const void *arg1, const void *arg2) {
    if (*(double*)arg1 > *(double*)arg2) {
        return 1; // 앞에 값이 뒤에 값보다 큰 경우 1
    }
    else if (*(double*)arg1 < *(double*)arg2) {
        return -1; // 앞에 값이 뒤에 값보다 작은 경우 -1
    }
    else {
        return 0; // 같으면 0 
    }
}

int main() {

    int len;

    printf("enter the len : ");
    scanf("%d", &len);

    double *list = (double*)malloc(sizeof(double) * len);

    srand(time(NULL));

    for (int i = 0; i < len; i++) {
        list[i] = rand() % 10 + 1;
    }

    printf("before : ");
    for (int i = 0; i < len; i++) {
        printf("%4.1lf ", list[i]);
    }
    puts("");

    qsort((void *)list, len, sizeof(double), compare);

    printf("after : ");
    for (int i = 0; i < len; i++) {
        printf("%4.1lf ", list[i]);
    }
    puts("");

    free(list);

    return 0;
}
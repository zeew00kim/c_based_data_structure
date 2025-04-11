#include "multi_stack.h"

void quickSort(int *arr, int left, int right);

// 3장 실습 정렬된 2중 스택 값 출력하기
int main() {

    int num;
    int initCnt = 1;

    srand(time(NULL));

    printf("enter the array length : ");
    scanf("%d", &num);

    int *arr = (int*)malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++) {
        arr[i] = rand() % 10 + 1;
    }

    quickSort(arr, 0, num -1);

    Stack s1, s2;

    init_stack(&s1, &initCnt);
    init_stack(&s2, &initCnt);

    printf("input data : ");
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
        push(&s1, arr[i]);
    }

    puts("");

    printf("output data of s1 : ");
    while (!is_empty(&s1)) {
        printf("%d ", peek(&s1));
        push(&s2, pop(&s1));
    }

    puts("");

    printf("output data of s2 : ");
    while (!is_empty(&s2)) {
        printf("%d ", pop(&s2));
    }

    puts("");

    free(arr);

    return 0;
}

void quickSort(int *arr, int left, int right) {

    if (left >= right) {
        return;
    }

    int pivot = arr[(left + right) / 2];
    int checkLeft = left;
    int checkRight = right;
    int temp;

    do {
        while (arr[checkLeft] < pivot) {
            checkLeft++;
        }
        while (arr[checkRight] > pivot) {
            checkRight--;
        }
        if (checkLeft <= checkRight) {
            temp = arr[checkLeft];
            arr[checkLeft] = arr[checkRight];
            arr[checkRight] = temp;
            checkLeft++;
            checkRight--;
        }
    } while (checkLeft <= checkRight);

    quickSort(arr, left, checkRight);
    quickSort(arr, checkLeft, right);
}
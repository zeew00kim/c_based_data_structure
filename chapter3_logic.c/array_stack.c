#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

typedef int Element; // int 자료형에 별칭 부여
#include "array_stack.h"

void selectionSort(int *arr, int size);

int main() {

    int num;

    printf("enter the size of array : ");
    scanf("%d", &num);

    srand(time(NULL));

    Element *arr = (int*)malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++) {
        arr[i] = rand() % 10 + 1;
    }

    selectionSort(arr, num);

    init_stack();

    puts("[ stack test ]");
    printf("input data : ");

    for (int i = 0; i < num; i++) {
        printf(" %d", *(arr + i));
        push(arr[i]);
    }

    puts("");

    printf("output data : ");

    while(!is_empty()) {
        printf(" %d", pop());
    }

    puts("");

    return 0;
}

void selectionSort(int *arr, int size) {

    for (int i = 0; i < size -1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}
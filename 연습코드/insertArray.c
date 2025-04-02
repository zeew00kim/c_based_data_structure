#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *arr, int left, int right);
void printArr(int *arr, int size);
void insert(int *arr, int size);

// 배열 정렬 및 원하는 인덱스 번호에 새로운 값 삽입
int main() {

    int num;

    printf("enter the size of array : ");
    scanf("%d", &num);

    srand(time(NULL));

    int *arr = (int*)malloc(sizeof(int) * num);

    printf("initial array : ");
    for (int i = 0; i < num; i++) {
        arr[i] = rand() % 10 + 1;
        printf("%d ", arr[i]);
    }

    puts("");

    quickSort(arr, 0, num - 1);
    printArr(arr, num);
    insert(arr, num);

    free(arr);

    return 0;
}

void quickSort(int *arr, int left, int right) {

    if (left >= right) {
        return;
    }

    int pivot = arr[(right + left) / 2];
    int checkLeft = left;
    int checkRight = right;
    int temp;

    do {
        while(arr[checkLeft] < pivot) {
            checkLeft++;
        }
        while(arr[checkRight] > pivot) {
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

void printArr(int *arr, int size) {

    printf("sortted array : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    puts("");
}

void insert(int *arr, int size) {

    int idx, value;
    printf("enter the idx : ");
    scanf("%d", &idx);
    printf("enter the value : ");
    scanf("%d", &value);

    for (int i = size - 1; i >= idx; i--) {
        arr[i + 1] = arr[i];
    }
    arr[idx] = value;
    size++;

    printf("insert value in array : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
#define MAX_SIZE 1024
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right) {
    static int temp[MAX_SIZE];
    int i = left;
    int j = mid+1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++]=arr[i++];
    }
    while (j <= right) {
        temp[k++]=arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void printArr(int *arr, int size, char *str) {
    printf("%s", str);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {

    int len;
     
    printf("enter the len : ");
    scanf("%d", &len);

    srand(time(NULL));

    int *arr = (int*)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 10 + 1;
    }

    mergeSort(arr, 0, len - 1);
    printArr(arr, len, "result of mergeSort : ");

    free(arr);

    return 0;
}
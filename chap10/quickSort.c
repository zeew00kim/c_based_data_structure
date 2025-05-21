#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *p, int left, int right) {
    
    if (left >= right) {
        return;
    }
    
    int pivot = p[(left + right) / 2];
    int checkLeft = left;
    int checkRight = right;
    int temp;

    do {
        while (p[checkLeft] < pivot) {
            checkLeft++;
        }
        while (p[checkRight] > pivot) {
            checkRight--;
        }
        if (checkLeft <= checkRight) {
            temp = p[checkLeft];
            p[checkLeft] = p[checkRight];
            p[checkRight] = temp;
            checkLeft++;
            checkRight--;
        }
    } while (checkLeft <= checkRight);

    quickSort(p, left, checkRight);
    quickSort(p, checkLeft, right);
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

    quickSort(arr, 0, len - 1);
    printArr(arr, len, "result of quickSort : ");

    free(arr);

    return 0;
}
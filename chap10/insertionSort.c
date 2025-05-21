#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void printList(int *p, int size, char *str) {
    printf("%s", str);
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p+i));
    }
    puts("");
}

void insertionSort(int *p, int size) {
    // 배열의 인덱스가 0이될 때까지 계속 비교
    for (int i = 1; i < size; i++) {
        int key = p[i];
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (p[j] > key) {
                p[j + 1] = p[j];
            }
            else break;
        }
        p[j + 1] = key;
    }
}

int main() {

    int len; 

    printf("enter the list len : ");
    scanf("%d", &len);

    int *list = (int*)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        list[i] = rand() % 100 + 1;
    }

    printList(list, len, "Original : ");
    insertionSort(list, len);
    printList(list, len, "result of SelectionSort : ");

    return 0;
}
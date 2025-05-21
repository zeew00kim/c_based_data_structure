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

// 시간복잡도 = O(n^2) / 제자리 정렬 = 안정성 만족 X
void selectionSort(int *p, int size) {
    int minIdx; 
    for (int i = 0; i < size - 1; i++) { 
        minIdx = i; 
        for (int j = i + 1; j < size; j++) {
            if (p[minIdx] < p[j]) {
                minIdx = j; // 각각의 모든 요소마다 최소 값을 탐색 n(n-1)/2회 비교
            }
        }
        int temp = p[i];
        p[i] = p[minIdx];
        p[minIdx] = temp;
    }
}

int main() {

    int len; // 자료 이동 횟수가 미리 결정

    printf("enter the list len : ");
    scanf("%d", &len);

    int *list = (int*)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        list[i] = rand() % 100 + 1;
    }

    printList(list, len, "Original : ");
    selectionSort(list, len);
    printList(list, len, "result of SelectionSort : ");

    return 0;
}
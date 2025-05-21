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

void bubbleSort(int *p, int size) {
    
    for (int i = 0; i < size; i++) {
        int swapCnt = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (p[j] > p[j+1]) {
                int temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                swapCnt++;
            }
        }
        if (swapCnt == 0) {
            break;
        }
    }

    printList(p, size, "result of bubbleSort : ");
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
    bubbleSort(list, len);

    return 0;
}
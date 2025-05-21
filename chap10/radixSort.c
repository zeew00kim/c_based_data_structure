#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

typedef int Element;
#include "queueStruct.h"

void printStep (int *p, int len, int val) {
    printf("   Step %2d : ", val);
    for (int i = 0; i < len; i++) {
        printf("%5d", p[i]);
    }
    puts("");
}

void printArr(int *p, int len, char *str) {
    printf("%s", str);
    for (int i = 0; i < len; i++) {
        printf("%5d", p[i]);
    }
    puts("");
}

#define BUCKET 10
#define DIGIT 4
void radixSort(int *p, int len) {
    Queue queue[BUCKET];
    for (int b = 0; b < BUCKET; b++) {
        init_queue(&queue[b]);
    }

    int factor = 1;

    for (int d = 0; d < DIGIT; d++) {
        for (int i = 0; i < len; i++) {
            int id = (p[i] / factor) % BUCKET;
            enqueue(&queue[id], p[i]);
        }

        int i = 0;

        for (int b = 0; b < BUCKET; b++) {
            while (!is_empty(&queue[b])) {
                p[i++] = dequeue(&queue[b]);
            }
        }
        factor *= BUCKET;
        printStep(p, len, d + 1);
    }
}

int main() {

    srand(time(NULL));

    int len;

    printf("enter the len : ");
    scanf("%d", &len);

    int *list = (int*)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        list[i] = rand() % 100 + 1;
    }

    printArr(list, len, "original : ");

    free(list);
    radixSort(list, len);

    return 0;
}
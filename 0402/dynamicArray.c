#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_array(int* data, int size);
void print_array(int* data, int size);
double average_array(int* data, int size);

int main() {

    int size;
    printf("enter the array length : ");
    scanf("%d", &size);

    int* data = (int*)malloc(sizeof(int) * size);

    rand_array(data, size);
    print_array(data, size);

    double avg = average_array(data, size);

    printf("average of data array : %.2lf\n", avg);

    free(data);

    return 0;
}

void rand_array(int* data, int size) {

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100 + 1;
    }
}

void print_array(int* data, int size) {

    printf("data[%d] = { ", size);
    for (int i = 0; i < size; i++) {
        printf("%d", data[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

double average_array(int* data, int size) {

    int sum = 0;
    int res;

    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    printf("%d", sum);

    res = (double)(sum / size);

    return res;
}
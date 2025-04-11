#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int (*p)[4]);
void bubbleSort(int *p, int size);
void selectionSort(int *p, int size);
void insertSort(int *p, int size);
void quickSort(int *p, int left, int right);

int main() {

  int choice;
  char word[20];
  int arr[3][4];
  int num = sizeof(arr) / sizeof(arr[0][0]);

  srand(time(NULL));

  do {

    puts("");

    printf("[ Initial Random Array ]\n");
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        arr[i][j] = rand() % 100 + 1;
      }
    }

    int(*p)[4];
    p = arr;

    printArray(p);

    puts("");

    printf("[ choose the Sortting method ]\n");
    printf("|  \t0. exit             |\n");
    printf("|  \t1. bubbleSort       |\n");
    printf("|  \t2. selectionSort    |\n");
    printf("|  \t3. insertionSort    |\n");
    printf("|  \t4. quickSort        |\n");
    printf("\n select one (0 ~ 4) : ");

    scanf("%d", &choice);
    printf("_________________________\n");

    puts("");

    if (choice == 0) {
      printf("end of programming...\n");
    } else {
      switch (choice) {
      case 1:
        printf("[ result of bubbleSort ]\n");
        bubbleSort(p, num);
        printArray(p);
        break;
      case 2:
        printf("[ result of SelectionSort ]\n");
        selectionSort(p, num);
        printArray(p);
        break;
      case 3:
        printf("[ result of insertSort ]\n");
        insertSort(p, num);
        printArray(p);
        break;
      case 4:
        printf("[ result of quickSort ]\n");
        quickSort(p, 0, num - 1);
        printArray(p);
        break;
      default:
        printf("inputMismatchException\n");
        break;
      }
    }
  } while (choice != 0 && choice <= 4);

  return 0;
}

void printArray(int (*p)[4]) {

  for (int i = 0; i < 3; i++) {
    printf("arr[%d] = { ", i);
    for (int j = 0; j < 4; j++) {
      printf("%d", p[i][j]);
      if (j != 3) {
        printf(", ");
      } else if (j == 3) {
        printf("}\n");
      }
    }
  }
  printf("_________________________\n");
}

void bubbleSort(int *p, int size) {

  int swapCnt;

  for (int i = 0; i < size; i++) {
    swapCnt = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (p[j] > p[j + 1]) {
        int temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
        swapCnt++;
      }
    }
    if (swapCnt == 0) {
      break;
    }
  }
}

void selectionSort(int *p, int size) {
// 인덱스 번호 크기를 먼저 비교 후 나중에 값을 변경
  for (int i = 0; i < size - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < size; j++) {
      if (p[j] < p[minIdx]) {
        minIdx = j;
      }
    }
    int temp = p[i];
    p[i] = p[minIdx];
    p[minIdx] = temp;
  }
}

void insertSort(int *p, int size) {
// arr[0]이 될 때까지 계속 비교
  for (int i = 1; i < size; i++) {
    int key = p[i];
    int j = i - 1;
    while (j >= 0 && p[j] > key) {
      p[j + 1] = p[j];
      j--;
    }
    p[j + 1] = key;
  }
}

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
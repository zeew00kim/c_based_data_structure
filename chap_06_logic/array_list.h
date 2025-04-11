#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef int Element;
typedef struct {
    Element data[MAX_SIZE];
    int size;
} ArrList;

Element data[MAX_SIZE];

int size = 0;

void error(char *str) {
    puts(str);
    exit(1);
}

// 리스트의 연산들
void init_list(ArrList *pList) {
    pList->size = 0;
}

int is_empty(ArrList list) {
    return list.size == 0;
}

int is_full(ArrList list) {
   return list.size == MAX_SIZE;
}

// 삽입 연산 (구조체 활용)
void insert(ArrList *pList, int pos, Element e) {
    if (is_full(*pList)) {
        error("overflow error1");
    }
    if (pos < 0 || pos > pList->size) {
        error("invalid position error!");
    }
    for (int i = pList->size - 1; i >= pos; i--) {
        pList->data[i + 1] = pList->data[i];
    }
    pList->data[pos] = e;
    ++pList->size;
}

// 삭제 연산
// Element delete(int pos) {
//     if (is_empty()) {
//         error("underflow error!");
//     }

//     if (pos < 0 || pos > size) {
//         error("Invalid Position Error!");
//     }

//     Element e = data[pos];

//     for (int i = pos + 1; i < size; i++) {
//         data[i - 1] = data[i];
//     }
//     size -= 1;

//     return e;
// }

// 참조 연산
// Element get_entry(int pos) {
//     if (is_empty()) {
//         error("underflow error!");
//     }
//     if (pos < 0 || pos > size) {
//         error("Invalid Position Error!");
//     }
//     return data[pos];
// }
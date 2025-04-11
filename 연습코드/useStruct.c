#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 안에 다른 구조체를 선언하는 코드 로직
typedef struct {
    int age;
    double height;
} profile;

typedef struct {
    profile pf;
    int id;
    int grade;
    char* intro; // 포인터 변수는 malloc을 사용해 메모리 할당
} std;

void printStructValues(std* temp);

int main() {

    std zeew00;
    int choice;

    do {
        printf("[ choose the number 0 or 1 ]\n");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("end of input value...");
            break;
        }
        else {
            switch (choice) {
            case 1:
                printf("[ enter the age ]\n");
                scanf("%d", &zeew00.pf.age);
                getchar();
                printf("[ enter the height ]\n");
                scanf("%lf", &zeew00.pf.height);
                getchar();
                printf("[ enter the id ]\n");
                scanf("%d", &zeew00.id);
                getchar();
                printf("[ enter the grade ]\n");
                scanf("%d", &zeew00.grade);
                getchar();
            default:
                printf("[ enter the introduce ]\n");
                zeew00.intro = (char*)malloc(sizeof(char) * 20);
                gets(zeew00.intro);
                break;
            }
            printStructValues(&zeew00);
            free(zeew00.intro);
        }
    } while (choice != 0 && choice <= 1);

    return 0;
}

void printStructValues(std* temp) {
    printf("std age = %d\n", temp->pf.age);
    printf("std height = %.2lf\n", temp->pf.height);
    printf("std id = %d\n", temp->id);
    printf("std grade = %d\n", temp->grade);
    printf("std intro = %s\n", temp->intro);
}
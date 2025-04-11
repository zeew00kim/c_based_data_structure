#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printScore(int(*score)[3][4], char(*name)[3][20]);
void printAverage(double avg);

int main() {

    // 2면, 3행, 4열
    int score[2][3][4];
    char name[2][3][20]; // 6명의 이름

    for (int i = 0; i < 2; i++) {
        printf("[ No.%d  Class ]\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("No.%d student name : ", j + 1);
            scanf("%s", name[i][j]);
            printf("[ student %s's scores ]\n", name[i][j]);
            for (int k = 0; k < 4; k++) {
                printf("no.%d score : ", k + 1);
                scanf("%d", &score[i][j][k]);
            }
        }
    }

    puts("");
    printf("< each scores of all students >\n");
    puts("");
    printScore(score, name);

    return 0;
}

void printScore(int(*score)[3][4], char(*name)[3][20]) {

    double avg = 0.0;
    int total;

    for (int i = 0; i < 2; i++) {
        printf("[ class no.%d ]\n", i + 1);
        puts("");
        for (int j = 0; j < 3; j++) {
            printf("[ student %s's scores ]\n", name[i][j]);
            total = 0;
            for (int k = 0; k < 4; k++) {
                printf("no.%d score : %d\n", k + 1, score[i][j][k]);
                total += score[i][j][k];
            }
            avg = (double)total / 4;
            printf("average score of student %s = ", name[i][j]);
            printAverage(avg);
            puts("");
        }
    }
    puts("");
}

void printAverage(double avg) {

    printf("%.2lf", avg);
    puts("");
}
#include <stdio.h>
#include <string.h>

void compareString(char(*imitation)[20]);
void printString(char(*name)[20]);

int main() {

    char name[5][20];
    char imitation[5][20];

    printf("[ enter your name into the string ]\n");
    for (int i = 0; i < 5; i++) {
        printf("no.%d name = ", i + 1);
        scanf("%s", name[i]);
        strcpy(imitation[i], name[i]);
    }

    puts("");

    compareString(imitation);
    printf("[ sequintial string list ]\n");
    printString(name);
    puts("");
    printf("[ Sortted String list ]\n");
    printString(imitation);

    return 0;
}

void compareString(char(*imitation)[20]) {

    int swapCnt;

    for (int i = 0; i < 5; i++) {
        swapCnt = 0;
        for (int j = 0; j < 5 - i - 1; j++) {
            if (strcmp(imitation[j], imitation[j + 1]) > 0) {
                char temp[20];
                strcpy(temp, imitation[j]);
                strcpy(imitation[j], imitation[j + 1]);
                strcpy(imitation[j + 1], temp);
                swapCnt++;
            }
        }
        if (swapCnt == 0) {
            break;
        }
    }
}

void printString(char(*name)[20]) {

    for (int i = 0; i < 5; i++) {
        printf("no.%d student name = %s\n", i + 1, name[i]);
    }
}
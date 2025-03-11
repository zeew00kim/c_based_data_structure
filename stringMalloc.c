#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// test logic
// int main() {

// 	char temp[80];
// 	char* str[3];

// 	for (int i = 0; i < 3; i++) {
// 		printf("[ 문자열을 입력 ]\n");
// 		gets(temp);
// 		// strlen 함수는 문자열의 널 값을 제외한 길이를 반환
// 		str[i] = (char*)malloc(strlen(temp) + 1);
// 		strcpy(str[i], temp); // 널 값을 포함한 만큼의 메모리 공간을 할당하고 복사
// 		puts(*(str+i));
// 		free(str[i]);
// 	}

// 	return 0;
// }

void printString(char **str);

int main() {

    char temp[80];
    char *str[21] = { 0 };
    int i = 0;

    while (i < 20) {
        printf("enter your string : ");
        gets(temp);
        if (strcmp(temp, "end") == 0) {
            puts("end of programm...\n");
            break;
        }
        else {
            *(str + i) = (char*)malloc(strlen(temp) + 1);
            if (str[i] == NULL) {
                puts("malloc fail...");
                break;
            }
            strcpy(str[i], temp);
            i++;
        }
    }

    printString(str);

    for (int i = 0; str[i] != NULL; i++) {
        free(str[i]);
    }

    return 0;
}

void printString(char **str) {

    while (*str != NULL) {
        puts(*str);
        str++;
    }
}
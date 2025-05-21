#include <stdio.h>
#include <stdlib.h>
#define MAX_VSIZE 100
typedef char VElement;

int vsize = 5;

VElement vdata[MAX_VSIZE] = { 'U', 'V', 'W', 'X', 'Y' };

int adj[MAX_VSIZE][MAX_VSIZE] = {
    {0, 1, 1, 0, 0}, 
    {1, 0, 1, 1, 0}, 
    {1, 1, 0, 0, 0}, 
    {0, 1, 0, 0, 0}, 
    {0, 0, 1, 0, 0},
};

int degree(int v) {
    int cnt = 0;
    for (int i = 0; i < vsize; i++) {
        if (adj[v][i] == 1) {
            cnt++;
        } 
    }
    return cnt;
}

int main() {
    printf("adjarcent matrix of graph\n");
    for (int i = 0; i < vsize; i++) {
        printf("vertex %c, degree %d : ", vdata[i], degree(i));
        for (int j = 0; j < vsize; j++) {
            printf("%2d", adj[i][j]);
        }
        puts("");
    }
}
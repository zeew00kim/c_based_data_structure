// 8장 실습 1 : 인접 리스트 표현 사용한 DFS, BFS 구현

#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

#define MAX_VSIZE 100
#define PrintVtx(i) (printf("%c ", vdata[i]))
int visited[MAX_VSIZE];

typedef char VElement;
typedef struct GNode {
    int id;
    struct GNode* link;
} GNode;

int vsize = 0;
VElement vdata[MAX_VSIZE];
GNode* adj[MAX_VSIZE];

void init_graph() {
    vsize = 0;
    for (int i = 0; i < MAX_VSIZE; i++) {
        adj[i] = NULL;
    }
}

void append_vtx(VElement e) {
    vdata[vsize] = e;
    adj[vsize] = NULL;
    vsize += 1;
}

void reset_visited() {
    for (int i = 0; i < vsize; i++) {
        visited[i] = 0;
    }
}

void insert_edge(int u, int v) {
    GNode* node = (GNode*)malloc(sizeof(GNode));
    if (node == NULL){
        printf("malloc failed\n");
        return;
    }
    node->id = v;
    node->link = adj[u];
    adj[u] = node;
}

void DFS(int v) {
    PrintVtx(v);
    visited[v] = 1;
    for (GNode* p = adj[v]; p != NULL; p = p->link) {
        if (visited[p->id] == 0) {
            DFS(p->id);
        }
    }
}

void BFS(int v) {
    init_queue();

    enqueue(v);
    visited[v] = 1;
    PrintVtx(v);
    while (!is_empty()) {
        v = dequeue();
        for (GNode* w = adj[v]; w != NULL; w = w->link) {
            if (!visited[w->id]) {
                enqueue(w->id);
                visited[w->id] = 1;
                PrintVtx(w->id);
            }
        }
    }
}

void free_graph() {
    for (int i = 0; i < vsize; i++) {
        GNode* p = adj[i];
        while (p != NULL) {
            GNode* temp = p;
            p = p->link;
            free(temp);
        }
        adj[i] = NULL; // Dangling 포인터 방지 (이미 해제된 메모리를 가리키는 포인터)
    }
}

int main() {
    VElement vtx[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
    int am[MAX_VSIZE][MAX_VSIZE] = { 
        { 0, 1, 1, 0, 0, 0, 0, 0},
        { 1, 0, 0, 1, 0, 0, 0, 0},
        { 1, 0, 0, 1, 1, 0, 0, 0},
        { 0, 1, 1, 0, 0, 1, 0, 0},
        { 0, 0, 1, 0, 0, 0, 1, 1},
        { 0, 0, 0, 1, 0, 0, 0, 0},
        { 0, 0, 0, 0, 1, 0, 0, 1},
        { 0, 0, 0, 0, 1, 0, 1, 0}
    };

    init_graph();

    for (int i = 0; i < 8; i++) {
        append_vtx(vtx[i]);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (am[i][j]) {
                insert_edge(i, j);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        reset_visited();
        printf("DFS(%c start) --> ", vdata[i]);
        DFS(i);
        puts("");

        reset_visited();
        printf("BFS(%c start) --> ", vdata[i]);
        BFS(i);
        puts("\n");
    }

    free_graph();
}
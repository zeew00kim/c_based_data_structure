#include "circular_deque.h"
#include "windows.h"

#define MAZE_DIM 6

char map[MAZE_DIM][MAZE_DIM] = {
    {'1', '1', '1', '1', '1', '1'}, 
    {'0', '0', '1', '0', '0', '1'}, 
    {'1', '0', '0', '0', '1', '1'}, 
    {'1', '0', '1', '0', '1', '1'}, 
    {'1', '0', '1', '0', '0', 'x'}, 
    {'1', '1', '1', '1', '1', '1'}, 
};

void push_loc(int r, int c);
void print_maze();
Element pop_loc();

// 실습 4-3 : 덱을 사용한 미로 탈출 구현
int main() {

    init_deque();
    push_loc(1, 0);

    while (is_empty() == 0) {
        system("cls"); // 화면 지우고 미로 출력
        print_maze();
        Sleep(500); // 0.5초마다 다음 단계 진행

        Element here = pop_loc();

        int c = here.c;
        int r = here.r;

        if (map[r][c] == 'x') {
            puts("Successful escape from the maze");
            return 0;
        }
        else {
            map[r][c] = '.'; // 방문한 위치
            push_loc(r - 1, c); // 상
            push_loc(r + 1, c); // 하
            push_loc(r, c - 1); // 좌
            push_loc(r, c + 1); // 우
        } 
    }

    puts("Failure to escape the maze");
    
    return 0;
}

void push_loc(int r, int c) {

    if (r < 0 || c < 0 || r >= MAZE_DIM || c >= MAZE_DIM) {
        return; // 미로 범위를 벗어나면 반환
    }
    if (map[r][c] != '0' && map[r][c] != 'x') {
        return; // 갈 수 없는 칸 0과 x만 가능
    }

    Element post = { r, c }; 
    add_rear(post);
}

void print_maze() {
    
    Element here = get_rear();
    for (int i = 0; i < MAZE_DIM; i++) {
        for (int j = 0; j < MAZE_DIM; j++) {
            if ((here.r == i) && (here.c == j)) {
                printf("@");
            }
            else printf("%c", map[i][j]);
        }
        puts("");
    }
}

Element pop_loc() {
    return delete_rear();
}
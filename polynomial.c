#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
} Elem;

void print_mat2(Elem *mat, int len, char* str);
void transpose_mat2(Elem* mat, int len);

int main() {

	Elem mat[5] = { {0, 3, 11}, {2, 5, 42}, {3, 1, 33}, {4, 4, 87}, {5, 4, 55} };
	print_mat2(mat, 5, "희소 행렬");

	puts("");

	transpose_mat2(mat, 5);
	print_mat2(mat, 5, "전치 행렬");

	return 0;
}

void print_mat2(Elem *mat, int len, char* str) {
	printf("%s\n", str);
	for (int i = 0; i < len; i++) {
		printf("{ %d, %d, %d }\n", mat[i].col, mat[i].row, mat[i].value);
	}
}

void transpose_mat2(Elem *mat, int len) {
	for (int i = 0; i < len; i++) {
		int temp = mat[i].row;
		mat[i].row = mat[i].col;
		mat[i].col = temp;
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
    int x, y;
} Point2D;
#define Element Point2D

int x_ascent(Element a, Element b) {
    return (a.x - b.x); // 오름차순
}
int y_descent(Element a, Element b) {
    return (b.y - a.y); // 내림차순
}
int z_ascent(Element a, Element b) {
    int da = a.x * a.x + a.y * a.y;
    int db = b.x * b.x + b.y * b.y;
    return da - db;  // 두 값의 거리 기준 오름차순
}

void insertion_sort_fn(Element *p, int size, int(*f)(Element, Element)) {
    for (int i = 1; i < size; i++) {
        Element key = p[i];
        int j;
        for (j = i -1; j >= 0 && f(p[j], key) > 0; j--) {
            p[j+1] = p[j];
        }
        p[j + 1] = key;
    }
}

void print_point_array(Element *list, int len, char *str) {
    printf("%s", str);
    for (int i = 0; i < len; i++) {
        printf("(%d, %d) ", list[i].x, list[i].y);
    }
    puts("");
}

int main() {

    int len;

    printf("enter the list length : ");
    scanf("%d", &len);

    Element *list = (Element*)malloc(sizeof(Element) * len);

    for (int i = 0; i < len; i++) {
        list[i].x = rand() % 100 + 1;
        list[i].y = rand() % 100 + 1;
    }

    print_point_array(list, len, "original : ");

    insertion_sort_fn(list, len, x_ascent);
    print_point_array(list, len, "x_ascent : ");

    insertion_sort_fn(list, len, y_descent);
    print_point_array(list, len, "y_descent : ");

    insertion_sort_fn(list, len, z_ascent);
    print_point_array(list, len, "z_ascent");

    return 0;
}
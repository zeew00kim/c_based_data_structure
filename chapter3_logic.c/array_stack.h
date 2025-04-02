Element data[MAX_SIZE];
int top;

void error(char *str) {
    puts(str);
    exit(-1);
}

void init_stack() {
    top = -1;
}

int is_empty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_full() {
    return (top == (MAX_SIZE - 1));
}

void push(Element e) {

    if (is_full()) {
        error("Overflow Error!");
    }
    else {
        data[++top] = e;
    }
}

Element pop() {
    if (is_empty()) {
        error("Underflow Error!");
    }
    return data[top--]; // 비어있지 않다면 값을 출력하고 top--
}

Element peek() {
    if (is_empty()) {
        error("Underflow Error!");
    }
    return data[top]; // 현재 top 위치 값 출력 (삭제 안함)
}
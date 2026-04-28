#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) return; // ignore overflow for simplicity
    stack[++top] = value;
}

void pop() {
    if (top == -1) return; // ignore underflow for simplicity
    top--;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, value;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        pop();
    }

    display();
    return 0;
}

#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isEmpty() {
    return top == -1;
}

int main() {
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);

    int i = 0, k = 0;
    while (infix[i] != '\0') {
        char c = infix[i];

        if (isalnum(c)) {
            // Operand goes directly to output
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        } else {
            // Operator
            while (!isEmpty() && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
        i++;
    }

    // Pop remaining operators
    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("%s\n", postfix);

    return 0;
}

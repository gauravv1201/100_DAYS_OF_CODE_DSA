#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* expr) {
    int i = 0;
    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            // convert char digit to int
            push(expr[i] - '0');
        } else if (expr[i] == ' ') {
            // skip spaces
        } else {
            // operator: pop two operands
            int val2 = pop();
            int val1 = pop();
            switch (expr[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char expr[100];
    // read entire line including spaces
    fgets(expr, sizeof(expr), stdin);

    int result = evaluatePostfix(expr);
    printf("%d\n", result);

    return 0;
}

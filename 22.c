#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, val, count = 0;
    scanf("%d", &n);
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL) head = newNode;
        else temp->next = newNode;
        temp = newNode;
    }

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }
    printf("\n%d\n", count);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int val;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL) head = newNode;
        else temp->next = newNode;
        temp = newNode;
    }
    return head;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    while(head) {
        if(head->data == key) count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, key;
    scanf("%d", &n);
    struct Node* head = createList(n);
    scanf("%d", &key);

    printf("%d\n", countOccurrences(head, key));
    return 0;
}
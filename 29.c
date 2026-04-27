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

struct Node* rotateRight(struct Node* head, int k, int n) {
    if(!head || k == 0) return head;
    struct Node* tail = head;
    while(tail->next) tail = tail->next;
    tail->next = head;
    k = k % n;
    int steps = n - k;
    struct Node* newHead = head;
    struct Node* newTail = NULL;
    for(int i = 0; i < steps; i++) {
        newTail = newHead;
        newHead = newHead->next;
    }
    newTail->next = NULL;
    return newHead;
}

void printList(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    struct Node* head = createList(n);
    scanf("%d", &k);
    head = rotateRight(head, k, n);
    printList(head);
    return 0;
}
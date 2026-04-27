#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createCircularList(int n) {
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
    if(temp) temp->next = head;
    return head;
}

void traverseCircular(struct Node* head) {
    if(head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = createCircularList(n);
    traverseCircular(head);
    return 0;
}
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

struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;
    while(temp != NULL) {
        if(temp->data == key) {
            if(prev == NULL) head = temp->next;   // deleting head
            else prev->next = temp->next;        // bypass node
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void printList(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, key;
    scanf("%d", &n);
    struct Node* head = createList(n);
    scanf("%d", &key);

    head = deleteKey(head, key);
    printList(head);
    return 0;
}
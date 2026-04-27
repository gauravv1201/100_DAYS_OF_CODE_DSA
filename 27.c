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

int getLength(struct Node* head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = (len1 > len2) ? len1 - len2 : len2 - len1;
    if(len1 > len2) {
        while(diff--) head1 = head1->next;
    } else {
        while(diff--) head2 = head2->next;
    }

    while(head1 && head2) {
        if(head1->data == head2->data) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* list1 = createList(n);
    scanf("%d", &m);
    struct Node* list2 = createList(m);

    struct Node* inter = findIntersection(list1, list2);
    if(inter) printf("%d\n", inter->data);
    else printf("No Intersection\n");
    return 0;
}
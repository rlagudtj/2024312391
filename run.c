#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* nNode = (Node*)malloc(sizeof(Node));
    nNode->data = data;
    nNode->next = NULL;
    return nNode;
}

void sortedInsert(Node** head, Node* nNode) {
    Node* current;

    if (*head == NULL || (*head)->data >= nNode->data) {
        nNode->next = *head;
        *head = nNode;
    } else {
        current = *head;
        while (current->next != NULL && current->next->data < nNode->data) {
            current = current->next;
        }
        nNode->next = current->next;
        current->next = nNode;
    }
}

void insertionSort(Node** a) {
    Node* sort = NULL;   
    Node* current = *a;

    while (current != NULL) {
        Node* next = current->next; 
        sortedInsert(&sort, current);  
        current = next;
    }

    *a = sort;  
}


void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, num;

    printf("정렬할 숫자의 개수: ");
    scanf("%d", &n);

    printf("정렬할 숫자: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        Node* newNode = createNode(num);
        newNode->next = head;
        head = newNode;
    }

    printf("정렬 전:\n");
    printList(head);
    insertionSort(&head);
    printf("정렬 후:\n");
    printList(head);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} *node;

node createNewNode(int);
void insertSortedLinkedListElement(node, int);
void printList(node);
node findTrueHead(node);

int main() {
    int n;
    printf("Enter an integer to store into a linked list: ");
    scanf("%d", &n);
    node head = createNewNode(n);
    printf("How many more integers would you like to insert? (Enter now:) ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int n1;
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &n1);
        insertSortedLinkedListElement(head, n1);
        head = findTrueHead(head);
    }
    printList(head);
    
    return 0;
}

node createNewNode(int n) {
    node newNode = (node)malloc(sizeof(struct node));
    newNode->data = n;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertSortedLinkedListElement(node head, int n) {
    node newNode = createNewNode(n);
    node trav = head;
    for (; trav != NULL; trav = trav->next) {
        if (newNode->data < trav->data) {
            newNode->next = trav;
            trav-;
            trav = trav->prev;
            if (trav->prev == NULL) {
                return;
            }
            trav = trav->prev;
            trav->next = newNode;
            newNode->prev = trav;
            return;
        }
    }
    trav->next = newNode;
    newNode->prev = trav;
}

void printList(node head) {
    node trav = head;
    printf("Printing all items in the list:\n");
    for (; trav != NULL; trav = trav->next) {
        printf("%d\n", trav->data);
    }
}

node findTrueHead(node head) {
    node trav = head;
    for (; trav->prev != NULL; trav = trav->prev);
    head = trav;
    return head;
}
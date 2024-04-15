#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} *node;

node createNewNode(int);

int main(int argv, char *argc[]) {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    node head = createNewNode(n);
    free(head);
    return 0;
}

node createNewNode(int data) {
    node temp = (node)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int elems[MAX];
    int count;
} Stack;

Stack createStack();
void initStack(Stack*);
bool isEmpty(Stack);
bool isFull(Stack);
void visualise(Stack);
bool push(Stack*, int);
bool pop(Stack*);
int peek(Stack);
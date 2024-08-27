#include <stdio.h>
#include <stdbool.h>
#include "MyStack.h"

Stack createStack() {
    Stack s;
    s.count = 0;
    return s;
}

void initStack(Stack *s) {
    s->count = 0;
}

bool isEmpty(Stack s) {
    return s.count == 0;
}

bool isFull (Stack s) {
    return s.count >= MAX;
}

void visualise (Stack s) {
    printf("List {");
    for (int i = 0; i < s.count; ++i) {
        printf("%d", s.elems[i]);
        if (i < s.count - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

bool push (Stack *s, int elem) {
    if (!isFull(*s)) {
        s->elems[(s->count)++] = elem;
        return true;
    }
    return false;
}

bool pop (Stack *s) {
    if (!isEmpty(*s)) {
        (s->count)--;
        return true;
    }
    return false;
}

int peek(Stack s) {
    return s.elems[s.count];
}
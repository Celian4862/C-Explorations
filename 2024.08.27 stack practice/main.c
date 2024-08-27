#include <stdio.h>
#include <stdbool.h>
#include "MyStack.h"

int main() {
    Stack stackA = createStack();

    visualise(stackA);
    push(&stackA, 10);
    visualise(stackA);;
    push(&stackA, 5);
    visualise(stackA);
    push(&stackA, 4);
    visualise(stackA);
    push(&stackA, 7);
    visualise(stackA);
    push(&stackA, 1);
    visualise(stackA);
    push(&stackA, 6);
    visualise(stackA);

    for (int i = 0; i < 10; i++) {
        pop(&stackA);
        visualise(stackA);
    }
    
    printf("\n\n");
    return 0;
}
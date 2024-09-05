#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"

int main() {
    QueueADT q;
    int max, choice;
    String buffer;
    _Bool invalid_input = false;
    printf("How many students do you have in total? ");
    do {
        scanf("%19s", buffer);
        // The line below is for testing purposes only.
        unsigned int buffer_length = strlen(buffer);
        for (int i = 0; i < strlen(buffer); i++) {
            if (!isdigit(buffer[i])) {
                invalid_input = true;
                printf("Please input only numbers.\n");
                break;
            }
        }
    } while (invalid_input);
    max = atoi(buffer);
    q = createQueue(max);
    printf("What would you like to do with the queue?\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Visualise\n");
    printf("5. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
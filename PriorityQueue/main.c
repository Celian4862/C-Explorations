#include "pq.h"

extern void (*display[])(Heap);

int main(int argc, char **argv) {
    int numberOfArrs = 1, maxArrs = 5, arr, choice, data;
    Heap *heap = (Heap*) malloc (sizeof(Heap) * maxArrs);
    initHeap(heap, MAX);
    do {
        if (numberOfArrs > 1) {
            printf("Which set of data would you like to modify? (1 - %d) ", numberOfArrs);
            scanf("%d", &arr);
            if (arr < 1 || arr > numberOfArrs) {
                printf("Invalid choice.\n\n");
                continue;
            }
            arr--; // Subtract one from array for array indexing
        }
        printf("What would you like to do?\n1. Insert\n2. Remove\n3. Heapify\n4. Display data\n5. Add another set of data\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 6) {
            printf("\nInvalid choice.\n\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter the datum: ");
                scanf("%d", &data);
                printf("%s\n", (insertHeap(heap + arr, data)) ? "\nInsert successful!\n" : "\nInsert failed.\n");
                break;
            case 2:
                printf("%s\n", (rmHeap(heap + arr)) ? "\nRemove successful!\n" : "\nRemove failed.\n");
                break;
            case 3:
                printf("%s\n", (heapify(heap + arr)) ? "\nHeapify successful!\n" : "\nHeapify failed.\n");
                break;
            case 4:
                printf("In which manner would you like to display it?\n1. Breadth-first search\n2. Pre-order depth-first search\n3. In-order depth-first search\n4. Post-order depth-first search\nEnter your choice here: ");
                scanf("%d", &choice);
                display[choice - 1](heap[arr]);
                break;
            case 5:
                if (numberOfArrs == maxArrs) {
                    
                }
            case 6:
                break;
            default:
                printf("\nInvalid choice.\n\n");
        }
    } while (choice != 6);
    printf("Goodbye!\n");
    return 0;
}
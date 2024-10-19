#include "pq.h"

extern void (*display[])(Heap, int);

int main(int argc, char **argv) {
    Heap heap;
    if (!initHeap(&heap)) {
        return 1;
    }
    // int arr[] = {5, 20, 24, 10, 13, 15, 14, 21, 30, 35, 40, 45, 50, 25, 0};
    // int arr[] = {1, 56, 69, 12, 40, 422, 23, 2, 90, 71};
    int arr[] = {1, 2, 23, 40, 12, 422, 69, 56, 90, 71};
    for (int i = 0; i < 10; i++) {
        printf("%d: %s\n", arr[i], (insertHeap(&heap, arr[i]) ? "Success!" : "Fail."));
    }
    display[0](heap, 0);
    printf("\n");
    for (int i = 0; i < 10; i++) {
        rmHeap(&heap);
        display[0](heap, 0);
        printf("\n");
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", heap.arr[i]);
    }
    return 0;
}

// bool initHeapArray(Heap**, int);
// bool resizeHeapArray(Heap**, int);

// int main(int argc, char **argv) {
//     int numberOfArrs = 1, maxArrs = 5, arr = 0, choice, data;
//     Heap *heap;
//     if (!initHeapArray(&heap, maxArrs)) {
//         return 1;
//     }
//     if (!initHeap(heap)) {
//         return 2;
//     }
//     do {
//         if (numberOfArrs > 1) {
//             printf("Which set of data would you like to modify? (1 - %d) ", numberOfArrs);
//             scanf("%d", &arr);
//             if (arr < 1 || arr > numberOfArrs) {
//                 printf("Invalid choice.\n\n");
//                 continue;
//             }
//             arr--; // Subtract one from array for array indexing
//         }
//         printf("What would you like to do?\n1. Insert\n2. Remove\n3. Heapify\n4. Display data\n5. Add another set of data\n6. Exit\nEnter your choice: ");
//         scanf("%d", &choice);
//         if (choice < 1 || choice > 6) {
//             printf("\nInvalid choice.\n\n");
//             continue;
//         }
//         switch (choice) {
//             case 1:
//                 printf("Enter the datum: ");
//                 scanf("%d", &data);
//                 printf("%s\n", (insertHeap(heap + arr, data)) ? "\nInsert successful!\n" : "\nInsert failed.\n");
//                 break;
//             case 2:
//                 printf("%s\n", (rmHeap(heap + arr)) ? "\nRemove successful!\n" : "\nRemove failed.\n");
//                 break;
//             case 3:
//                 printf("%s\n", (heapify(heap + arr)) ? "\nHeapify successful!\n" : "\nHeapify failed.\n");
//                 break;
//             case 4:
//                 printf("\nIn which manner would you like to display it?\n1. Breadth-first search\n2. Pre-order depth-first search\n3. In-order depth-first search\n4. Post-order depth-first search\nEnter your choice here: ");
//                 scanf("%d", &choice);
//                 if (choice < 1 || choice > 4) {
//                     printf("Invalid input.\n\n");
//                     break;
//                 }
//                 display[choice - 1](heap[arr], 0); // Only breadth-first display doesn't need new index arguments; the other three are recursive
//                 printf("\n");
//                 /*
//                 Breadth-first: Prints every datum in the array
//                 Depth-first: Passes the array for reference as well as the index of the next datum to print
//                 */
//                 break;
//             case 5: // Add another array
//                 if (numberOfArrs == maxArrs) {
//                     maxArrs += 5;
//                     if (resizeHeapArray(&heap, maxArrs)) {
//                         return 1;
//                     }
//                 }
//                 if (!initHeap(heap + numberOfArrs)) {
//                     break;
//                 }
//                 numberOfArrs++;
//             case 6:
//                 break;
//             default:
//                 printf("\nInvalid choice.\n\n");
//         }
//     } while (choice != 6);
//     printf("Goodbye!\n");
//     return 0;
// }

// bool initHeapArray(Heap **h, int max) {
//     *h = (Heap*) malloc (sizeof(Heap) * max);
//     if (!(*h)) {
//         printf("Memory allocation failed.\n");
//         return false;
//     }
//     return true;
// }

// bool resizeHeapArray(Heap **h, int max) {
//     *h = (Heap*) realloc (h, sizeof(Heap) * max);
//     if (!(*h)) {
//         printf("Memory allocation failed.\n");
//         return false;
//     }
//     return true;
// }
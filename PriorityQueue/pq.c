#include "pq.h"

void (*display[])(Heap, int) = {breadth_first, preorder, inorder, postorder};

bool initHeap(Heap *h, int max) {
    h->arr = (int*) malloc (sizeof(int) * max);
    if (!h->arr) {
        printf("Memory allocation failed.\n");
        return false;
    }
    h->max = max;
    h->count = -1; // Count will keep track of the last element, not how many there are.
    return true;
}

bool resizeHeap(Heap *h, int max) {
    h->arr = (int*) realloc (h->arr, sizeof(int) * max);
    if (!h->arr) {
        printf("Memory allocation failed.\n");
        return false;
    }
    h->max = max;
    return true;
}

bool insertHeap(Heap *h, int data) {
    if (h->count < h->max - 1) {
        int child = ++h->count;
        while (data < h->arr[(child - 1) / 2] && child != 0) {
            h->arr[child] = h->arr[(child - 1) / 2];
            child = (child - 1) / 2;
        }
        h->arr[child] = data;
        return true;
    }
    return false;
}

bool rmHeap(Heap *h) {
    int temp = h->arr[0];
    h->arr[0] = h->arr[h->count]; // Count stores the index of the last element, not the number of elements.
    h->arr[h->count--] = temp; // The initially smallest element in the array is at the end of the array.
    // Perform sift down
    int idx = 0;
    while (idx <= h->count) {
        if (h->arr[idx] > h->arr[2 * idx + 2]) {
            idx = 2 * idx + 2;
        } else if (h->arr[idx] > h->arr[2 * idx + 1]) {
            idx = 2 * idx + 1;
        } else {
            break;
        }
    }
    return false;
}

bool heapify(Heap *h) {
    return false;
}

void breadth_first(Heap h, int idx) {
    while (idx <= h.count) {
        printf("%d ", h.arr[idx]);
    }
}

void preorder(Heap h, int idx) {
    if (idx <= h.count) {
        printf("%d ", h.arr[idx]);
        preorder(h, 2 * idx + 1);
        preorder(h, 2 * idx + 2);
    }
}

void inorder(Heap h, int idx) {
    if (idx <= h.count) {
        inorder(h, 2 * idx + 1);
        printf("%d ", h.arr[idx]);
        inorder(h, 2 * idx + 2);
    }
}

void postorder(Heap h, int idx) {
    if (idx <= h.count) {
        postorder(h, 2 * idx + 1);
        postorder(h, 2 * idx + 2);
        printf("%d ", h.arr[idx]);
    }
}
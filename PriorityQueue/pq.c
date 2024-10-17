#include "pq.h"

void (*display[])(Heap, int) = {breadth_first, preorder, inorder, postorder};

bool initHeap(Heap *h) {
    h->arr = (int*) malloc (sizeof(int) * MAX);
    if (!h->arr) {
        printf("Memory allocation failed.\n");
        return false;
    }
    h->max = MAX;
    h->lastIdx = -1;
    return true;
}

bool resizeHeap(Heap *h) {
    h->arr = (int*) realloc (h->arr, sizeof(int) * (h->max + MAX));
    if (!h->arr) {
        printf("Memory allocation failed.\n");
        return false;
    }
    h->max = h->max + MAX;
    return true;
}

bool insertHeap(Heap *h, int data) {
    if (h->lastIdx == h->max - 1 && !resizeHeap(h)) {
        return false;
    }
    int child = ++h->lastIdx;
    while (data < h->arr[(child - 1) / 2] && child != 0) {
        h->arr[child] = h->arr[(child - 1) / 2];
        child = (child - 1) / 2;
    }
    h->arr[child] = data;
    return true;
}

bool rmHeap(Heap *h) {
    // Transfer last data to the root
    int temp = h->arr[0];
    h->arr[0] = h->arr[h->lastIdx];
    h->arr[h->lastIdx--] = temp;
    // Sift down
    // int idx = 0;
    // bool flag = true;
    // while (idx <= h->lastIdx && flag) {
    //     idx = 2 * idx + ((h->arr[idx] > h->arr[2 * idx + 2]) ? 2 : ((h->arr[idx] > h->arr[2 * idx + 1]) ? 1 : 0)
    //     if (h->arr[idx] > h->arr[2 * idx + 2]) {
    //         idx = 2 * idx + 2;
    //     } else if (h->arr[idx] > h->arr[2 * idx + 1]) {
    //         idx = 2 * idx + 1;
    //     } else {
    //         break;
    //     }
    //     flag = (h->arr)
    // }
    return false;
}

bool heapify(Heap *h) {
    return false;
}

void breadth_first(Heap h, int idx) { // Must pass idx = 0 to display the entire tree
    while (idx <= h.lastIdx) {
        printf("%d ", h.arr[idx++]);
    }
}

void preorder(Heap h, int idx) {
    if (idx <= h.lastIdx) {
        printf("%d ", h.arr[idx]);
        preorder(h, 2 * idx + 1);
        preorder(h, 2 * idx + 2);
    }
}

void inorder(Heap h, int idx) {
    if (idx <= h.lastIdx) {
        inorder(h, 2 * idx + 1);
        printf("%d ", h.arr[idx]);
        inorder(h, 2 * idx + 2);
    }
}

void postorder(Heap h, int idx) {
    if (idx <= h.lastIdx) {
        postorder(h, 2 * idx + 1);
        postorder(h, 2 * idx + 2);
        printf("%d ", h.arr[idx]);
    }
}
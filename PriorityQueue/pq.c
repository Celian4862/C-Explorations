#include "pq.h"

void (*display[])(Heap, int) = {breadth_first, preorder, inorder, postorder};

bool initHeap(Heap *h) {
    h->arr = (int*) malloc (sizeof(int) * (15));
    if (!h->arr) {
        printf("Memory allocation failed.\n");
        return false;
    }
    h->max = 15;
    h->lastIdx = -1;
    h->depth_breadth = 8;
    return true;
}

bool resizeHeap(Heap *h) {
    h->arr = (int*) realloc (h->arr, sizeof(int) * (h->max + h->depth_breadth * 2));
    if (!h->arr) {
        printf("Memory allocation failed.\n");
        return false;
    }
    h->depth_breadth *= 2;
    h->max += h->depth_breadth;
    return true;
}

bool insertHeap(Heap *h, int data) {
    if (h->lastIdx == h->max - 1 && !resizeHeap(h)) {return false;}
    int child = ++h->lastIdx;
    while (data < h->arr[(child - 1) / 2] && child != 0) {
        h->arr[child] = h->arr[(child - 1) / 2];
        child = (child - 1) / 2;
    }
    h->arr[child] = data;
    return true;
}

bool rmHeap(Heap *h) {
    if (h->lastIdx == -1) return false;
    int last = h->arr[h->lastIdx];
    h->arr[h->lastIdx--] = h->arr[0];
    int index = 0, left = index * 2 + 1, smaller = (left + 1 <= h->lastIdx && h->arr[left + 1] < h->arr[left]) ? left + 1 : left;
    while (left <= h->lastIdx && last > h->arr[smaller]) {
        h->arr[index] = h->arr[smaller];
        index = smaller;
        left = index * 2 + 1;
        smaller = (left + 1 <= h->lastIdx && h->arr[left + 1] < h->arr[left]) ? left + 1 : left;
    }
    h->arr[index] = last;
    return true;
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
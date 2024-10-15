#include "pq.h"

void (*display[])(Heap) = {breadth_first, preorder, inorder, postorder};

bool initHeap(Heap *h, int max) {
    h->arr = (int*) malloc (sizeof(int) * max);
    if (!h->arr) {
        printf("Memory allocation failed.\n");
        return false;
    }
    h->max = max;
    h->count = 0;
    return true;
}

bool resizeHeap(Heap *h, int max) {
    h->arr = (int*) realloc (h->arr, sizeof(int) * max);
    if (!h->arr) {
        printf("Memory allocation failed.\n");
        return false;
    }
    h->max = max;
    h->count = 0;
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
    return false;
}

bool heapify(Heap *h) {
    return false;
}

void breadth_first(Heap h) {

}

void preorder(Heap h) {

}

void inorder(Heap h) {

}

void postorder(Heap h) {

}
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
    h->max = h->max + h->depth_breadth;
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
    int i = 0, left_child = 1, right_child = 2;
    temp = h->arr[0]; // Temp stores the data to sift down
    while (left_child <= h->lastIdx) { // While left child exists
        if (right_child <= h->lastIdx) { // If right child exists
            if (temp > h->arr[left_child] || temp > h->arr[right_child]) { // If temp is greater than either of the children
                if (h->arr[left_child] >= h->arr[right_child]) {
                    h->arr[i] = h->arr[right_child];
                    i = right_child;
                } else if (h->arr[left_child] < h->arr[right_child]) {
                    h->arr[i] = h->arr[left_child];
                    i = left_child;
                }
                right_child = i * 2 + 2; // Right child changes to right child of the new node
            } else {
                break;
            }
        } else if (temp > h->arr[left_child]) {
            h->arr[i] = h->arr[left_child];
            i = left_child;
        } else {
            break;
        }
        left_child = i * 2 + 1;
    }
    h->arr[i] = temp;
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
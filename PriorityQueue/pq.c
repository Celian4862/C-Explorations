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
    // --(h->lastIdx);
    // int index = 0, smaller = index, left = 1, temp = h->arr[0];
    // while (index <= h->lastIdx && left <= h->lastIdx && left + 1 <= h->lastIdx) {
    //     smaller = (h->arr[left] < h->arr[left + 1]) ? left : left + 1;
    //     h->arr[index] = h->arr[smaller];
    //     index = smaller;
    //     left = index * 2 + 1;
    // }
    // h->arr[index] = h->arr[h->lastIdx + 1];
    // h->arr[h->lastIdx + 1] = temp;
    // return true;

    int temp = h->arr[h->lastIdx], i = 0, left_child = 1, right_child = 2, child; // Variable initalisations for the whole function
    h->arr[h->lastIdx--] = h->arr[i]; // Just in case of heap sorting
    // Sift down
    while (left_child <= h->lastIdx && (((right_child <= h->lastIdx && (temp > h->arr[left_child] || temp > h->arr[right_child])) || temp > h->arr[left_child]))) {
        child = (right_child <= h->lastIdx && (temp > h->arr[left_child] || temp > h->arr[right_child]) && h->arr[left_child] < h->arr[right_child] || right_child > h->lastIdx && temp > h->arr[left_child]) ? left_child : right_child;
        h->arr[i] = h->arr[child];
        i = child;
        left_child = i * 2 + 1;
        right_child = left_child + 1;
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
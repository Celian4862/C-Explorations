#include "pq.h"
#include <stdlib.h>

bool (*ops[])(Heap*, int) = {insert, remove};
void (*display[])(Heap) = {breadth_first, preorder, inorder, postorder};

void initHeap(Heap *h, int max) {
    h->arr = (int*) malloc (sizeof(int) * max);
    h->max = max;
    h->count = 0;
}

void resizeHeap(Heap *h, int max) {
    h->arr = (int*) realloc (h->arr, sizeof(int) * max);
    h->max = max;
    h->count = 0;
}

bool insert(Heap *h, int data) {
    if (h->count < h->max - 1) {
        int child = ++h->count;
        while (data < h->arr[(child - 1) / 2]) {
            
        }
    }
    return false;
}

bool remove(Heap *h, int data) {

}
#ifndef PQ_H
#define PQ_H
#include <stdbool.h>
#define MAX 10

typedef struct {
    int *arr, max, count;
} Heap;

void initHeap(Heap*, int max);
void resizeHeap(Heap*, int max);
bool insert(Heap*, int data);
bool remove(Heap*, int data);
bool heapify(Heap*);

void breadth_first(Heap);
void preorder(Heap);
void inorder(Heap);
void postorder(Heap);

#endif
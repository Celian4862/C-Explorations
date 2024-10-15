#ifndef PQ_H
#define PQ_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int *arr, max, count;
} Heap;

void initHeap(Heap*, int max);
void resizeHeap(Heap*, int max);
bool insertHeap(Heap*, int data);
bool rmHeap(Heap*);
bool heapify(Heap*);

void breadth_first(Heap);
void preorder(Heap);
void inorder(Heap);
void postorder(Heap);

#endif
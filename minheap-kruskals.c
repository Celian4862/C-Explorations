#include <stdio.h>
#define MAX 10

typedef int LabelAdjMat[MAX][MAX];

typedef struct {
  int u,v, weight;
} Edge;

typedef struct {
  Edge edge[MAX - 1];
  int lastNdx;
} EdgeList;

typedef struct {
  EdgeList el;
  int cost;
} MST;

void heapify(EdgeList*);
EdgeList createMinHeap(LabelAdjMat);
MST Kruskals(LabelAdjMat);

int main(int argc, char **argv) {
  return 0;
}

void heapify(EdgeList *el) {
  
}

EdgeList createMinHeap(LabelAdjMat A) {
  EdgeList el;
  for (int i = 0; i < MAX; i++) {
    for (int j = i + 1; j < MAX; j++) {
      el.edge[++el.lastNdx].u = i;
      el.edge[el.lastNdx].v = j;
      el.edge[el.lastNdx].weight = A[i][j];
      heapify(&el);
    }
  }
}

MST Kruskals (LabelAdjMat A) {

}
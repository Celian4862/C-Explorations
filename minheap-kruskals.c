#include <stdio.h>
#define MAX 10

typedef int LabelAdjMat[MAX][MAX];

typedef struct {
  int u,v,weight;
} Edge;

typedef struct {
  Edge edge[MAX - 1];
  int lastNdx;
} EdgeList;

typedef struct {
  EdgeList el;
  int cost;
} MST;

MST Kruskals(LabelAdjMat);
EdgeList createMinHeap(LabelAdjMat);
void insertHeap(EdgeList*, int, int, int);

int main(int argc, char **argv) {
  LabelAdjMat matrix;
  int x,y,z;
  printf("Enter 0 to stop giving input.\n");
  printf("Enter edge: (source, destination, weight): ");
  scanf("%d %d %d", &x, &y, &z);
  return 0;
}

MST Kruskals (LabelAdjMat A) {

}

EdgeList createMinHeap(LabelAdjMat A) {
  EdgeList el;
  for (int i = 0; i < MAX; i++) {
    for (int j = i + 1; j < MAX; j++) {
      insertHeap(&el, i, j, A[i][j]);
    }
  }
}

void insertHeap(EdgeList *el, int u, int v, int weight) {
  el->edge[++el->lastNdx].u = u;
  el->edge[++el->lastNdx].v = v;
  el->edge[++el->lastNdx].weight = weight;
}
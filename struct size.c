#include <stdio.h>

typedef struct {
    int a;
    double b;
    char c[3];
    float d;
} sizing;

int main() {
    printf("%d\n", sizeof(sizing));
    return 0;
}
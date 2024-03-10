#include <stdio.h>

int main() {
    system("clear");
    char s[10];
    fgets(s, 9, stdin);
    printf("%s\n", s);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_CHAR
#define MAX_CHAR 100
#endif

char* find_common_word();

int main() {
    char *sentence1 = (char *) malloc (MAX_CHAR), *sentence2 = (char *) malloc (MAX_CHAR), *common_word;
    printf("Enter a sentence (max characters %d): ", MAX_CHAR);
    scanf(" %[^\n]", sentence1);
    printf("Enter another sentence (max charactesr %d): ", MAX_CHAR);
    scanf(" %[^\n]", sentence2);

    // Not sure if this will work, because a string is an array of characters.
    strcpy(common_word, find_common_word());

    return 0;
}

char* find_common_word() {

    return "c";
}
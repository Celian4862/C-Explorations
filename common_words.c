#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX_CHAR
#define MAX_CHAR 100
#endif

// char** find_common_word(char*, char*, int, int);
void printWords(char**);

// Putting this here before final function so that I don't have to keep changing the prototype
char** find_common_word(char *sentence1, char *sentence2) {
    int i, size = (strlen(sentence1) > strlen(sentence2)) ? strlen(sentence1) : strlen(sentence2);
    // Initialise 2D arrays with the smallest possible size
	char **common_words = (char**) malloc (sizeof(char*));
    *common_words = (char*) malloc (strlen(size) + 1);

    for (i = 0; i < size; i++) {
        if ()
    }
    /*
    Algorithm (iterative breaking down):
        Example: sentence1 = "This is fun!", sentence2 = "What is he doing?"
        Use the shorter sentence as reference.
        If it's a character, add it to the word.
        If the first word of the shorter sentence is found anywhere in the longer sentence, record it. Else, don't.
            How does the programme know what a word is and what's not?
                If you see a bunch of characters in consecutive order, then it's a word. Spaces or other special characters separate words.

        If the second word of the shorter sentence is found anywhere in the longer sentence, record it. Else, don't.
        End when there are no more characters to look for.

        Question: where will you store the common words? Array.
        Question: a 1D array can only contain a single string. How do you store an array of strings? 2D arrays.
        Question: the arrays are dynamically allocated to be as small as possible. How will you resize it?
    */

    return common_words;
}

int main(int argc, char *argv[]) {
    char *sentence1 = (char *) malloc (MAX_CHAR), *sentence2 = (char *) malloc (MAX_CHAR), **common_words;
    printf("Enter a sentence (max characters %d): ", MAX_CHAR);
    scanf(" %[^\n]", sentence1);
    printf("Enter another sentence (max charactesr %d): ", MAX_CHAR);
    scanf(" %[^\n]", sentence2);
    sentence1 = (char*) realloc (sentence1, strlen(sentence1) + 1), sentence2 = (char*) realloc (sentence2, strlen(sentence2) + 1);

    common_words = find_common_word(sentence1, sentence2);

    // Printing all words that appear more than once in both sentences
    printf("Common words:\n");
    printWords(common_words);

    return 0;
}

void printWords(char** words) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, words[i]);
    }
}

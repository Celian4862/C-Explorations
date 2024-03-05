#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100

void getSentences(char*, char*);
int compareSTRLEN(char*, char*);

int main() {
	system("cls");
	// Dynamically allocated so that memory can be resized if needed
	char *sentence1 = (char*) malloc (MAX_CHAR), *sentence2 = (char*) malloc (MAX_CHAR);

	// Get the sentences necessary for the task
	getSentences(sentence1, sentence2);
	// Store the string length of the shorter sentence to avoid redundancy
	int size = compareSTRLEN(sentence1, sentence2);

	return 0;
}

void getSentences(char *sentence1, char *sentence2) {
	printf("Enter a sentence (max 100 characters: ");
	scanf(" %[^\n]", sentence1);
	sentence1 = (char*) realloc(sentence1, strlen(sentence1));

	printf("Enter another sentence (max 100 characters): ");
	scanf(" %[^\n]", sentence2);
	sentence2 = (char*) realloc(sentence2, strlen(sentence2));
}

int compareSTRLEN(char *sentence1, char *sentence2) {
	if (strlen(sentence1) < strlen(sentence2)) {
		return strlen(sentence1);
	} else {
		return strlen(sentence2);
	}
}

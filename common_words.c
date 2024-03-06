#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef MAX_CHAR
#define MAX_CHAR 100
#endif

void getSentences(char*, char*);
void string_tolower(char*, int);
void remove_special(char*, int);
int find_shorter_string(char*, char*);
char** find_common_words(char*, char*, int*);
void printWords(char**, int);

int main() {
	system("clear");
	system("cls");
	// Dynamically allocated so that memory can be resized if needed
	char *sentence1 = (char*) malloc (MAX_CHAR), *sentence2 = (char*) malloc (MAX_CHAR);

	// Get the sentences necessary for the task
	getSentences(sentence1, sentence2);
	// To make typing shorter, create variables to store the string lengths of the sentences.
	int size1 = strlen(sentence1), size2 = strlen(sentence2);
	// Have a word count variable for later.
	int word_count = 0;

	// Make both strings lowercase to deal with them easier.
	string_tolower(sentence1, size1);
	string_tolower(sentence2, size2);

	// Remove special characters from both strings
	remove_special(sentence1, size1);
	remove_special(sentence2, size2);

	// Dynamically allocated by the function.
	char **words = find_common_words(sentence1, sentence2, &word_count);

	printWords(words, word_count);

	free(sentence1);
	free(sentence2);
	free(*words);
	free(words);

	return 0;
}

// Function is special: it has to receive dynamically allocated strings, or else an error may occur.
void getSentences(char *sentence1, char *sentence2) {
	printf("Enter a sentence (max 100 characters): ");
	scanf(" %[^\n]", sentence1);
	sentence1 = (char*) realloc(sentence1, strlen(sentence1) + 1);

	printf("Enter another sentence (max 100 characters): ");
	scanf(" %[^\n]", sentence2);
	sentence2 = (char*) realloc(sentence2, strlen(sentence2) + 1);
}

void string_tolower(char *s, int size) {
	for (int i = 0; i < size; i++) {
		s[i] = tolower(s[i]);
	}
}

void remove_special(char *s, int size) {
	for (int i = 0; i < size; i++) {
		if (iscntrl(s[i]) && s[i] != '\0' || ispunct(s[i])) {
			s[i] = ' ';
		}
	}
}

int find_shorter_string(char *s1, char *s2) {
	if (strlen(s1) < strlen(s2)) {
		return strlen(s1);
	} else {
		return strlen(s2);
	}
}

// Progress note: something is wrong with strtok; it's changing the strings, but also not remembering the first string, so that's why the loop ends early. I wonder how to solve this....
char** find_common_words(char *s1, char *s2, int *word_count) {
	// Initialise the tokens.
	char *token1 = strtok(s1, " "), *token2;
	// Initialise the array of words.
	char **words = (char**) malloc (sizeof(char*));
	*words = (char*) malloc (find_shorter_string(s1, s2));
	while (token1) {
		token2 = strtok(s2, " ");
		while (token2) {
			if (!strcmp(token1, token2)) {
				strcpy(words[(*word_count)++], token1);
				words = (char**) realloc (words, sizeof(char**) * ((*word_count) + 1));
				*words = (char*) realloc (words, find_shorter_string(s1, s2) * ((*word_count) + 1));
			}
			token2 = strtok(NULL, " ");
		}
		token1 = strtok(NULL, " ");
	}
	return words;
}

void printWords(char **s, int word_count) {
	for (int i = 0; i < word_count; i++) {
		printf("%s\n", s[i]);
	}
}

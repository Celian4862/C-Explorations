#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef MAX
#define MAX 100
#endif

int main() {
    system("clear");
	char *s1 = (char*) malloc (MAX + 1), *s2 = (char*) malloc (MAX + 1), **words = (char**) malloc (sizeof(char*)), *saveptr1, *saveptr2, *token1, *token2, *s2_copy;
	printf("Enter a sentence (max 100 characters): ");
	scanf(" %[^\n]", s1);
	printf("Enter another sentence (max 100 characters): ");
	scanf(" %[^\n]", s2);
	int size1 = strlen(s1), size2 = strlen(s2), word_count = 0, shorter = (size1 < size2) ? size1 : size2, i;
    s1 = (char*) realloc(s1, strlen(s1) + 1), s2 = (char*) realloc(s2, strlen(s2) + 1), token1 = strtok_r(s1, " ", &saveptr1), *words = (char*) malloc (shorter), s2_copy = (char*) malloc (strlen(s2) + 1);
    for (i = 0; i < size1; i++) {
		s1[i] = tolower(s1[i]);
        if (iscntrl(s1[i]) && s1[i] != '\0' || ispunct(s1[i])) {
			s1[i] = ' ';
		}
	}
    for (i = 0; i < size2; i++) {
        s2[i] = tolower(s2[i]);
        if (iscntrl(s2[i]) && s2[i] != '\0' || ispunct(s2[i])) {
			s2[i] = ' ';
		}
    }

    strcpy(s2_copy, s2);
    while (token1) {
        strcpy(s2, s2_copy);
        token2 = strtok_r(s2, " ", &saveptr2);
        while (token2) {
            if (!strcmp(token1, token2)) {
                strcpy(words[word_count++], token1);
				words = (char**) realloc (words, sizeof(char*) * ((word_count) + 1));
				words[(word_count) - 1] = (char*) realloc (words[(word_count) - 1], strlen(words[(word_count) - 1]) + 1);
				words[(word_count)] = (char*) malloc (shorter + 1);
            }
            token2 = strtok_r(NULL, " ", &saveptr2);
        }
        token1 = strtok_r(NULL, " ", &saveptr1);
    }
    free(words[word_count]);
    words = (char**) realloc (words, sizeof(char*) * (word_count));
    free(s2_copy);

    for (i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }

    for (int i = 0; i < word_count; i++) {
		free(words[i]);
	}
	free(words);

	free(s1);
	free(s2);

	return 0;
}

#undef MAX
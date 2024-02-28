#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

void push(int*, int*);
void pop(int*, int*); // Don't forget to typecast int since it was supposed to be int in the first place
void print(int*, int*);

int main() {
	int action, stack[MAX_SIZE], last_ind = 0;
	void (*acts[3])() = {push, pop, print};
	do {
		system("cls");
		printf("Actions menu:\n1. Push\n2. Pop\n3. Show stack\n4. Exit\n\nInput action number: ");
		scanf("%d", &action);
		if (action > 4 || action < 1) {
			printf("Invalid choice.\n");
			continue;
		}
		acts[action - 1](stack, &last_ind);
	} while (action != 4);
	return 0;
}

void push(int stack[], int* last_ind) {
	char char_input;
	int input;
	do {
		printf("What would you like to push? Enter an integer here (and enter 'c' to cancel): ");
		scanf("%c", &char_input);
		if (isalpha(char_input)) {
			printf("Invalid input. Enter an integer.\n");
		} else if (char_input == 'c') {
			printf("Push canceled.\n");
			return;
		}
	} while (isalpha(char_input));
	input = atoi(&char_input);
	stack[*last_ind] = input;
	(*last_ind)++;
}

void pop (int stack[], int* last_ind) {
	return;
}

void print(int stack[], int* last_ind) {
	return;
}

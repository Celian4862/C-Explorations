#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

void push(int*, int*, int*);
void pop(int*, int*, int*);
void print(int*, int*, int*);

int main() {
	int action, *stack = (int*) malloc (4), size = 1, last_ind = 0;
	void (*acts[3])(int*, int*, int*) = {push, pop, print};
	do {
		system("cls");
		printf("Actions menu:\n1. Push\n2. Pop\n3. Show stack\n4. Exit\n\nInput action number: ");
		scanf("%d", &action);
		if (action > 4 || action < 1) {
			printf("Invalid choice.\n");
			continue;
		}
		acts[action - 1](stack, &size, &last_ind);
	} while (action != 4);
	return 0;
}

void push(int *stack, int* size, int* last_ind) {
	if (*size == MAX_SIZE) {
		printf("Stack has reached maximum capacity.\n");
		sleep(2,5);
		return;
	}
	char char_input;
	int input;
	do {
		printf("What would you like to push? Enter an integer here (and enter 'c' to cancel): ");
		scanf(" %c", &char_input);
		if (char_input == 'c') {
			printf("Push canceled.\n");
			sleep(2,5);
			return;
		} else if (isalpha(char_input)) {
			printf("Invalid input. Enter an integer.\n");
		}
	} while (isalpha(char_input));
	input = atoi(&char_input);
	stack[*last_ind] = input;
	stack = (int*) realloc (stack, 4 * *size);
	(*last_ind)++;
	(*size)++;
}

void pop (int *stack, int* size, int* last_ind) {
	
}

void print(int *stack, int* size, int* last_ind) {
	return;
}

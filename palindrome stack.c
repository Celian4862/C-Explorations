/*
Task: Ask for a word and check if its palindrome. Implement palindrome checking using stack.
*/

#include <stdio.h>
#include <string.h>

#define STACK_MAX 10

typedef struct stack {
    char letter;
    int index;
    struct stack *next;
} Stack;

void get_word(char*);
void push(Stack temp, char letter);

Stack *top;

int main() {
    char input_word[11];
    Stack pal;
    top = &pal;
    pal.index = 0;
    printf("Enter a word (max 10 characters): ");
    get_word(input_word);
    for (int i = 0; i < strlen(input_word); i++) {
        push(, input_word[i]);
    }
    return 0;
}

void get_word(char string[]) {
    scanf(" %s", string);
    string[10] = 0;
}

void push(Stack temp, char letter) {
    if (temp.index == STACK_MAX) {
        printf("The stack is full.\n");
    } else {
        temp.letter = letter;
        top = &temp;
    }
}
#include <stdbool.h>
#include "Student.h";

#define MAX 5

typedef struct {
    Student elems[MAX];
    int count;
} Stack;

Stack createStack();
void initStack(Stack*);
bool isEmpty(Stack);
bool isFull(Stack);
void visualise(Stack);
bool push(Stack*, Student);
bool pop(Stack*);
Student peek(Stack);

Stack getStudent(String program);
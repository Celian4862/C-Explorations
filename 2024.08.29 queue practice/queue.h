#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include "student.h"

typedef struct {
    Student *studList;
    int max;
    int rear;
    int front;
} QueueADT;

void initQueue(QueueADT*, int);
QueueADT createQueue(int);
bool isEmpty(QueueADT);
bool isFull(QueueADT);
void makeEmpty(QueueADT*);
bool enqueue(QueueADT*, Student);
bool dequeue(QueueADT*);
Student front(QueueADT*);
void visualise(QueueADT);
void display(QueueADT);

void initQueue(QueueADT *q, int max) {
    q->max = max;
    q->studList = (Student*) malloc (sizeof(Student) * max);
    q->rear = 0;
    q->front = 1;
}

QueueADT createQueue(int max) {
    QueueADT q;
    q.max = max;
    q.studList = (Student*) malloc (sizeof(Student) * max);
    q.rear = 0;
    q.front = 1;
    return q;
}

bool isEmpty(QueueADT q) {
    return (q.rear + 1) % q.max == q.front;
}

bool isFull(QueueADT q) {
    return (q.rear + 2) % q.max == q.front;
}

void makeEmpty(QueueADT *q) {
    q->rear = (q->front + (q->max - 1)) % q->max;
}

bool enqueue(QueueADT *q, Student s) {
    if (isFull(*q)) {
        return false;
    }
    q->rear = (q->rear + 1) % q->max;
    q->studList[q->rear] = s;
    return true;
}

bool dequeue(QueueADT *q) {
    if (isEmpty(*q)) {
        return false;
    }
    q->front = (q->front + 1) % q->max;
    return true;
}

Student front(QueueADT *q) {
    
}

// Display all elements in the array based on the index, value, and indicator. Do not display an index's value if it is not part of the queue
void visualise(QueueADT q) {
    // Index, value, indicator
    for (int i = 0; i < q.max; i++) {
        printf("Index\t\tValue\t\tIndicator\n");
        printf("%d\t\tStud%d\t\t%c\n", i, q.studList[i].studID, (i == q.front) ? 'F' : (i == q.rear) ? 'R' : ' ');
    }
}

// Display all elements in the queue in order of front to rear
void display(QueueADT q) {
    for (int i = (q.front + 1) % q.max; i != (q.rear + 1) % q.max; i = (i + 1) % q.max) {
        displayStudent(q.studList[i]);
    }
}

Name createName(String fname, String lname) {
    Name n;
    strcpy(n.fname, fname);
    strcpy(n.lname, lname);
    return n;
}

Student createStudent(int studID, Name studName, bool sex, String program, int year) {
    Student s;
    s.studID = studID;
    s.studName = studName;
    s.sex = sex;
    strcpy(s.program, program);
    s.year = year;
    return s;
}

#endif
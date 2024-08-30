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
    return q.studList[q.front];
}

void visualise(QueueADT q) {
    String studID;
    printf("-%13s%-13s%Indicator\n", "Index", "Student ID");
    for (int i = 0; i < q.max; i++) {
        if (i >= q.front && i <= q.rear) {
            sprintf(studID, "%d", q.studList[i].studID);
        } else {
            studID = "";
        }
        printf("%-13d%-13s%c\n", i, studID, (i == q.front) ? 'F' : (i == q.rear) ? 'R' : ' ');
    }
}

void display(QueueADT q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q.front; i != (q.rear + 1) % q.max; i = (i + 1) % q.max) {
        displayStudent(q.studList[i]);
    }
}

#endif
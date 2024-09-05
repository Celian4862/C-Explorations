#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

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
    Student s;
    if (isEmpty(*q)) {
        s.studID = -1;
    } else {
        s = q->studList[q->front];
    }
    return s;
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

void displayStudent(Student s) {
    printf("Student ID: %d\n", s.studID);
    printf("Student Name: %s %s\n", s.studName.fname, s.studName.lname);
    printf("Sex: %c\n", s.sex);
    printf("Program: %s\n", s.program);
    printf("Year: %d\n", s.year);
}
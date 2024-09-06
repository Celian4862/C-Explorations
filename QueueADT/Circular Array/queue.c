#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
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
    if ((q.rear + 1) % q.max == q.front) {
        printf("The queue is empty.\n");
        #ifdef _WIN32
            Sleep(2000);
        #else
            sleep(2);
        #endif
        return true;
    }
    return false;
}

bool isFull(QueueADT q) {
    if ((q.rear + 2) % q.max == q.front) {
        printf("The queue is full.\n");
        #ifdef _WIN32
            Sleep(2000);
        #else
            sleep(2);
        #endif
        return true;
    }
    return false;
}

void makeEmpty(QueueADT *q) {
    q->rear = (q->front + (q->max - 1)) % q->max;
    printf("Queue emptied.\n");
    #ifdef _WIN32
        Sleep(2000);
    #else
        sleep(2);
    #endif
}

bool enqueue(QueueADT *q, Student s) {
    if (isFull(*q)) {
        return false;
    }
    q->rear = (q->rear + 1) % q->max;
    q->studList[q->rear] = s;
    printf("Enqueue successful.\n");
    #ifdef _WIN32
        Sleep(2000);
    #else
        sleep(2);
    #endif
    return true;
}

bool dequeue(QueueADT *q) {
    if (isEmpty(*q)) {
        return false;
    }
    q->front = (q->front + 1) % q->max;
    printf("Dequeue successful.\n");
    #ifdef _WIN32
        Sleep(2000);
    #else
        sleep(2);
    #endif
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

void visualise(QueueADT q) {
    if (isEmpty(q)) {
        return;
    }
    String studID;
    printf("%-13s%-13sIndicator\n", "Index", "Student ID");
    for (int i = 0; i < q.max; i++) {
        if (i >= q.front && i <= q.rear) {
            sprintf(studID, "%d", q.studList[i].studID);
        } else {
            strcpy(studID, "");
        }
        printf("%-13d%-13s%s\n", i, studID, (i == q.front && i == q.rear) ? "F/R" : (i == q.front) ? "F" : (i == q.rear) ? "R" : " ");
    }
}

void display(QueueADT q) {
    if (isEmpty(q)) {
        return;
    }
    for (int i = q.front; i != (q.rear + 1) % q.max; i = (i + 1) % q.max) {
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

#endif
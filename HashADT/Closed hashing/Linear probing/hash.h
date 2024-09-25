#ifndef HASH_H
#define HASH_H

#include <stdbool.h>

typedef enum flag {
    EMPTY,
    DELETED,
    OCCUPIED
} flag;

typedef struct {
    int studID;
    char studName[30];
    char program[10];
    int year;
    flag status;
} Student;

typedef struct {
    Student *elem; // Dynamically allocate memory for rehashing
    int count;
} HashTable;

/*  Get the hash based on the summation of the first 3 letters of the name and the letters in the program.
    Assume that the name is always at least 3 letters long.
    The function must be able to return a value from 0 - 19. */
int getHash(Student s);

void initDictionary(HashTable *ht);
// Use insertSorted if multiple data are already in the list.
bool insert(HashTable *ht, Student s);
bool deleteItem(HashTable *ht, Student s);

void visualiseTable(HashTable ht);

void freeHash(HashTable *ht);

#endif
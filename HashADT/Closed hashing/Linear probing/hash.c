#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"

int getHash(Student s) {
    int hash = 0;
    for (int i = 0; i < 3; i++) {
        hash += (int) s.studName[i];
    }
    for (int i = 0; i < strlen(s.program); i++) {
        hash += (int) s.program[i];
    }
    return hash % 20;
    // 0 <= remainder < divisor
}

void initDictionary(HashTable *ht) {
    ht->elem = (Student*) malloc (sizeof(Student) * 20);
    ht->count = 0;
    int i;
    for (i = 0; i < 20; i++) {
        ht->elem[i].status = EMPTY;
    }
}

bool insert(HashTable *ht, Student s) {
    
}

bool deleteItem(HashTable *ht, Student s) {
}

void visualiseTable(HashTable ht) {
}
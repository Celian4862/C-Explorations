﻿#include <stdio.h>
#include <string.h>

#ifndef MAX
#define MAX 5
#endif

#ifndef MAX_CHAR
#define MAX_CHAR 20
#endif

struct temp
{
	char fname[MAX_CHAR];	
	char lname[MAX_CHAR];	
	char program[MAX_CHAR];
	int age;
};

struct info
{
	struct temp var[MAX];
};

struct temp *sortByProgramAsc(struct temp *var);
struct info sortByLastNameAsc(struct temp *var);
void printThisOne(struct temp *var);
void printThisTwo(struct info var);

int main(int argc, char *argv[]) {
	struct temp var[MAX] = {{"Chris","Maderazo","BSCOMPE",51},
						  {"John","Duterte","BSIT",30},
						  {"asdf","qwer","BSCS",19},
						  {"wert","sdfg","BSIT",20},
						  {"sdfg","hdfgh","BSCS",30}};
	struct temp *var2 = sortByProgramAsc(var);
	printThisOne(var2);
	
	struct info var3 = sortByLastNameAsc(var);	
	printThisTwo(var3);	
	
	return 0;
}

struct temp *sortByProgramAsc(struct temp *var) {
	
}

struct info sortByLastNameAsc(struct temp *var) {
	
}

void printThisOne(struct temp *var) {
	
}

void printThisTwo(struct info var) {
	
}
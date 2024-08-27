#include <stdio.h>
#include <string.h>
#include "ArrayListStatic.h"

List createList() {
	List list = {{0}, 0};
	return list;
}

void displayList(List list) {
	int i;
	for (i = 0; i < list.count; i++) {
		printf("%d ", list.elems[i]);
	}
	printf("\n");
}

void insertFront(List *list, int value) {
	memcpy(list->elems + 1, list->elems, sizeof(int) * list->count);
	list->elems[0] = value;
	list->count++;
}

void insertRear(List *list, int value) {
	list->elems[list->count++] = value;
}

void insertInto(List *list, int value, int position) {
	memcpy(list->elems + position + 1, list->elems + position, sizeof(int) * (list->count - position));
	list->elems[position] = value;
	list->count++;
}

void deleteFront(List *list) {
	memcpy(list->elems, list->elems + 1, sizeof(int) * (list->count - 1));
	list->count--;
}

void deleteRear(List *list) {
	list->count--;
}

void deleteFrom(List *list, int position) {
	memcpy(list->elems + position, list->elems + position + 1, sizeof(int) * (list->count - position));
	list->count--;
}

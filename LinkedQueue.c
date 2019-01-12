#include <malloc.h>
#include <stdio.h>
#include "LinkedQueue.h"

struct node {
	item value;
	struct node* next;
};

struct LinkedQueue {
	struct node* head;
	struct node* tail;
	int size;
};

LinkedQueue newLinkedQueue () {
	LinkedQueue res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	res->head = NULL;
	res->tail = NULL;
	res->size = 0;
	return res;
}

int emptyQueue (LinkedQueue q) {
	if (!q) {
		return -1;
	}
	return q->size == 0;
}

int enqueue (LinkedQueue q, item val) {
	if (!q) {
		return -1;
	}
	if (!val) {
		return -1;
	}
	struct node* nuovo = malloc(sizeof(*nuovo));
	if (!nuovo) {
		return 0;
	}
	nuovo->value = val;
	if (!q->head) {
		q->head = nuovo;
	} else {
		q->tail->next = nuovo;
	}
	q->tail = nuovo;
	q->size++;
	return 1;
}

item dequeue (LinkedQueue q) {
	if (!q) {
		return NULL;
	}
	if (q->size == 0) {
		return NULL;
	}
	item res = q->head->value;
	struct node* del = q->head;
	q->head = q->head->next;
	free(del);
	if (!q->head) {
		q->tail = NULL;
	}
	q->size--;
	return res;
}
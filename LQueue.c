#include <malloc.h>
#include <stdio.h>
#include "LQueue.h"

struct node {
	Item value;
	struct node* next;
};

struct LQueue {
	struct node* head;
	struct node* tail;
	int size;
};

LQueue newQueue () {
	LQueue res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	res->head = NULL;
	res->tail = NULL;
	res->size = 0;
	return res;
}

int emptyQueue (LQueue q) {
	if (!q) {
		return -1;
	}
	return q->size == 0;
}

int enqueue (LQueue q, Item val) {
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
	nuovo->next = NULL;
	if (!q->head) {
		q->head = nuovo;
	} else {
		q->tail->next = nuovo;
	}
	q->tail = nuovo;
	q->size++;
	return 1;
}

Item dequeue (LQueue q) {
	if (!q) {
		return NULL;
	}
	if (q->size == 0) {
		return NULL;
	}
	Item res = q->head->value;
	struct node* del = q->head;
	q->head = q->head->next;
	free(del);
	if (!q->head) {
		q->tail = NULL;
	}
	q->size--;
	return res;
}

int outputQueue (LQueue q) {
	if (!q) {
		return 0;
	}
	if (q->size == 0) {
		return 1;
	}
	struct node* tmp = q->head;
	while (tmp != NULL) {
		if (tmp->next) {
			outputItem(tmp->value);
			printf(", ");
		} else {
			outputItem(tmp->value);
			printf(".\n");
			break;
		}
		tmp = tmp->next;
	}
	return 1;
}
#include <malloc.h>
#include <stdio.h>
#include "AQueue.h"

#define MAXQUEUE 100

struct AQueue {
	Item* vet;
	int size;
	int num_elem;
	int head;
	int tail;
};

AQueue newQueue (int max_size) {
	AQueue res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	if (max_size <= 0) {
		max_size = MAXQUEUE;
	}
	res->size = max_size;
	res->vet = malloc(res->size * sizeof(Item));
	res->num_elem = 0;
	return res;
}

int emptyQueue (AQueue q) {
	if (!q) {
		return -1;
	}
	return q->num_elem == 0;
}

int enqueue (AQueue q, Item val) {
	if (!q) {
		return -1;
	}
	if (!val) {
		return -1;
	}
	if (q->num_elem == q->size) {
		return 0;
	}
	if (q->num_elem == 0) {
		q->head = 0;
		q->tail = 0;
	} else {
		q->tail = (q->tail + 1) % q->size;
	}
	q->vet[q->tail] = val;
	q->num_elem++;
	return 1;
}

Item dequeue (AQueue q) {
	if (!q) {
		return NULL;
	}
	if (q->num_elem == 0) {
		return NULL;
	}
	Item res = q->vet[q->head];
	q->head = (q->head + 1) % q->size;
	q->num_elem--;
	return res;
}

int outputQueue (AQueue q) {
	if (!q) {
		return 0;
	}
	if (q->num_elem == 0) {
		return 1;
	}
	int pos;
	for (pos = q->head; pos != q->tail; pos = (pos + 1) % q->size) {
		outputItem(q->vet[pos]);
		printf(", ");
	}
	outputItem(q->vet[q->tail]);
	printf(".\n");
	return 1;
}
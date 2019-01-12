#include <malloc.h>
#include <stdio.h>
#include "ArrayQueue.h"

#define MAXQUEUE 100

struct ArrayQueue {
	item* vet;
	int size;
	int num_elem;
	int head;
	int tail;
};

ArrayQueue newArrayQueue (int max_size) {
	ArrayQueue res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	if (max_size <= 0) {
		max_size = MAXQUEUE;
	}
	res->size = max_size;
	res->vet = malloc(res->size * sizeof(item));
	res->num_elem = 0;
	return res;
}

int emptyQueue (ArrayQueue q) {
	if (!q) {
		return -1;
	}
	return q->num_elem == 0;
}

int enqueue (ArrayQueue q, item val) {
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

item dequeue (ArrayQueue q) {
	if (!q) {
		return NULL;
	}
	if (q->num_elem == 0) {
		return NULL;
	}
	item res = q->vet[q->head];
	q->head = (q->head + 1) % q->size;
	q->num_elem--;
	return res;
}

int outputQueue (ArrayQueue q) {
	if (!q) {
		return 0;
	}
	if (q->num_elem) {
		return 1;
	}
	int pos;
	for (pos = q->head; pos != q->tail; pos = (pos + 1) % q->size) {
		outputItem(q->vet[pos]);
	}
	outputItem(q->vet[q->tail]);
	return 1;
}
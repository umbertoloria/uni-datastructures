#include <stdio.h>
#include <malloc.h>
#include "AStack.h"
#define STARTSIZE 50
#define ADDSIZE 20

struct AStack {
	Item* vet;
	int top;
	int size;
};

AStack newStack () {
	AStack res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	res->vet = malloc(STARTSIZE * sizeof(Item));
	if (!res->vet) {
		free(res);
		return NULL;
	}
	res->size = STARTSIZE;
	res->top = 0;
	return res;
}

int emptyStack (AStack s) {
	if (!s) {
		return -1;
	}
	return s->top == 0;
}

int push (AStack s, Item val) {
	if (!s) {
		return -1;
	}
	if (!val) {
		return -1;
	}
	if (s->top == s->size) {
		Item* tmp = realloc(s->vet, (s->size + ADDSIZE) * sizeof(Item));
		if (!tmp) {
			return 0;
		}
		s->vet = tmp;
		s->size += ADDSIZE;
	}
	s->vet[s->top] = val;
	s->top++;
	return 1;
}

int pop (AStack s) {
	if (!s) {
		return -1;
	}
	if (s->top == 0) {
		return 0;
	}
	s->top--;
	return 1;
}

Item top (AStack s) {
	if (!s) {
		return NULL;
	}
	if (s->top < 1) {
		return NULL;
	}
	return s->vet[s->top - 1];
}

int outputStack (AStack s) {
	if (!s) {
		return 0;
	}
	int i;
	for (i = s->top - 1; i > 0; i--) {
		outputItem(s->vet[i]);
		printf(", ");
	}
	outputItem(s->vet[i]);
	printf("\n");
	return 1;
}
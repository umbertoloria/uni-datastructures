#include <stdio.h>
#include <malloc.h>
#include "ArrayStack.h"
#define STARTSIZE 50
#define ADDSIZE 20

struct ArrayStack {
	item* vet;
	int top;
	int size;
};

ArrayStack newArrayStack () {
	ArrayStack res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	res->vet = malloc(STARTSIZE * sizeof(item));
	if (!res->vet) {
		free(res);
		return NULL;
	}
	res->size = STARTSIZE;
	res->top = 0;
	return res;
}

int emptyStack (ArrayStack s) {
	if (!s) {
		return -1;
	}
	return s->top == 0;
}

int push (ArrayStack s, item val) {
	if (!s) {
		return -1;
	}
	if (!val) {
		return -1;
	}
	if (s->top == s->size) {
		item* tmp = realloc(s->vet, (s->size + ADDSIZE) * sizeof(item));
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

int pop (ArrayStack s) {
	if (!s) {
		return -1;
	}
	if (s->top == 0) {
		return 0;
	}
	s->top--;
	return 1;
}

item top (ArrayStack s) {
	if (!s) {
		return NULL;
	}
	if (s->top < 1) {
		return NULL;
	}
	return s->vet[s->top - 1];
}

int outputStack (ArrayStack s) {
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
}
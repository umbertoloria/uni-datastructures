#include <stdio.h>
#include <malloc.h>
#include "LStack.h"

struct node {
	Item value;
	struct node* next;
};

struct LStack {
	struct node* top;
};

LStack newStack () {
	LStack res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	res->top = NULL;
	return res;
}

int emptyStack (LStack s) {
	if (!s) {
		return -1;
	}
	return s->top == NULL;
}

int push (LStack s, Item val) {
	if (!s) {
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
	nuovo->next = s->top;
	s->top = nuovo;
	return 1;
}

int pop (LStack s) {
	if (!s) {
		return -1;
	}
	if (s->top == NULL) {
		return 0;
	}
	struct node* tmp = s->top;
	s->top = s->top->next;
	free(tmp);
	return 1;
}

Item top (LStack s) {
	if (!s) {
		return NULL;
	}
	if (s->top == NULL) {
		return NULL;
	}
	return s->top->value;
}

int outputStack (LStack s) {
	if (!s) {
		return 0;
	}
	struct node* tmp = s->top;
	int i;
	for (i = 0; tmp; i++) {
		outputItem(tmp->value);
		tmp = tmp->next;
		if (tmp) {
			printf(", ");
		}
	}
	free(tmp);
	printf("\n");
	return 1;
}

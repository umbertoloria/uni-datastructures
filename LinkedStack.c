#include <stdio.h>
#include <malloc.h>
#include "LinkedStack.h"

struct node {
	item value;
	struct node* next;
};

struct LinkedStack {
	struct node* top;
};

LinkedStack newLinkedStack () {
	LinkedStack res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	res->top = NULL;
	return res;
}

int emptyStack (LinkedStack s) {
	if (!s) {
		return -1;
	}
	return s->top == NULL;
}

int push (LinkedStack s, item val) {
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

int pop (LinkedStack s) {
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

item top (LinkedStack s) {
	if (!s) {
		return NULL;
	}
	if (s->top == NULL) {
		return NULL;
	}
	return s->top->value;
}

int outputStack (LinkedStack s) {
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
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "Item.h"

struct Item {
	int value;
};

Item newItem (int value) {
	Item res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	res->value = value;
	return res;
}

int equalsItem (Item a, Item b) {
	if (!a || !b) {
		return -1;
	}
	return a->value == b->value;
}

int cmpItem (Item a, Item b) {
	if (!a || !b) {
		return -1;
	}
	return a->value - b->value;
}

int outputItem (Item i) {
	if (i) {
		printf("%d", i->value);
		return 1;
	} else {
		printf("NULL");
		return 0;
	}
}

int inputItem (Item* i) {
	*i = malloc(sizeof(Item));
	if (!*i) {
		return 0;
	}
	scanf("%d", &(*i)->value);
	return 1;
}

Item cloneItem (Item i) {
	if (!i) {
		return NULL;
	}
	return newItem(i->value);
}

int destroyItem (Item* i) {
	if (*i) {
		free(*i);
		*i = NULL;
		return 1;
	}
	return 0;
}
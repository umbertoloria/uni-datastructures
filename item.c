#include <stdio.h>
#include <malloc.h>
#include "item.h"

struct item {
	int value;
};

item newItem (int val) {
	item res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	res->value = val;
	return res;
}

int outputItem (item i) {
	if (i) {
		printf("%d", i->value);
		return 1;
	} else {
		printf("NULL");
		return 0;
	}
}

int inputItem (item* i) {
	*i = malloc(sizeof(item));
	if (!*i) {
		return 0;
	}
	scanf("%d", &((*i)->value));
	return 1;
}

int eq (item a, item b) {
	if (!a || !b) {
		return -1;
	}
	return a->value == b->value;
}

int getInt (item i) {
	if (!i) {
		return -1;
	}
	return i->value;
}

int destroyItem (item* i) {
	if (*i) {
		free(*i);
		*i = NULL;
		return 1;
	}
	return 0;
}


item cloneItem (item i) {
	if (!i) {
		return NULL;
	}
	return newItem(i->value);
}
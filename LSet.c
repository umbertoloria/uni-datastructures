#include <malloc.h>
#include <stdio.h>
#include "LSet.h"

struct node {
	Item value;
	struct node* next;
};

struct LSet {
	struct node* first;
	int size;
};

static struct node* makeNode (Item val, struct node* next) {
	struct node* nuovo = malloc(sizeof(*nuovo));
	if (!nuovo) {
		return 0;
	}
	nuovo->value = val;
	nuovo->next = next;
	return nuovo;
}

LSet newSet () {
	LSet s = malloc(sizeof(*s));
	s->first = NULL;
	s->size = 0;
	return s;
}

int emptySet (LSet s) {
	if (!s) {
		return -1;
	}
	return s->size == 0;
}

int cardinality (LSet s) {
	if (!s) {
		return -1;
	}
	return s->size;
}

int contains (LSet s, Item val) {
	if (!s) {
		return -1;
	}
	if (!val) {
		return -1;
	}
	struct node* tmp = s->first;
	while (tmp) {
		if (equalsItem(tmp->value, val) == 1) {
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

int insertSet (LSet s, Item val) {
	if (!s) {
		return -1;
	}
	if (!val) {
		return -1;
	}
	if (!s->first) {
		s->first = makeNode(val, NULL);
		if (!s->first) {
			return 0;
		}
		s->size++;
		return 1;
	}
	struct node* tmp = s->first;

	if (equalsItem(tmp->value, val) == 1) {
		return 0;
	}

	while (tmp->next) {
		if (equalsItem(tmp->next->value, val) == 1) {
			return 0;
		}
		tmp = tmp->next;
	}

	tmp->next = makeNode(val, NULL);
	if (!tmp->next) {
		return 0;
	}
	s->size++;
	return 1;
}

int removeSet (LSet s, Item val) {
	if (!s) {
		return 0;
	}
	if (!s->first) {
		return 0;
	}

	struct node* tmp = s->first;

	if (equalsItem(tmp->value, val) == 1) {
		s->first = s->first->next;
		free(tmp);
		s->size--;
		return 1;
	}

	while (tmp->next) {
		if (equalsItem(tmp->next->value, val) == 1) {
			struct node* tmp1 = tmp->next;
			tmp->next = tmp1->next;
			free(tmp1);
			s->size--;
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}

int unionSet (LSet s1, LSet s2) {
	if (!s1 || !s2) {
		return 0;
	}

	struct node* tmp = s2->first;
	int res = 0;

	while (tmp) {
		if (insertSet(s1, tmp->value) == -1) {
			return 0;
		}
		tmp = tmp->next;
	}
	return 1;
}

int intersectSet (LSet s1, LSet s2) {
	if (!s1 || !s2) {
		return 0;
	}

	if (!s1->first) {
		return 1;
	}

	struct node* tmp = s1->first;
	struct node* tmp1;

	while (tmp->next) {
		if (contains(s2, tmp->next->value) == 0) {
			tmp1 = tmp->next;
			tmp->next = tmp1->next;
			s1->size--;
			free(tmp1);
		} else {
			tmp = tmp->next;
		}
	}

	if (contains(s2, s1->first->value) == 0) {
		tmp1 = s1->first;
		s1->first = s1->first->next;
		s1->size--;
		free(tmp1);
	}
}

int subSet (LSet s1, LSet s2) {
	if (!s1 || !s2) {
		return 0;
	}

	if (!s1->first) {
		return 1;
	}

	struct node* tmp = s1->first;
	struct node* tmp1;

	while (tmp->next) {
		if (contains(s2, tmp->next->value) == 1) {
			tmp1 = tmp->next;
			tmp->next = tmp1->next;
			s1->size--;
			free(tmp1);
		} else {
			tmp = tmp->next;
		}
	}

	if (contains(s2, s1->first->value) == 1) {
		tmp1 = s1->first;
		s1->first = s1->first->next;
		s1->size--;
		free(tmp1);
	}
}

int outputSet (LSet s) {
	if (!s) {
		return 0;
	}
	if (!s->first) {
		return 0;
	}
	struct node* tmp = s->first;
	printf("%d", getValue(tmp->value));
	tmp = tmp->next;
	if (!tmp) {
		printf(".\n");
		return 1;
	}
	while (tmp) {
		printf(", %d", getValue(tmp->value));
		tmp = tmp->next;
	}
	printf(".\n");
	return 1;
}
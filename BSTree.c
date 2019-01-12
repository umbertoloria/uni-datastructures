#include <malloc.h>
#include <stdio.h>
#include "Item.h"
#include "BSTree.h"

struct node {
	Item value;
	struct node* left;
	struct node* right;
};

struct BSTree {
	struct node* root;
	int size;
};

static int r_contains (struct node* t, Item elem) {
	if (!t) {
		return 0;
	}
	int cmp = cmpItem(elem, t->value);
	if (cmp == 0) {
		return 1;
	} else if (cmp < 0) {
		return r_contains(t->left, elem);
	}
	return r_contains(t->right, elem);
}

static struct node* makeLeaf (Item elem) {
	struct node* n = malloc(sizeof(struct node));
	if (!n) {
		return NULL;
	}
	n->value = elem;
	n->left = NULL;
	n->right = NULL;
	return n;
}

static int r_insert (struct node** t, Item elem) {
	if (!*t) {
		*t = makeLeaf(elem);
		if (!*t) {
			return -1;
		}
		return 1;
	}
	int cmp = cmpItem(elem, (*t)->value);
	if (cmp < 0) {
		return r_insert(&(*t)->left, elem);
	} else if (cmp > 0) {
		return r_insert(&(*t)->right, elem);
	}
	return 0;
}

static Item deleteMax (struct node** t) {
	if ((*t)->right) {
		return deleteMax(&(*t)->right);
	}
	Item x = (*t)->value;
	struct node* tmp = *t;
	*t = (*t)->left;
	free(tmp);
	return x;
}

static int r_delete (struct node** t, Item elem) {
	if (!*t) {
		return 0;
	}
	int res, cmp;
	cmp = cmpItem(elem, (*t)->value);
	if (cmp < 0) {
		res = r_delete(&(*t)->left, elem);
	} else if (cmp > 0) {
		res = r_delete(&(*t)->right, elem);
	} else if (!(*t)->left) {
		struct node* tmp = *t;
		*t = (*t)->right;
		free(tmp);
		res = 1;
	} else if (!(*t)->right) {
		struct node* tmp = *t;
		*t = (*t)->left;
		free(tmp);
		res = 1;
	} else {
		(*t)->value = deleteMax(&(*t)->left);
		res = 1;
	}
	return res;
}

static void r_output (struct node* t) {
	if (t) {
		r_output(t->left);
		outputItem(t->value);
		printf("\n");
		r_output(t->right);
	}
}

BSTree newBSTree () {
	BSTree t = malloc(sizeof(*t));
	if (!t) {
		return NULL;
	}
	t->root = NULL;
	t->size = 0;
	return t;
}

int emptyBSTree (BSTree t) {
	if (!t) {
		return -1;
	}
	return t->size == 0;
}

int cardinality (BSTree t) {
	if (!t) {
		return -1;
	}
	return t->size;
}

int contains (BSTree t, Item elem) {
	if (!t) {
		return -1;
	}
	return r_contains(t->root, elem);
}

int insertBSTree (BSTree t, Item elem) {
	if (!t) {
		return -1;
	}
	int res = r_insert(&(t->root), elem);
	if (res == 1) {
		t->size++;
	}
	return res;
}

int removeBSTree (BSTree t, Item elem) {
	if (!t) {
		return -1;
	}
	int res = r_delete(&(t->root), elem);
	if (res == 1) {
		t->size--;
	}
	return res;
}

int outputBSTree (BSTree t) {
	if (!t) {
		return -1;
	}
	r_output(t->root);
	printf("\n");
	return 1;
}
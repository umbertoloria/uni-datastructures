#include <stdio.h>
#include <malloc.h>
#include "BTree.h"

struct node {
	Item value;
	struct node* left;
	struct node* right;
};

BTree newBTree () {
	return NULL;
}

int emptyBTree (BTree t) {
	return !t;
}

Item getRoot (BTree t) {
	if (!t) {
		return NULL;
	}
	return t->value;
}

BTree leftBTree (BTree t) {
	if (!t) {
		return NULL;
	}
	return t->left;
}

BTree rightBTree (BTree t) {
	if (!t) {
		return NULL;
	}
	return t->right;
}

BTree consBTree (Item val, BTree sx, BTree dx) {
	struct node* nuovo = malloc(sizeof(*nuovo));
	if (!nuovo) {
		return NULL;
	}
	nuovo->value = val;
	nuovo->left = sx;
	nuovo->right = dx;
	return nuovo;
}

void preOrder (BTree t) {
	if (!t) {
		return;
	}
	outputItem(t->value);
	printf("\n");
	preOrder(t->left);
	preOrder(t->right);
}

void postOrder (BTree t) {
	if (!t) {
		return;
	}
	postOrder(t->left);
	postOrder(t->right);
	outputItem(t->value);
	printf("\n");
}

void inOrder (BTree t) {
	if (!t) {
		return;
	}
	inOrder(t->left);
	outputItem(t->value);
	printf("\n");
	inOrder(t->right);
}

/*void levelOrder (BTree t) {
	BTree tsx, tdx, tv;
	Queue q = newQueue();
	enqueue(q, t);
	while (!emptyQueue(q)) {
		tv = dequeue(q);
		outputItem(getRoot(tv));
		tsx = leftBTree(tv);
		tdx = rightBTree(tv);
		if (tsx) {
			enqueue(q, tsx);
		}
		if (tdx) {
			enqueue(q, tdx);
		}
	}
}*/
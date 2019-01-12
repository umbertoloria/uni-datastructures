#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "HashTable.h"

struct hash {
	int size;
	struct elem** table;
};

struct elem {
	char* key;
	Item value;
	struct elem* next;
};

static void deleteList (struct elem* p) {
	if (p) {
		deleteList(p->next);
		free(p);
	}
}

static int hash (char* k, int m) {
	int val;
	int len = (int) strlen(k);
	val = k[0] + k[len - 1] + len;
	return val % m;
}

HashTable newHashTable (int size) {
	HashTable h = malloc(sizeof(*h));
	if (!h) {
		return NULL;
	}
	h->size = size;
	h->table = (struct elem**) malloc(size * sizeof(struct elem*));
	int i;
	for (i = 0; i < size; i++) {
		h->table[i] = NULL;
	}
	return h;
}

int insertHash (HashTable h, char* key, Item i) {
	struct elem* head;
	struct elem* curr;
	int idx = hash(key, h->size);
	head = h->table[idx];
	for (curr = head; curr; curr = curr->next) {
		if (strcmp(curr->key, key) == 0) {
			return -1;
		}
	}
	h->table[idx] = malloc(sizeof(struct elem));
	if (!h->table[idx]) {
		return -1;
	}
	h->table[idx]->key = malloc(strlen(key) + 1);
	if (!h->table[idx]->key) {
		free(h->table[idx]);
		return -1;
	}
	strcpy(h->table[idx]->key, key);
	h->table[idx]->value = i;
	h->table[idx]->next = head;
	return 0;
}

Item searchHash (HashTable h, char* key) {
	int idx = hash(key, h->size);
	struct elem* curr = h->table[idx];
	for (; curr; curr = curr->next) {
		if (strcmp(curr->key, key) == 0) {
			return curr->value;
		}
	}
	return NULL;
}

int deleteHash (HashTable h, char* key) {
	struct elem* prev;
	struct elem* curr;
	struct elem* head;
	int idx = hash(key, h->size);
	prev = head = h->table[idx];
	for (curr = head; curr; curr = curr->next) {
		if (strcmp(curr->key, key) == 0) {
			if (curr == head) {
				h->table[idx] = curr->next;
			} else {
				prev->next = curr->next;
			}
			free(curr->key);
			destroyItem(&(curr->value));
			free(curr);
			return 1;
		}
		prev = curr;
	}
	return 0;
}

void destroyHash (HashTable h) {
	int i;
	for (i = 0; i < h->size; i++) {
		deleteList(h->table[i]);
	}
	free(h->table);
	h->table = NULL;
}
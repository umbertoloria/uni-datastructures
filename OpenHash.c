#include <string.h>
#include <malloc.h>
#include "OpenHash.h"

struct elem {
	char* key;
	Item value;
};

static struct elem* newElem (char* key, Item item) {
	struct elem* res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	res->key = malloc(strlen(key) + 1);
	if (!res->key) {
		free(res);
		return NULL;
	}
	strcpy(res->key, key);
	res->value = item;
	return res;
}

static Item getItem (struct elem* e) {
	if (!e) {
		return NULL;
	}
	return e->value;
}

struct hash {
	int size;
	struct elem** hash;
};

int hash (char* k, int size) {
	int len = (int) strlen(k);
	int v = k[0] + k[len - 1] + len;
	return v % size;
}

int hash2 (char* k, int size) {
	int sum = 0;
	while (*k != '\0') {
		sum += *k;
		k++;
	}
	return sum % size;
}

int hash_oa (char* k, int i, int size) {
	// Linear Probing
	return (hash(k, size) + i) % size;
	// Double Hashing
	// return (hash(k, size) + i * hash2(k, size)) % size;
}

OpenHash newOpenHash (int size) {
	OpenHash h = malloc(sizeof(*h));
	if (!h) {
		return NULL;
	}
	h->size = size;
	h->hash = (struct elem**) malloc(size * sizeof(struct elem*));
	int i;
	for (i = 0; i < size; i++) {
		h->hash[i] = NULL;
	}
	return h;
}

int hashInsert (OpenHash h, char* key, Item item) {
	int idx, start;
	int i = 0;
	int len = h->size;
	start = idx = hash_oa(key, i, h->size);
	do {
		if (!h->hash[idx]) {
			h->hash[idx] = newElem(key, item);
			return 1;
		} else {
			i++;
			idx = hash_oa(key, i, h->size);
		}
	} while (idx != start);
	return 0;
}

Item hashSearch (OpenHash h, char* key) {
	int idx, start;
	int i = 0;
	start = idx = hash_oa(key, i, h->size);
	do {
		if (!h->hash[idx]) {
			return NULL;
		} else if (!strcmp(h->hash[idx]->key, key)) {
			return h->hash[idx]->value;
		} else {
			i++;
			idx = hash_oa(key, i, h->size);
		}
	} while (idx != start);
	return NULL;
}

int  hashDelete (OpenHash h, char* key) {
	/*
	 *
	 * Si genera un indice per questa chiave
	 * int idx = hash(key, h->size);
	 *
	 * Si libera la memoria
	 * destroyItem(&h->hash[idx]->value);
	 * free(h->hash[idx]->key);
	 * free(h->hash[idx]);
	 *
	 * Si marca il posto come DELETED
	 * h->hash[idx] = DELETED;
	 *
	 * Se si fosse settato NULL, ricerca ed inserimento non funzionerebbero
	 * perché non si ignorerebbero parte di possibili risultati di posti
	 * nell'array, visto che la scansione si fermerebbe al primo NULL.
	 *
	 */
	return 0;
}

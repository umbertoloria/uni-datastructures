#include <malloc.h>
#include <stdio.h>
#include "List.h"

// Nodo

struct node {
	Item value;
	struct node* next;
};

/**
 * Restituisce un nuovo nodo che contiene l'item e il nodo next forniti.
 *
 * Post: m=node(val,next)
 *
 * Restituisce: Un nodo con item e next forniti nei parametri
 *              NULL se non è stato possibile allocare memoria.
 */
static struct node* makeNode (Item val, struct node* next) {
	struct node* res = malloc(sizeof(*res));
	if (!res) {
		return NULL;
	}
	Item copia = cloneItem(val);
	if (!copia) {
		free(res);
		return NULL;
	}
	res->value = copia;
	res->next = next;
	return res;
}

/**
 * Restituisce un nodo tra i cui nodi puntati ne manca uno in posizione pos.
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 *      Il controllo di questa precondizione non è presente nella funzione
 *      "removeNode" perché questa funzione è chiamata solo dalla funzione
 *      "removeList".
 *      La chiamata a "removeNode" viene effettuata nella funzione "removeList"
 *      solo se la precondizione di "removeList" è soddisfatta. Quindi, il
 *      controllo di questa precondizione non è presente nella funzione
 *      "removeNode" perché viene ereditato da "removeList".
 *
 * Post: r=node(...) che non contiene un preciso nodo in posizione pos tra i
 *       suoi nodi concatenati.
 *
 * Restituisce: 0 se si viola la precondizione (controllo commentato).
 *              Un nodo:
 *                      Se pos = 0: Restituisce n->next.
 *                      Altrimenti: Restituisce n (tra i cui nodi puntati manca
 *                                  quello in posizione pos).
 */
static struct node* removeNode (struct node* n, int pos) {
	// Nella documentazione è motivata l'esclusione di questo controllo.
	/*if (!n) {
		return 0;
	}*/
	struct node* del;
	if (pos == 0) {
		del = n;
		n = n->next;
	} else {
		struct node* prec = n;
		int i;
		for (i = 0; i < pos - 1; i++) {
			prec = prec->next;
		}
		del = prec->next;
		prec->next = prec->next->next;
	}
	destroyItem(&del->value);
	free(del);
	return n;
}

/**
 * Inserisce un nodo tra tanti nodi concatenti in una posizione stabilita.
 *
 * Post: i=node(...) dove tra i nodi concatenati ne è presente uno nuovo in
 *       posizione pos.
 *
 * Restituisce: Il nodo che contiene tra i suoi nodi concatenati un nuovo nodo
 *              nella posizione fornita che contiene il valore fornito.
 *              NULL se non è possibile allocare memoria per il nuovo nodo.
 */
static struct node* insertNode (struct node* n, int pos, Item val) {
	if (pos == 0) {
		return makeNode(val, n);
	}
	int i;
	struct node* prec = n;
	for (i = 0; i < pos - 1; i++) {
		prec = prec->next;
	}
	struct node* n1 = makeNode(val, prec->next);
	if (!n1) {
		return NULL;
	}
	prec->next = n1;
	return n;
}

// Lista

struct List {
	struct node* first;
	int size;
};

List newList () {
	List l = malloc(sizeof(*l));
	if (!l) {
		return NULL;
	}
	l->first = NULL;
	l->size = 0;
	return l;
}

int emptyList (List l) {
	if (!l) {
		return -1;
	}
	return l->size == 0;
}

int sizeList (List l) {
	if (!l) {
		return -1;
	}
	return l->size;
}

Item getItem (List l, int pos) {
	if (!l) {
		return NULL;
	}
	if (pos < 0 || pos >= l->size) {
		return NULL;
	}
	struct node* tmp = l->first;
	int i;
	for (i = 0; i < pos; i++) {
		tmp = tmp->next;
	}
	return cloneItem(tmp->value);
}

int posItem (List l, Item val) {
	if (!l) {
		return -1;
	}
	if (!val) {
		return -1;
	}
	struct node* tmp = l->first;
	int i;
	for (i = 0; tmp != 0; i++) {
		if (equalsItem(tmp->value, val) == 1) {
			return i;
		}
		tmp = tmp->next;
	}
	return -1;
}

int insertList (List l, int pos, Item val) {
	if (!l) {
		return -1;
	}
	if (pos < 0 || pos > l->size) {
		return -1;
	}
	if (!val) {
		return -1;
	}
	struct node* tmp = insertNode(l->first, pos, val);
	if (!tmp) {
		return 0;
	}
	l->first = tmp;
	l->size++;
	return 1;
}

int removeList (List l, int pos) {
	if (!l) {
		return 0;
	}
	if (pos < 0 || pos >= l->size) {
		return 0;
	}
	l->first = removeNode(l->first, pos);
	// Se removeNode restituisse anche 0 verificheremo così il problema
	/*if (!l->first) {
		return 0;
	}*/
	l->size--;
	return 1;
}

int deleteList (List l) {
	if (!l) {
		return 0;
	}
	struct node* tmp = l->first;
	struct node* del;
	while (tmp != NULL) {
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	l->first = NULL;
	l->size = 0;
	return 1;
}

int destroyList (List* l) {
	if (*l) {
		deleteList(*l);
		free(*l);
		*l = NULL;
		return 1;
	}
	return 0;
}

int outputList (List l) {
	if (!l) {
		return 0;
	}
	int i;
	struct node* tmp = l->first;
	for (i = 0; tmp; i++) {
		printf("[%2d] ", i);
		outputItem(tmp->value);
		printf("\n");
		tmp = tmp->next;
	}
	printf("\n");
	return 1;
}

List reverseList1 (List l) {
	if (!l) {
		return NULL;
	}
	List res = newList();
	struct node* tmp = l->first;

	while (tmp) {
		res->first = makeNode(tmp->value, res->first);
		/*
		 * Attenzione: makeNode potrebbe restituire NULL.
		 * Per semplicità non controlliamo questo caso.
		 */
		tmp = tmp->next;
	}

	if (res->first) {
		res->size = l->size;
	}
	return res;
}

int reverseList2 (List l) {
	if (!l) {
		return 0;
	}
	struct node* n = l->first;
	struct node* prec = NULL;
	struct node* succ = NULL;
	while (n) {
		succ = n->next;
		n->next = prec;
		prec = n;
		n = succ;
	}
	l->first = prec;
	return 1;
}

List cloneList (List l) {
	if (!l) {
		return NULL;
	}
	if (emptyList(l)) {
		return newList();
	}

	struct node* tmp = l->first;
	List res = newList();
	res->first = makeNode(tmp->value, NULL);

	struct node* tmp1 = res->first;

	while (tmp->next) {
		tmp1->next = makeNode(tmp->next->value, NULL);
		/*
		 * Attenzione: makeNode potrebbe restituire NULL.
		 * Per semplicità non controlliamo questo caso.
		 */
		tmp = tmp->next;
		tmp1 = tmp1->next;
	}
	res->size = l->size;
	return res;
}

List inputList (int n) {
	if (n <= 0) {
		return newList();
	}

	Item val;
	List res = newList();

	printf("Elemento di posizione 0: ");
	inputItem(&val);
	res->first = makeNode(val, NULL);

	struct node* tmp = res->first;

	int i;
	for (i = 1; i < n - 1; i++) {
		printf("Elemento in posizione %d: ", i);
		inputItem(&val);
		tmp->next = makeNode(val, NULL);
		/*
		 * Attenzione: makeNode potrebbe restituire NULL.
		 * Per semplicità non controlliamo questo caso.
		 */
		tmp = tmp->next;
	}
	res->size = n;
	return res;
}

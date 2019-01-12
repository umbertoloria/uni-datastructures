#include "item.h"

typedef struct LinkedQueue* LinkedQueue;

/**
 * Crea una nuova coda vuota.
 *
 * Post: q = queue().
 *
 * Restituisce: Una nuova coda vuota.
 *              NULL se non è stato possibile allocare memoria.
 */
LinkedQueue newLinkedQueue ();

/**
 * Questa coda è vuota?
 *
 * Pre: La coda non deve essere un puntatore vuoto.
 *
 * Post: Se (l->size == 0) e=1 altrimenti e=0.
 *
 * Restituisce: 1 se la coda non contiene nessun elemento.
 *              0 se la coda contiene almeno un elemento.
 *              -1 se è stata violata la precondizione.
 */
int emptyQueue (LinkedQueue);

/**
 * Accoda a questa coda questo item.
 *
 * Pre: La coda non deve essere un puntatore vuoto.
 * Pre: L'item non deve essere un puntatore vuoto.
 *
 * Post: q = <a1, a2, a3, ..., an> AND q1 = <e, a1, a2, a3, ..., an>.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se non è stato possibile allocare memoria.
 *              -1 se sono state violate le precondizioni.
 */
int enqueue (LinkedQueue, item);

/**
 * Dammi il prossimo elemento della coda.
 *
 * Pre: La coda non deve essere un puntatore vuoto.
 * Pre: La coda non deve essere vuota.
 *
 * Post: q=<a1, a2, a3, ..., an-1, an> AND q1=<a1, a2, a3, ..., an-1>.
 *
 * Restituisce: L'elemento in testa alla coda.
 *              NULL se sono state violate le precondizioni.
 */
item dequeue (LinkedQueue);
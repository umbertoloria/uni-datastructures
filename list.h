#include "item.h"

typedef struct list* list;

/**
 * Crea una nuova lista vuota.
 *
 * Post: l = list().
 *
 * Restituisce: Una nuova lista vuota.
 *              NULL se non è stato possibile allocare memoria.
 */
list newList ();

/**
 * E' vero che questa lista è vuota?
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 *
 * Post: Se (l->size == 0) e=1 altrimenti e=0
 *
 * Restituisce: 1 se la lista non contiene nessun elemento.
 *              0 se la lista contiene almeno un elemento.
 *              -1 se è stata violata la precondizione.
 */
int emptyList (list);

/**
 * Quanti elementi contiene questa lista?
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 *
 * Post: s = l->size.
 *
 * Restituisce: La quantità di elementi nella lista.
 *              -1 se è stata violata la precondizione.
 */
int sizeList (list);

/**
 * Dammi l'elemento di questa lista in questa posizione.
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 * Pre: La posizione deve essere minore o uguale alla lunghezza della lista.
 *
 * Post: g = elemento che occupa la posizione pos.
 *
 * Restituisce: L'elemento nella posizione fornita.
 *              NULL se sono state violate le precondizioni.
 */
item getItem (list, int);

/**
 * Qual è la posizione del primo elemento in cui è presente questo valore?
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 * Pre: La lista deve contenere l'elemento fornito.
 * Pre: L'item non deve essere un puntatore vuoto.
 *
 * Post: Se item è contenuto allora restituisce la prima occorrenza
 *       dell'elemento. Altrimenti -1.
 *
 * Restituisce: -1 se l'elemento cercato non è presente nella lista o se sono
 *              state violate le precondizioni.
 *              La posizione dell'elemento se è presente nella lista.
 */
int posItem (list, item);

/**
 * Inserisci in questa lista e in questa posizione questo elemento.
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 * Pre: La posizione deve essere minore o uguale alla lunghezza della lista.
 * Pre: L'item non deve essere un puntatore vuoto.
 *
 * Post: l1 si ottiene da l inserendo i in posizione pos.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se non è stato possibile allocare memoria.
 *              -1 se sono state violate le precondizioni.
 */
int insertList (list, int, item);

/**
 * Rimuovi l'elemento di questa lista che si trova in questa posizione.
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 * Pre: La lista deve contenere almeno un elemento.
 * Pre: La variabile "pos" deve essere la posizione di un elemento esistente
 *      nella lista.
 *
 * Post: l1 si ottiene da l eliminando l'elemento in posizione pos.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se sono state violate le precondizioni.
 */
int removeList (list, int);

/**
 * Svuota questa la lista.
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 *
 * Post: l = <a1, a2, a3, ..., an> AND l1 = <>.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se sono state violate le precondizioni.
 */
int deleteList (list);

/**
 * Svuota questa lista e distruggila.
 *
 * Pre: La lista puntata non deve essere un puntatore vuoto.
 *
 * Post: l = <a1, a2, a3, ..., an> AND l1 = NULL.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se è stata violata la precondizione.
 */
int destroyList (list*);

/**
 * Stampa a video il contenuto di questa lista tramite testo formattato.
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 *
 * Post: La lista rimane invariata.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se è stata violata la precondizione.
 */
int outputList (list);

/**
 * Dammi una copia invertita di questa lista.
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 *
 * Post: l = <a1, a2, a3, ..., an> AND l1 = <an, ..., a3, a2, a1>.
 *
 * Restituisce: Una lista invertita della lista fornita.
 *              NULL se sono state violate le precondizioni.
 */
list reverseList1 (list);

/**
 * Inverti questa lista.
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 *
 * Post: l = <a1, a2, a3, ..., an> AND r = <an, ..., a3, a2, a1>.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se è stata violata la precondizione.
 */
int reverseList2 (list);

/**
 * Dammi la copia di questa lista.
 *
 * Pre: La lista non deve essere un puntatore vuoto.
 *
 * Post: l = <a1, a2, a3, ..., an> AND c = <a1, a2, a3, ..., an>.
 *
 * Restituisce: Una lista nuova con lo stesso contenuto della lista fornita.
 *              NULL se non è stato possibile allocare memoria.
 */
list cloneList (list);

/**
 * Prendi in input questa quantità di elementi e restituisci una lista che li
 * contiene.
 *
 * Pre: La quantità deve essere maggiore di 0.
 *
 * Post: La lista viene presa in input di n numeri.
 *
 * Restituisce: Una lista che contiene tanti item presi in input dall'utente in
 *              base a quanti sono richiesti nel numero fornito.
 *              NULL se l'utente ha inserito dati sbagliti o se non è stato
 *              possibile allocare memoria.
 */
list inputList (int);

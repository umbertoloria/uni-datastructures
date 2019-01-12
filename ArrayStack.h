#include "item.h"

typedef struct ArrayStack* ArrayStack;

/**
 * Crea un nuovo stack.
 *
 * Post: stack().
 *
 * Restituisce: Un nuovo stack vuoto.
 *              NULL se non è stato possibile allocare memoria.
 */
ArrayStack newArrayStack ();


/**
 * E' vero che questo stack è vuota?
 *
 * Pre: Lo stack non deve essere un puntatore vuoto.
 *
 * Post: Se (l->top == 0) e=1 altrimenti e=0.
 *
 * Restituisce: 1 se lo stack non contiene nessun elemento.
 *              0 se lo stack contiene almeno un elemento.
 *              -1 se è violata la precondizione.
 */
int emptyStack (ArrayStack);

/**
 * Inserisci in cima a questo stack questo elemento.
 *
 * Pre: Lo stack non deve essere un puntatore vuoto.
 * Pre: L'item non deve essere un puntatore vuoto.
 *
 * Post: s1 si ottiene da s inserendo i in cima.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se non è stato possibile allocare memoria.
 *              -1 se sono state violate le precondizioni.
 */
int push (ArrayStack, item);

/**
 * Rimuovi l'elemento in cima a questo stack.
 *
 * Pre: Lo stack non deve essere un puntatore vuoto.
 * Pre: Lo stack deve contenere almeno un elemento.
 *
 * Post: s=stack(a1, a2, a3, ..., an) AND s1=stack(a2, a3, ..., an).
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se sono state violate le precondizioni.
 */
int pop (ArrayStack);

/**
 * Dammi l'elemento in cima a questo stack.
 *
 * Pre: Lo stack non deve essere un puntatore vuoto.
 * Pre: Lo stack deve contenere almeno un elemento.
 *
 * Post: s=stack(a1, a2, a3, ..., an) AND t=a1.
 *
 * Restituisce: L'item in cima allo stack.
 *              NULL se sono state violate le precondizioni.
 */
item top (ArrayStack);

/**
 * Stampa a video il contenuto di questo stack tramite testo formattato.
 *
 * Pre: Lo stack non deve essere un puntatore vuoto.
 *
 * Post: Lo stack rimane invariato.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se è stata violata la precondizione.
 */
int outputStack (ArrayStack);
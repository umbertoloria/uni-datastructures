typedef struct item* item;

/**
 * Crea un nuovo item.
 *
 * Post: item(val).
 *
 * Restituisce: Un nuovo item con il contenuto fornito.
 *              NULL se non è stato possibile allocare memoria.
 */
item newItem (int);

/**
 * Stampa a video il contenuto di questo item.
 *
 * Pre: L'item non deve essere un puntatore vuoto.
 *
 * Post: L'item rimane invariato.
 *
 * Restituisce: Manda in output il contenuto dell'item fornito e restituisce 1.
 *              Se è stata violata la precondizione manda in output "NULL" e
 *              restituisce 0.
 */
int outputItem (item);

/**
 * Crea un nuovo item e prendi in input il suo nuovo valore.
 *
 * Post: i=item(dati presi in input).
 *
 * Restituisce: 1 se l'elaborazione è stata eseguita.
 *              0 se non è stato possibile allocare memoria.
 */
int inputItem (item*);

/**
 * Dimmi se questi due item sono uguali.
 *
 * Pre: Gli item non devono essere puntatori vuoti.
 *
 * Post: Se (a == b) allora e=1 altrimenti e=0.
 *
 * Restituisce: 1 se gli item hanno lo stesso contenuto.
 *              0 se gli item hanno contenuti diversi.
 *              -1 se sono state violate le precondizioni.
 */
int eq (item, item);

/**
 * Dimmi se questi due item sono uguali.
 *
 * Pre: L'item non deve essere un puntatore vuoto.
 *
 * Post: item(n) AND g=n.
 *
 * Restituisce: Il contenuto dell'item.
 *              -1 se è stata violata la precondizione.
 * N.B.: Se il contenuto dell'item fosse -1, per capire che la precondizione
 *       non è stata violata e quindi il contenuto restituito è quello
 *       effettivo, accertarsi che l'item passato alla funzione non sia NULL.
 *
 */
int getInt (item);

/**
 * Distruggi questo item.
 *
 * Pre: L'item non deve essere un puntatore vuoto.
 *
 * Post: i = item(...) AND i1 = NULL.
 *
 * Restituisce: 1 se è stato possibile concludere l'elaborazione.
 *              0 se è stata violata le precondizione.
 */
int destroyItem (item*);

/**
 * Dammi la copia di questo item.
 *
 * Pre: L'item non deve essere un puntatore vuoto.
 *
 * Post: i = item(...) AND i1 = item(...).
 *
 * Restituisce: Un item nuovo con lo stesso contenuto dell'item fornito.
 *              NULL se non è stato possibile allocare memoria.
 */
item cloneItem (item);
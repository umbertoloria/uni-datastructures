/**

 ADT LQueue

 SPECIFICA SINTATTICA

 Tipi usati: Item, bool, int.

 Operatori:
 	newQueue()						➤ LQueue
 	emptyQueue(LQueue)				➤ bool
 	enqueue(LQueue, Item)			➤ LQueue
 	dequeue(LQueue)					➤ (Item, LQueue)
 	outputQueue(LQueue)				➤ int

 SPECIFICA SEMANTICA

 newQueue() ➔ q
 	Post: q = Ø

 emptyQueue(l) ➔ e
	Post: Se (l = Ø) allora e = 1, altrimenti e = 0

 enqueue(q, e) ➔ q'
	Post: q' = e ∪ q (in prima posizione)

 dequeue(q) ➔ (qn, q')
 	Pre: |q| > 0
 	Post: q' = q - {primo elemento}

 outputQueue(q)
	Post: Output di q

 */

#include "Item.h"

typedef struct LQueue* LQueue;

LQueue newQueue ();

int emptyQueue (LQueue);

int enqueue (LQueue, Item);

Item dequeue (LQueue);

int outputQueue (LQueue);
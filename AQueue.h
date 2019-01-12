/**

 ADT AQueue

 SPECIFICA SINTATTICA

 Tipi usati: Item, bool, int.

 Operatori:
 	newQueue()						➤ AQueue
 	emptyQueue(AQueue)				➤ bool
 	enqueue(AQueue, Item)			➤ AQueue
 	dequeue(AQueue)					➤ (Item, AQueue)
 	outputQueue(AQueue)				➤ int

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

typedef struct AQueue* AQueue;

AQueue newQueue (int);

int emptyQueue (AQueue);

int enqueue (AQueue, Item);

Item dequeue (AQueue);

int outputQueue (AQueue);
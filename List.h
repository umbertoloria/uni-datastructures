/**

 ADT List

 SPECIFICA SINTATTICA

 Tipi usati: Item, bool, int.

 Operatori:
 	newList()						➤ List
 	emptyList(List)					➤ bool
 	sizeList(List)					➤ int
 	getItem(List, int)				➤ Item
 	posItem(List, Item)				➤ int
 	insertList(List, int, Item)		➤ List
 	removeList(List, int)			➤ List
 	deleteList(List)				➤ List
 	destroyList(List)				➤ null
 	outputList(List)				➤ int
 	reverseList(List)				➤ List
 	cloneList(List)					➤ List
 	inputList(int)					➤ List

 SPECIFICA SEMANTICA

 newList() ➔ l
 	Post: l = Ø

 emptyList(l) ➔ e
	Post: Se (l = Ø) allora e = 1, altrimenti e = 0

 sizeList(l) ➔ s
	Post: s = |l|

 getItem(l, pos) ➔ i
 	Pre: pos >= 0 AND |l| > pos
 	Post: i = l[pos]

 posItem(l, e) ➔ l'
 	Post: Se (e ∈ l) allora p = (prima occorrenza di e), altrimenti p = -1

 insertList(l, pos, e) ➔ l'
 	Pre: |l| >= pos
 	Post: l' = l ∪ e (in posizione pos)

 removeList(l, pos) ➔ l'
 	Pre: |s| > pos
 	Post: l' = l - {elemento in posizione pos}

 deleteList(l) ➔ l'
 	Post: l' = Ø

 destroyList(l)
 	Post: l' scompare

 outputList(s)
	Post: Output di s

 reverseList(l) ➔ l'
 	Post: l' = l con elementi disposti nell'ordine inverso

 cloneList(l) ➔ c
 	Post: c = l (in una differente locazione di memoria)

 inputList(n) ➔ l
	Post: l = contiene n elementi presi in input

 */

#include "Item.h"

typedef struct List* List;

List newList ();

int emptyList (List);

int sizeList (List);

Item getItem (List, int);

int posItem (List, Item);

int insertList (List, int, Item);

int removeList (List, int);

int deleteList (List);

int destroyList (List*);

int outputList (List);

List reverseList1 (List);

int reverseList2 (List);

List cloneList (List);

List inputList (int);

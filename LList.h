/**

 ADT LList

 SPECIFICA SINTATTICA

 Tipi usati: Item, bool, int.

 Operatori:
 	newList()						➤ LList
 	emptyList(LList)				➤ bool
 	sizeList(LList)					➤ int
 	getItem(LList, int)				➤ Item
 	posItem(LList, Item)			➤ int
 	insertList(LList, int, Item)	➤ LList
 	removeList(LList, int)			➤ LList
 	deleteList(LList)				➤ LList
 	destroyList(LList)				➤ null
 	outputList(LList)				➤ int
 	reverseList(LList)				➤ LList
 	cloneList(LList)				➤ LList
 	inputList(int)					➤ LList

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

typedef struct LList* LList;

LList newList ();

int emptyList (LList);

int sizeList (LList);

Item getItem (LList, int);

int posItem (LList, Item);

int insertList (LList, int, Item);

int removeList (LList, int);

int deleteList (LList);

int destroyList (LList*);

int outputList (LList);

LList reverseList1 (LList);

int reverseList2 (LList);

LList cloneList (LList);

LList inputList (int);

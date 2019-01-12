/**

 ADT Item

 SPECIFICA SINTATTICA

 Tipi usati: Item, bool, int.

 Operatori:
 	newItem(int)					➤ Item
 	equalsItem(Item, Item)			➤ bool
 	cmpItem(Item, Item)				➤ int
 	outputItem(Item)				➤ bool
 	inputItem(Item)					➤ bool
 	cloneItem(Item)					➤ Item
 	destroyItem(Item)				➤ void

 SPECIFICA SEMANTICA

 newItem(v) ➔ i
 	Post: i = <v>

 equalsItem(i1, i2) ➔ e
 	Pre: i1 ≠ Ø AND i2 ≠ Ø
 	Post: Se (i1 = i2) allora e = 1, altrimenti e = 0

 cmpItem(i1, i2) ➔ e
 	Pre: i1 ≠ Ø AND i2 ≠ Ø
 	Post: e = i1 - i2

 cmpItem(i ➔ k
 	Pre: i ≠ Ø
 	Post: k = chiave di i

 outputItem(i)
	Post: Output di i

 inputItem(i) ➔ e
	Post: i = contiene qualcosa presa in input

 cloneItem(i) ➔ c
	Post: c = i (in una differente locazione di memoria)

 destroyItem(i)
	Post: i scompare

 */

typedef struct Item* Item;

Item newItem (int);

int equalsItem (Item, Item);

int cmpItem (Item, Item);

int outputItem (Item);

int inputItem (Item*);

Item cloneItem (Item);

int destroyItem (Item*);
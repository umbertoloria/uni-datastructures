/**

 ADT Item

 SPECIFICA SINTATTICA

 Tipi usati: Item, bool, int.

 Operatori:
 	newItem(int)					➤ Item
 	outputItem(Item)				➤ int
 	inputItem(Item)					➤ int
 	eq(Item, Item)					➤ bool
 	getInt(Item)					➤ int
 	destroyItem(Item)				➤ null
 	cloneItem(Item)					➤ Item

 SPECIFICA SEMANTICA

 newItem(v) ➔ i
 	Post: i = <v>

 outputItem(i)
	Post: Output di i

 inputItem(i) ➔ e
	Post: i = contiene qualcosa presa in input

 eq(i1, i2) ➔ e
 	Post: Se (i1 = i2) allora e = 1, altrimenti e = 0

 cmpItem(i1, i2) ➔ e
 	Post: Se (i1 < i2) allora e = -1, se (i1 = i2) allora e = 0, altrimenti e = 1

 getInt(i) ➔ g
	Post: g = valore di i

 destroyItem(i)
	Post: i scompare

 cloneItem(i) ➔ c
	Post: c = i (in una differente locazione di memoria)

 */

typedef struct Item* Item;

Item newItem (int);

int outputItem (Item);

int inputItem (Item*);

int eq (Item, Item);

int cmpItem (Item, Item);

/*
 * N.B.: Se il contenuto dell'item fosse -1, per capire che la precondizione
 *       non è stata violata e quindi il contenuto restituito è quello
 *       effettivo, accertarsi che l'item passato alla funzione non sia NULL.
 *
 */
int getInt (Item);

int destroyItem (Item*);

Item cloneItem (Item);
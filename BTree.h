/**

 ADT BTree

 SPECIFICA SINTATTICA

 Tipi usati: bool, Item.

 Operatori:
 	newBTree()						➤ BTree
 	emptyBTree(BTree)				➤ bool
 	getRoot(BTree)					➤ Item
 	leftBTree(BTree)				➤ BTree
 	rightBTree(BTree)				➤ BTree
 	consBTree(Item, BTree, BTree)	➤ BTree

 SPECIFICA SEMANTICA

 newBTree() ➔ t
 	Post: t = Ø

 emptyBTree(t) ➔ e
	Post: Se (t = Ø) allora e = 1, altrimenti e = 0

 getRoot(t) ➔ r
 	Pre: t ≠ Ø
	Post: t = (r, tsx, tdx)

 leftBTree(t) ➔ tsx
 	Pre: t ≠ Ø
	Post: t = (r, tsx, tdx)

 rightBTree(t) ➔ tdx
 	Pre: t ≠ Ø
	Post: t = (r, tsx, tdx)

 consBTree(r, tsx, tdx) ➔ t
	Post: t = (r, tsx, tdx)

 */

#include "Item.h"

typedef struct node* BTree;

BTree newBTree ();

int emptyBTree (BTree);

BTree consBTree (Item, BTree, BTree);

Item getRoot (BTree);

BTree leftBTree (BTree);

BTree rightBTree (BTree);

void preOrder (BTree);

void postOrder (BTree);

void inOrder (BTree);
/**

 ADT BSTree

 SPECIFICA SINTATTICA

 Tipi usati: bool, Item.

 Operatori:
 	newBSTree()						➤ BSTree
 	emptyBTree(BSTree)				➤ bool
 	cardinality(BSTree)				➤ Item
 	contains(BSTree, Item)			➤ bool
 	insertBSTree(BSTree, Item)		➤ bool
 	removeBSTree(BSTree, Item)		➤ bool
 	outputBSTree(BSTree)			➤ void

 SPECIFICA SEMANTICA

 newBSTree() ➔ t
 	Post: t = Ø

 emptyBSTree(t) ➔ e
	Post: Se (t = Ø) allora e = 1, altrimenti e = 0

 cardinality(t) ➔ c
 	Pre: t ≠ Ø
	Post: c = |t|

 insertBSTree(t, i) ➔ t'
 	Pre: t ≠ Ø
	Post: t = <a1, a2, a3, ..., an> AND t' = <a1, a2, i, a3, ..., an>

 removeBSTree(t, i) ➔ t'
 	Pre: t ≠ Ø
	Post: t = <a1, a2, i, a3, ..., an> AND t' = <a1, a2, a3, ..., an>

 outputBSTree(t)
 	Pre: t ≠ Ø
	Post: Output di t

 */

#include "Item.h"

typedef struct BSTree* BSTree;

BSTree newBSTree ();

int emptyBSTree (BSTree);

int cardinality (BSTree);

int contains (BSTree, Item);

int insertBSTree (BSTree, Item);

int removeBSTree (BSTree, Item);

int outputBSTree (BSTree);
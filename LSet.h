/**

 ADT LSet

 SPECIFICA SINTATTICA

 Tipi usati: Item, bool, int.

 Operatori:
 	newSet()					➤ LSet
 	emptySet(Set)				➤ bool
 	cardinality(Set)			➤ int
 	contains(Set, Item)			➤ bool
 	insertSet(Set, Item)		➤ LSet
 	removeSet(Set, Item)		➤ LSet
 	unionSet(Set, Set)			➤ LSet
 	intersectSet(Set, Set)		➤ LSet
 	subSet(Set, Set)			➤ LSet
 	outputSet(Set, Set)			➤ int

 SPECIFICA SEMANTICA

 newSet() ➔ s
 	Post: s = Ø

 emptySet(s) ➔ e
	Post: Se (s = Ø) allora e = 1, altrimenti e = 0

 cardinality(s) ➔ c
	Post: c = |s|

 contains(s, i) ➔ c
	Post: Se (i ∈ s) allora c = 1, altrimenti c = 0

 insertSet(s, i) ➔ s'
	Pre: s ≠ Ø
	Pre: i ∉ s
	Post: s' = s ∪ i

 removeSet(s, i) ➔ s'
	Pre: s ≠ Ø
	Pre: i ∈ s
	Post: s' = s - i

 unionSet(s1, s2) ➔ s'
	Post: s' = s1 ∪ s2

 intersectSet(s1, s2) ➔ s'
	Post: s' = s1 ∩ s2

 subSet(s1, s2) ➔ s'
	Post: s' = s1 - s2

 outputSet(s)
	Post: Output di s

 */

#include "Item.h"

typedef struct LSet* LSet;

LSet newSet ();

int emptySet (LSet);

int cardinality (LSet);

int contains (LSet, Item);

int insertSet (LSet, Item);

int removeSet (LSet, Item);

int unionSet (LSet, LSet);

int intersectSet (LSet, LSet);

int subSet (LSet, LSet);

int outputSet (LSet);
/**

 ADT OpenHash

 SPECIFICA SINTATTICA

 Tipi usati: bool, Item, Key.

 Operatori:
 	newOpenHash()					➤ OpenHash
 	hashInsert(OpenHash, Item)		➤ bool
 	hashSearch(OpenHash, Key)		➤ Item
 	hashDelete(OpenHash, Key)		➤ bool

 SPECIFICA SEMANTICA

 newOpenHash() ➔ t
 	Post: t = {}

 hashInsert(t, e) ➔ t'
	Post: t = {a1, a2, ..., an} AND t' = {a1, a2, ..., e, ..., an}

 hashSearch(t, k) ➔ e
 	Pre: t = {a1, a2, .., an} AND n > 0
	Post: e = ai AND 1 <= i <= n se ai->key = k

 hashDelete(t, k) ➔ t'
 	Pre: t = {a1, a2, .., an} AND n > 0 AND ai->key = k con 1<= i <= n
	Post: t' = {a1, a2, ..., ai-1, ai+1, ..., an}

 */

#include "Item.h"

typedef struct hash* OpenHash;

OpenHash newOpenHash (int);

int hashInsert (OpenHash, char*, Item);

Item hashSearch (OpenHash, char*);

int hashDelete (OpenHash, char*);

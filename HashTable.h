/**

 ADT HashTable

 SPECIFICA SINTATTICA

 Tipi usati: bool, Item, Key.

 Operatori:
 	newHashTable()						➤ HashTable
 	insertHash(HashTable, Key, Item)	➤ bool
 	searchHash(HashTable, Key)			➤ Item
 	deleteHash(HashTable, Key)			➤ bool

 SPECIFICA SEMANTICA

 newHashTable() ➔ t
 	Post: t = {}

 insertHash(t, k, e) ➔ t'
	Post: t = {a1, a2, ..., an} AND t' = {a1, a2, ..., e, ..., an}

 searchHash(t, k) ➔ e
 	Pre: t = {a1, a2, .., an} AND n > 0
	Post: e = ai AND 1 <= i <= n se ai->key = k

 deleteHash(t, k) ➔ t'
 	Pre: t = {a1, a2, .., an} AND n > 0 AND ai->key = k con 1<= i <= n
	Post: t' = {a1, a2, ..., ai-1, ai+1, ..., an}

 */

#include "Item.h"

typedef struct hash* HashTable;

HashTable newHashTable (int);

int insertHash (HashTable, char*, Item);

Item searchHash (HashTable, char*);

int deleteHash (HashTable, char*);

void destroyHash (HashTable);

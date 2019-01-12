/**

 ADT AStack

 SPECIFICA SINTATTICA

 Tipi usati: Item, bool.

 Operatori:
 	newStack()					➤ AStack
 	emptyStack(AStack)			➤ bool
 	push(AStack, Item)			➤ AStack
 	pop(AStack)					➤ AStack
 	top(AStack)					➤ Item
 	outputStack(AStack)			➤ bool

 SPECIFICA SEMANTICA

 newStack() ➔ s
 	Post: s = Ø

 emptyStack(s) ➔ e
	Post: Se (s = Ø) allora e = 1, altrimenti e = 0

 push(s, i) ➔ s'
 	Post: s' = i ∪ s

 pop(s) ➔ s'
 	Pre: |s| > 0
 	Post: s' = s - {elemento in cima}

 top(s) ➔ e
 	Pre: |s| > 0
 	Post: e = {elemento in cima}

 outputStack(s)
	Post: Output di s

 */

#include "Item.h"

typedef struct AStack* AStack;

AStack newStack ();

int emptyStack (AStack);

int push (AStack, Item);

int pop (AStack);

Item top (AStack);

int outputStack (AStack);
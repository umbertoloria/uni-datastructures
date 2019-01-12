/**

 ADT LStack

 SPECIFICA SINTATTICA

 Tipi usati: Item, bool.

 Operatori:
 	newStack()					➤ LStack
 	emptyStack(LStack)			➤ bool
 	push(LStack, Item)			➤ LStack
 	pop(LStack)					➤ LStack
 	top(LStack)					➤ Item
 	outputStack(LStack)			➤ int

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

typedef struct LStack* LStack;

LStack newStack ();

int emptyStack (LStack);

int push (LStack, Item);

int pop (LStack);

Item top (LStack);

int outputStack (LStack);

cmake_minimum_required(VERSION 3.9)
project(uni_datastructures C)

set(CMAKE_C_STANDARD 99)

set(QUEUE_SOURCE AQueue.c)
set(STACK_SOURCE AStack.c)
set(SET_SOURCE LSet.c)
set(BTREE_SOURCE BTRee.c)
set(BSTREE_SOURCE BSTree.c)
set(HASHTABLE HashTable.c)
set(OPENHASH OpenHash.c)

add_executable(uni_datastructures Item.c List.c
        ${QUEUE_SOURCE} ${STACK_SOURCE}
        ${BTREE_SOURCE} ${BSTREE_SOURCE}
        ${HASHTABLE} ${OPENHASH})

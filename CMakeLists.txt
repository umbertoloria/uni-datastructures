cmake_minimum_required(VERSION 3.13)
project(uni_datastructures C)

set(CMAKE_C_STANDARD 99)

set(QUEUE_SOURCE LinkedQueue.c)
set(STACK_SOURCE LinkedStack.c)

add_executable(uni_datastructures ${QUEUE_SOURCE} ${STACK_SOURCE} item.c list.c main.c)

#pragma once
#include <stdio.h>
#include <stdlib.h>

struct ElementS {
	int data;
	ElementS* next;
};

struct Stack {
	ElementS* head = NULL;
};

void push(Stack& q, int d); int pull(Stack& q); void printQueue(const Stack& q);
void reverseNumber(const Stack& q); void evenOdd(const Stack& q, int lenght); void clear(Stack& q, int& lenght);
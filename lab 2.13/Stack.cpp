#include "Stack.h"

void push(Stack& q, int d) {
	ElementS* e = (ElementS*)malloc(sizeof(ElementS));
	e->data = d;
	e->next = q.head;
	q.head = e;
}

int pull(Stack& q) {
	if (q.head == NULL) return 0;

	int d = q.head->data;
	ElementS* e = q.head;
	q.head = q.head->next;
	free(e);

	return d;
}

void printQueue(const Stack& q) {
	for (ElementS* cur = q.head; cur != NULL; cur = cur->next) {
		printf("%d -> ", cur->data);
	}
	printf("\b\b\b   \n");
}
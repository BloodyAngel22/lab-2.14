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

void reverseNumber(const Stack& q) {
	if (q.head == NULL) return;
	int tmp = 0;
	ElementS* cur = q.head;
	int reverseNumber;
	for (int i = 0; cur != NULL; i++, cur = cur->next) {
		tmp = (tmp + cur->data) * 10;
		if (cur->next == NULL) tmp /= 10;
	}
	reverseNumber = (tmp % 10) * 10;
	tmp /= 10;
	for (cur = q.head;cur->next != NULL; cur =cur->next) {
		reverseNumber = (reverseNumber + tmp % 10) * 10;
		tmp /= 10;
	}
	reverseNumber /= 10;
	printf("Вывод: ");
	printf("Число в обратном порядке: %d\n", reverseNumber);
}

void evenOdd(const Stack& q, int lenght) {
	if (q.head == NULL) return;
	int array[100];
	ElementS* cur = q.head;
	for (int i = 0; cur != NULL; cur = cur->next, i++)
		array[i] = cur->data;

	for (int i = 0; i < lenght - 2; i++) {
		int tmp = array[i];
		array[i] = array[i + 2];
		array[i + 2] = tmp;
	}
	printf("Вывод: ");
	for (int i = 0; i < lenght; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
}

void clear(Stack& q, int& lenght) {
	if (q.head == NULL) return;
	for (ElementS* cur = q.head; cur != NULL; cur = cur->next)
		q.head = q.head->next;
	lenght = 0;
}
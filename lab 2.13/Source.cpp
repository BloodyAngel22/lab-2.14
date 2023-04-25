#include "Stack.h"

void reverseNumber(const Stack& q); void evenOdd(const Stack& q, int lenght); void clear(Stack& q);

void loopStack(int& lenght) {
	Stack q;
	int choice;
	while (true) {
		printf("Выбор: 1 - Добавить новый элемент; 2 - Удалить элемент; 3 - Вывод числа в обратном порядке; 4 - Четное/нечетное; 5 - очистка; 6 - Выход\n");
		int tmp;
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			int number;
			printf("Введите число\n"); scanf_s("%d", &number);
			while (number != 0) {
				tmp = number % 10;
				number /= 10;
				lenght++;
				push(q, tmp);
			}
			break;
		case 2:
			tmp = pull(q);
			if (lenght > 0)
				lenght--;
			printf("Удаление элемента %d\n", tmp);
			break;
		case 3:
			printf("Вывод: ");
			reverseNumber(q);
			break;
		case 4:
			printf("Вывод: ");
			evenOdd(q, lenght);
			break;
		case 5:
			clear(q);
			printf("Очистка прошла успешно\n");
			break;
		case 6:
			return;
		}

		printQueue(q);
	}
}

void reverseNumber(const Stack& q) {
	if (q.head == NULL) return;
	int tmp = 0;
	ElementS* cur = q.head;
	int lenghtStack = 0;
	int reverseNumber;
	for (int i = 0; cur != NULL; i++, cur = cur->next) {
		tmp = (tmp + cur->data) * 10;
		lenghtStack++;
		if (cur->next == NULL) tmp /= 10;
	}
	if (lenghtStack == 1) {
		reverseNumber = tmp % 10;
		printf("Число в обратном порядке: %d\n", reverseNumber); return;
	}
	reverseNumber = (tmp % 10) * 10;
	tmp /= 10;
	for (int i = 1; i < lenghtStack; i++) {
		reverseNumber = (reverseNumber + tmp % 10) * 10;
		tmp /= 10;
		if (i == lenghtStack - 1) reverseNumber /= 10;
	}

	printf("Число в обратном порядке: %d\n", reverseNumber);
}

void evenOdd(const Stack& q, int lenght) {
	if (lenght <= 2) return;
	int array[100];
	ElementS* cur = q.head;
	for (int i = 0; cur != NULL; cur = cur->next, i++)
		array[i] = cur->data;

	for (int i = 0; i < lenght; i++) {
		for (int j = 1; j < lenght - 1; j++) {
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}

	for (int i = 0; i < lenght; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
}

void clear(Stack& q) {
	if (q.head == NULL) return;
	for (ElementS* cur = q.head; cur != NULL; cur = cur->next)
		q.head = q.head->next;
}

int main() {
	system("chcp 1251");
	int lenght = 0;
	loopStack(lenght);
	return 0;
}

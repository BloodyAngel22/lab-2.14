#include "Stack.h"

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
			reverseNumber(q);
			break;
		case 4:
			evenOdd(q, lenght);
			break;
		case 5:
			clear(q, lenght);
			printf("Очистка прошла успешно\n");
			break;
		case 6:
			return;
		}

		printQueue(q);
	}
}

int main() {
	system("chcp 1251");
	int lenght = 0;
	loopStack(lenght);
	return 0;
}

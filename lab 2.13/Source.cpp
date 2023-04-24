#include "Stack.h"

void entryNumber(int* array, int& lenght, int& lenghtStack); void reverseNumber(const Stack& q, int lenghtStack);

void loopStack(int lenght, int lenghtStack) {
	Stack q;
	int choice;
	while (true) {
		int* array = (int*)malloc(sizeof(int));
		printf("Выбор: 1 - Добавить новый элемент; 2 - Удалить элемент; 3 - Вывод числа в обратном порядке; 4 - Выход\n");
		int tmp;
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			entryNumber(array, lenght, lenghtStack);
			for (int i = 0; i < lenght; i++) {
				push(q, array[i]);
			}
			break;
		case 2:
			tmp = pull(q);
			printf("Удаление элемента %d\n", tmp);
			break;
		case 3:
			reverseNumber(q, lenghtStack);
			break;
		case 4:
			free(array);
			return;
		}

		printQueue(q);
	}
}

void entryNumber(int* array, int &lenght, int& lenghtStack) {
	int storage;
	lenght = 0;
	while (lenght < 2) {
		lenght = 0;
		printf("Введите число "); scanf_s("%d", &storage);
		//Длина числа
		int tmp2 = storage;
		while (tmp2 != NULL) {
			tmp2 = tmp2 / 10;
			lenght++;
			lenghtStack++;
		}
		if (lenght == 1) {
			array[0] = storage;
			lenghtStack++;
			return;
		}
	}
	//Разложение числа
	int tmp;
	for (int i = 0; i < lenght; i++) {
		tmp = storage % 10;
		storage = storage / 10;
		array[i] = tmp;
	}
}

void reverseNumber(const Stack& q, int lenghtStack) {
	if (q.head == NULL) return;
	int* storageArray = (int*)malloc(sizeof(int));
	ElementS* cur = q.head;
	lenghtStack = 0;
	for (int i = 0; cur != NULL; i++, cur = cur->next) {
		storageArray[i] = cur->data;
		lenghtStack++;
	}

	int reverseNumber = storageArray[lenghtStack-1];
	for (int i = lenghtStack - 1; i > 0; i--) {
		reverseNumber = (reverseNumber * 10) + storageArray[i - 1];
	}
	printf("Число в обратном порядке: %d\n", reverseNumber);

	//free(storageArray);
}

int main() {
	system("chcp 1251");
	int lenght = 0;
	int lenghtStack = 0;
	loopStack(lenght, lenghtStack);
	return 0;
}


/*//563412
int main() {
	int array[6] = { 1,2,3,4,5,6 };

	for (int i = 0; i < 6; i++) {
		for (int j = 1; j < 6 - 1; j++) {
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	
	for (int i = 0; i < 6; i++) {
		printf("%d", array[i]);
	}
}*/
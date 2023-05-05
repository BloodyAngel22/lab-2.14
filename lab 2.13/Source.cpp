#include "Stack.h"

void loopStack(int& lenght) {
	Stack q;
	int choice;
	while (true) {
		printf("�����: 1 - �������� ����� �������; 2 - ������� �������; 3 - ����� ����� � �������� �������; 4 - ������/��������; 5 - �������; 6 - �����\n");
		int tmp;
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			int number;
			printf("������� �����\n"); scanf_s("%d", &number);
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
			printf("�������� �������� %d\n", tmp);
			break;
		case 3:
			reverseNumber(q);
			break;
		case 4:
			evenOdd(q, lenght);
			break;
		case 5:
			clear(q, lenght);
			printf("������� ������ �������\n");
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

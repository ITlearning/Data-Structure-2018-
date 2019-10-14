//���� �ҽ��ڵ��� ��ȣ ���� �˻��ϱ�

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef char element;		// ���� ���� (element)�� �ڷ����� int�� ����

element stack[STACK_SIZE];
int top = -1;

int isEmpty() {		// ������ ���� �������� Ȯ���ϴ� ����
	if (top == -1) return 1;
	else return 0;
}

int isFull() {		// ������ ��ȭ �������� Ȯ���ϴ� ����
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

void push(element item) {		// ������ top�� ���Ҹ� �����ϴ� ����
	if (isFull()) {				// ������ ��ȭ ������ ���
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;	// top�� ������Ų �� ���� top�� ���� ����
}


element pop() {			// ������ top���� ���Ҹ� �����ϴ� ����
	if (isEmpty()) {	// ������ ���� ������ ���
		printf("\n\n Stack is Empty!! \n");
		return 0;
	}
	else return stack[top--];	// ���� top�� ���Ҹ� ������ �� top ����
}

element peek() {			// ������ top ���Ҹ� �˻��ϴ� ����
	if (isEmpty()) {		// ������ ���� ������ ���
		printf("\n\n Stack is Empty ! \n");
		return 0;
	}
	else return stack[top];	// ���� top�� ���� Ȯ��
}

int testPair(char filename[]) {
	char symbol, open_pair;

	FILE *fp = fopen(filename, "r"); //r �б���
	if (fp == NULL)
		printf("Error: ���� �������� �ʽ��ϴ�. \n");

	top = -1;

	while ((symbol = fgetc(fp)) != EOF) {
		switch (symbol)	{
		case '(':
		case '[':
		case '{':
			push(symbol);break;
		case ')':
		case ']':
		case '}':
			if (top == -1) return 0;
			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '[' && symbol != ']') ||
					(open_pair == '{' && symbol != '}'))
					return 0;
				else break;
			}
		}
	}

	fclose(fp);
	if (top == -1) return 1;
	else return 0;
}

int main() {
	int ret;

	ret = testPair("Reverse.c");
	(ret == 1) ? printf("Reverse.c ��ȣ ����\n") : printf("Reverse.c ��ȣ ������\n");

	ret = testPair("FileTestPair.c");
	(ret == 1) ? printf("FileTestPair.c ��ȣ ����\n") : printf("FileTestPair.c ��ȣ ������\n");
}
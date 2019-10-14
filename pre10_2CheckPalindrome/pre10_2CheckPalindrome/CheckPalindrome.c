// ȸ�� �˻��ϱ� ex) IoI, AoA;

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

int checkPalindrome(char str[]) {
	int i = 0;
	int count = 0;

	while (str[i] != '\0') {
		push(str[i++]);
	}
	i = 0;
	while (!isEmpty()) {
		if (str[i++]!= pop()) {
			count++;
		}
			
	}

	if (count > 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	char str[100];
	int ret;

	while (1) {
		printf("���ڿ��� �Է��ϼ��� : ");
		scanf("%s", str);

		ret = checkPalindrome(str);

		if (ret == 1) {
			printf("ȸ���Դϴ�.\n\n");
		}
		else {
			printf("ȸ���� �ƴմϴ�.\n\n");
		}
	}
}
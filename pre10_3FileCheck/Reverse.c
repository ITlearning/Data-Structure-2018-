// ������ �̿��Ͽ� ����ڷκ��� �Է¹��� ���ڿ��� 
// �������� ����ϱ�

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

void reverse(char a[], char b[]) {
	int i = 0;

	while (a[i] != '\0') {
		push(a[i]);
		i++;
	}
	i = 0;
	while (!isEmpty()) {
		b[i] = pop();
		i++;
	}

	b[i] = '\0';
}

int main() {
	char str[100];
	char rev[100];

	while (1) {
		printf("���ڿ��� �Է��ϼ��� : ");
		scanf("%s", str);

		reverse(str, rev);

		printf("���� : %s		���� : %s\n\n", str, rev);
	}
}
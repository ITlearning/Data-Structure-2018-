#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define MAZE_SIZE 7

typedef struct {
	int row;
	int col;
} element;

element stack[STACK_SIZE];
int top = -1;

element here = { 1, 0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
		{'1', '1', '1', '1', '1', '1', '1'},
		{'0', '0', '1', '0', '0', '0', '0'},
		{'1', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '1', '0', '1'},
		{'0', '0', '1', '1', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '1', 'x'},
		{'1', '0', '1', '1', '0', '0', '0'},
};


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
		return ;
	}
	else return stack[top--];	// ���� top�� ���Ҹ� ������ �� top ����
}

element peek() {			// ������ top ���Ҹ� �˻��ϴ� ����
	if (isEmpty()) {		// ������ ���� ������ ���
		printf("\n\n Stack is Empty ! \n");
		return;
	}
	else return stack[top];	// ���� top�� ���� Ȯ��
}

void pushLocation(int row, int col) {
	if (row < 0 || row > MAZE_SIZE - 1 || col < 0 || col > MAZE_SIZE - 1) {
		return;
	}

	if (maze[row][col] != '1' || maze[row][col] != '.') {
		element temp;

		temp.row = row;
		temp.col = col;

		push(temp);
	}
}

void printMaze() {
	int i, j;

	system("cls");

	for (i = 0; i < MAZE_SIZE; i++) {
		for (j = 0; j < MAZE_SIZE; j++) {
			printf("%d ", maze[i][j]);
		}
	}
}

int main(void) {
	int r, c;

	maze[here.row][here.col] = 'e';
	printMaze();
	getchar();

	while (maze[here.row][here.col] != 'x') {
		r = here.row;
		c = here.col;
		maze[r][c] = 'm';

		printMaze();
		gerchar();

		maze[r][c] = '.';
		pushLocation(r - 1, c); //����
		pushLocation(r + 1, c); //�Ʒ���
		pushLocation(r, c - 1); //����
		pushLocation(r, c + 1); //������

		if (isEmpty()) {
			printf("����\n");
			return 0;
		}
		else {
			here = pop();
		}

		maze[here.row][here.col] = 'm';
		printMaze();
		printf("����\n");
	}
}


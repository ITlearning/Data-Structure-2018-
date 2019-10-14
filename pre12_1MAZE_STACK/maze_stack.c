/*
 * maze_stack.c
 *
 *  Created on: 2019. 6. 8.
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>

#define cQ_SIZE 10
#define MAZE_SIZE 7

typedef struct {
	int row;
	int col;
} element;

typedef struct {
	element queue[cQ_SIZE];
	int front, rear;
} QueueType;

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

QueueType *createQueue() {
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0; 		// front �ʱⰪ ����
	cQ->rear = 0;		// rear �ʱⰪ ����
	return cQ;
}

int isEmpty(QueueType *cQ) { 	//����ť ���� ���� Ȯ��
	if(cQ->front == cQ->rear) {
		printf("Circular Queue is empty! ");
		return 1;
	}
	else return 0;
}


int isFull(QueueType *cQ) {		//����ť ��ȭ ���� Ȯ��
	if(((cQ->rear + 1) % cQ_SIZE) == cQ->front) {	//cQ->rear�� +1 �ϰ� ������� ������ front�� �������� ��ȭ���� ����
		printf("Circular Queue is Full! ");
		return 1;
	}
	else return 0;
}

// ����ť�� ���� ����
void enQueue(QueueType *cQ, element item) {
	if(isFull(cQ)) return ;
	else {
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}


// ����ť�� ���� ����
element deQueue(QueueType *cQ) {
	if(isEmpty(cQ)) exit(1);
	else {
		cQ->front = (cQ->front + 1) %cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}


//���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
element peek(QueueType *cQ) {
	if(isEmpty(cQ)) exit(1);
	else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

void pushLocation(int row, int col, QueueType *cQ) {
	if((0 > row || row < MAZE_SIZE -1) || (0 > col || col < MAZE_SIZE - 1)) {
		return;
	}

	if((maze[row][col] != '1') && (maze[row][col] != '.')){
		element temp;
		temp.row = row;
		temp.col = col;
		enQueue(cQ, temp);
	}
}

void printMaze() {
	int i, j;

	system("cls");

	for(i = 0; i < MAZE_SIZE; i++) {
		for(j = 0; j < MAZE_SIZE; j++) {
			printf("%c ", maze[i][j]);

		}
		printf("\n");
	}
}

int main(void) {
	int r, c;
	QueueType *Q1 = createQueue();

	maze[here.row][here.col] = 'e';
	printMaze();
	fflush(stdout);
	getchar();

	while(maze[here.row][here.col] != 'x') {
		r = here.row;
		c = here.col;
		maze[r][c] = 'm';

		printMaze();
		getchar();

		maze[r][c] = '.';
		pushLocation(r - 1, c, Q1); //����
		pushLocation(r + 1, c, Q1);	//�Ʒ���
		pushLocation(r, c - 1, Q1);	//����
		pushLocation(r, c + 1, Q1); //������


		if(!isEmpty(Q1)) {
			printf("����\n");
			return 0;
		}
		else
			here = deQueue(Q1);
	}

	maze[here.row][here.col] = 'm';
	printMaze();
	printf("����\n");
}






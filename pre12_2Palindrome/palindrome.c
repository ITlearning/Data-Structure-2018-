/*
 * palindrome.c
 *
 *  Created on: 2019. 6. 8.
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>

typedef char element; 		//��ũ ����(element)�� �ڷ����� char�� ����
typedef struct DQNode {		//���� ���� ����Ʈ ��ũ�� ��� ������ ����ü�� ����
	element data;
	struct DQNode *llink;
	struct DQNode *rlink;
} DQNode;

typedef struct {		// ��ũ���� ����ϴ� ������ front�� rear�� ����ü�� ����
	DQNode *front, *rear;
} DQueType;



// ���� ��ũ�� �����ϴ� ����
DQueType *createDQue() {
	DQueType *DQ;
	DQ = (DQueType *)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}


// ��ũ�� rear �ڷ� ���Ҹ� �����ϴ� ����
void insertRear(DQueType *DQ, element item) {
	DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
	newNode->data = item;
	if(DQ->rear == NULL) {	// ��ũ�� ���� ������ ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;
		newNode->rlink = NULL;
		newNode->llink = DQ->rear;
		DQ->rear = newNode;
	}
}

int isEmpty(DQueType *DQ) {
	if(DQ->front == NULL)
		return 1;
	else
		return 0;
}

element deleteFront(DQueType *DQ) {
	DQNode *old = DQ->front;
	element item;
	if(isEmpty(DQ)) return 0;
	else {
		item = old->data;
		if(DQ->front->rlink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}
		free(old);
		return item;
	}
}

element deleteRear(DQueType *DQ) {
	DQNode *old = DQ-> rear;
	element item;
	if(isEmpty(DQ)) return 0;
	else {
		item = old->data;
		if(DQ->rear->llink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}

int checkPalindrome(DQueType *DQ, char str[]) {
	int i = 0;
	char a, b;
	while(str[i] != '\0') {
		insertRear(DQ, str[i++]);
	}

	while(!isEmpty(DQ)){
		a = deleteFront(DQ);
		b = deleteRear(DQ);
		if(a != b) {
			return 0;
		}else {
			if(!isEmpty(DQ)){
				while(!isEmpty(DQ)){
					deleteRear(DQ);
				}
				return 1;
			}
			return 1;
		}
	}
	return 1;
}

int main() {
	DQueType *DQ1 = createDQue(); // ��ũ ����
	char str[100];
	int ret;

	while (1) {
		printf("���ڿ��� �Է��ϼ���: ");
		fflush(stdout);
		scanf("%s", str);

		ret = checkPalindrome(DQ1, str);
		if(ret == 1)
			printf("ȸ���Դϴ�. \n");
		else {
			printf("ȸ���� �ƴմϴ�.\n");

			while(!isEmpty(DQ1)){
				char temp = deleteFront(DQ1);
			}
		}
	}
}










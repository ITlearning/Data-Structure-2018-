/*
 * Binary_Tree.c
 *
 *  Created on: 2019. 6. 8.
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {	// ���� �ڷᱸ���� �����ϱ� ���� Ʈ���� ��� ����
	int data;
	struct treeNode *left;	//���� ���� Ʈ���� ���� ��ũ �ʵ�
	struct treeNode *right;	//������ ���� Ʈ���� ���� ��ũ �ʵ�
} treeNode;

int sum = 0; 		// ��Ʈ�� ���� �����ϴ� ���� ����

// data�� ��Ʈ ���� �Ͽ� ���� ���� Ʈ���� ������ ���� Ʈ���� �����ϴ� ����
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void preorder_print(treeNode *root) {
	if(root) {
		printf("%d ", root->data);
		preorder_print(root->left);
		preorder_print(root->right);
	}
}

void inorder_sum(treeNode *root) {
	if(root) {
		inorder_sum(root->left);
		sum += root->data;
		inorder_sum(root->right);
	}
}

void postorder_print30(treeNode *root) {
	if(root) {
		postorder_print30(root->left);
		postorder_print30(root->right);
		if(root->data > 30) {
			printf("%d ", root->data);
		}
	}
}


int main() {
	treeNode *n8 = makeRootNode(33, NULL, NULL);
	treeNode *n9 = makeRootNode(76, NULL, NULL);
	treeNode *n4 = makeRootNode(8, n8, n9);
	treeNode *n5 = makeRootNode(14, NULL,NULL);
	treeNode *n2 = makeRootNode(50,n4,n5);
	treeNode *n10 = makeRootNode(19, NULL,NULL);
	treeNode *n11 = makeRootNode(90, NULL,NULL);
	treeNode *n7 = makeRootNode(42, n10, n11);
	treeNode *n6 = makeRootNode(28, NULL,NULL);
	treeNode *n3 = makeRootNode(65, n6, n7);
	treeNode *n1 = makeRootNode(24, n2, n3);

	printf("\n ������ȸ ��� : ");
	preorder_print(n1);

	inorder_sum(n1);
	printf("\n������ȸ ��� ��: %d", sum);

	printf("\n ������ȸ 30�̻� ��� ��: ");
	postorder_print30(n1);
	printf("\n\n");
}













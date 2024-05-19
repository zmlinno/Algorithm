#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Tree.h"


BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	assert(a);
	if (*pi >= n || a[*pi] = "#")
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}


// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	else
	{
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
}


// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}



// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}




// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (k == NULL || k < 1)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}



// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}

	BTNode* left = BinaryTreeFind(root->_left, x);
	
		if (left != NULL)
		{
			return left;
		}
		return BinaryTreeFind(root->_right, x);
	
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}




// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c", root->_data);
	BinaryTreeInOrder(root->_right);
}



// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	printf("%c", root->_data);
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);

}




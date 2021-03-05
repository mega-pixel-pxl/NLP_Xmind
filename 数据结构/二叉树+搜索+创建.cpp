#inlcude<stdio.h>
#include<stdlib.h>

typedef struct BiTNode		//������������ 
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void PreOrderTraverse(BiTree T)		//ǰ����� 
{
	if(T==NULL)
		return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)		//������� 
{
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)		//������� 
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}

void CreatBiTree(BiTree *T)		//���������� 
{
	char ch;
	sancf("%c",&ch);
	if(ch=='#')
		*T==NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch;
		CreatBiTree(&*T->lchild);
		CreatBiTree(&*T->rchild);
	}
}



#inlcude<stdio.h>
#include<stdlib.h>

typedef struct BiTNode		//定义二叉树结点 
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void PreOrderTraverse(BiTree T)		//前序遍历 
{
	if(T==NULL)
		return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)		//中序遍历 
{
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)		//后序遍历 
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}

void CreatBiTree(BiTree *T)		//创建二叉树 
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



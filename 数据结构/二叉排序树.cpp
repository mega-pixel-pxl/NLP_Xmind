#include<stdio.h>
#include<stdlib.h> 

/*¶þ²æÅÅÐòÊ÷²éÕÒ*/ 
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if(!T)
	{
		*p = f;
		return 0;
	}
	else if(key == T->data)
	{
		*p = T;
		return 1;
	}
	else if(key < T->data)
		return SearchBST(T->lchild, key, f, p);
	else 
		return SearchBST(T->rchild, key, f, p); 
}

/*¶þ²æÅÅÐòÊ÷²åÈëAKA¹¹½¨*/ 

int InsertBST(BiTree *T, int key)
{
	BiTree p,s;
	if(!SerachBST(*T,key,NULL,&p))
	{
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data=key;
		s->lchild=s->rchild=NULL;
		if(!p)
			*T=s;
		else if(key<p->data)
			p->lchild=s;
		else
			p->rchild=s;
		return 1;
	}
	else
		return 0;
}


/*É¾³ý²Ù×÷*/ 

int Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->rchild==NULL)
	{
		q=*p;*p=(*p)->lchild;
		free(q);
	}
	else if((*p)->lchild==NULL)
	{
		q=*p;*p=(*p)->rchild;
	}
	else
	{
		q=*p;s=(*p)->lchild;
		while(s->rchild)
		{
			q=s;s=s->rchild;
		}
		(*p)->data=s->data;
		if(q!=*p)
			q->rchild=s->lchild;
		else
			q->lchild=s->lchild;
		free(s);
	}
	return 1;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode {
	int data;
	StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack {
	LinkStackPtr top;
	int count;
}LinkStack;

void iniLinkstack(LinkStack *S)
{
	S->count=0;
	S->top=NULL;
}

int StackEmpty(LinkStack *S)
{
	if(S->count==0)
		return 1;
	else
		return 0;
}

void push(LinkStack *S,int e)
{
	LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
	s->data=e;
	s->next=S->top;
	S->top=s;
	S->count++;
}

void pop(LinkStack *S,int *e)
{
	if(StackEmpty(S))
	{
		printf("stack is empty!");
		exit(0);
	 } 
	LinkStackPtr s=S->top;
	S->top=S->top->next;
	*e=s->data;
	S->count--;
	free(s);
}

int main(void)
{
	LinkStack S;
	int e;
	iniLinkstack(&S);
	push(&S,1);
	printf("%d\n",S.top->data);
	pop(&S,&e);
	printf("%d \n%d",e,S.count);
	pop(&S,&e);
	return 0;
	
} 

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct {
	
	int data[MAXSIZE];
	int top1;
	int top2;
	
}SqDoubleStack;

void inistack(SqDoubleStack *S)
{
	
	S->top1=-1;
	S->top2=MAXSIZE;
	
}

void push(SqDoubleStack *S,int e,int stacknum)
{
	
	if(S->top1+1==S->top2)
	{
		printf("stack is full!");
		exit(0);
	}
	if(stacknum==1)
	{
		S->top1++;
		S->data[S->top1]=e;
	}
	else if(stacknum==2)
	{
//		S->top2--;
//		S->data[S->top2]=e;
		S->data[--S->top2]=e;
	}
	else
	{
		printf("please input 1 or 2!");
	}
	
}

void pop(SqDoubleStack *S,int *e,int stacknum)
{
	
	if(stacknum==1)
	{
		if(S->top1==-1)
		{
			printf("stack1 is empty!");
			exit(0);
		}
		*e=S->data[S->top1--];
	}
	if(stacknum==2)
	{
		if(S->top2==MAXSIZE)
		{
			printf("stack2 is empty!");
			exit(0);
		}
		*e=S->data[S->top1++];
	}
}

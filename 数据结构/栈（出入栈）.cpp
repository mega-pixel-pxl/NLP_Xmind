#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
typedef struct {
	
	int data[MAXSIZE];
	int top;
	
}Sqstack;

void inistack(Sqstack *S)
{
	S->top=-1;
}

void push(Sqstack *S, int e) 
{
	
	if(S->top == MAXSIZE-1)
	{
		printf("stack is full!\n");
		exit(0);
	}
	S->top++;
	S->data[S->top]=e;
	
} 

void pop(Sqstack *S,int *e)
{
	
	if(S->top==-1)
	{
		printf("stack is empty!");
		exit(0);
	}
	*e=S->data[S->top];
	S->top--;
	
}

int main(void)
{
	Sqstack stk; 
	inistack(&stk);
	int out;
	push(&stk,1);
	printf("%d\n",stk.data[0]);
	pop(&stk,&out);
	printf("%d\n",stk.top);
	printf("%d\n",out);
	pop(&stk,&out);
	return 0;
}

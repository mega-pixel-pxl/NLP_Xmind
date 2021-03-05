#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 5

typedef struct Queue
{
	int data[MAXSIZE];
	int front;
	int rear;
}sqQueue;

int IniQueue(sqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return 1;
}

int QueueEmpty(sqQueue Q)
{
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}

int QueueLenth(sqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

int EnQueue(sqQueue *Q,int e)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
		return 0;
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	
	return 1;
}

int DeQueue(sqQueue *Q,int *e)
{
	if(Q->front==Q->rear)
		return 0;
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	
	return 1;
}

int main()
{	
	int e;
	sqQueue Q;
	IniQueue(&Q);
	QueueLenth(Q);
	EnQueue(&Q,1);
	printf("%d\n",Q.data[0]);
	DeQueue(&Q,&e);
	printf("%d\n",Q.data[0]);
	return 0;
}

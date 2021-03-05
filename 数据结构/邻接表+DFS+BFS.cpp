#include<stdio.h>
#include<stdlib.h>
#include"sequeue.h"
#define MAXVEX 100
#define TURE 1
#define FALSE 0
int visited[MAXVEX];
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode *firstedge;
} VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjlist;
	int numVertexes,numEdges;
}GraphAdjList;

void CreatALGraph(GraphAdjList *G)
{
	int i,j,k;
	EdgeNode *e;
	printf("输入顶点数和边数；\n");
	scanf("%d,%d",&G->numVertexes,G->numEdges);
	for(i=0;i<G->numVertexes;i++)
	{
		scanf(&G->adjlist[i].data);
		G->adjlist[i].firstedge=NULL;
	}
	
	for(k=0;k<G->numEdges;k++)
	{
		printf("输入边（vi,vj）上的顶点序号：\n");
		scanf("%d,%d",&i,&j);
		e=(EdgeNode*)malloc(sizeof(EdgeNode));
		
		e->adjvex=j;
		e->next=G->adjlist[i].firstedge;			//头插法 
		G->adjlist[i].firstedge=e;
		
		e=(EdgeNode*)malloc(sizeof(EdgeNode));

		e->adjvex=i;
		e->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=e;
		
	}
}

/*邻接表实现深度优先递归算法*/

void DFS(GraphAdjList GL,int i)
{
	EdgeNode *p;
	visited[i]=TURE;
	printf("%c",GL.adjlist[i].data);
	p=GL.adjlist[i].firstedge;
	while(p)
	{
		if(!visited[p->adjvex])
			DFS(GL,p->adjvex);
		p=p->next;
	}
} 

void DFSTraverse(GraphAdjList GL)
{
	int i;
	for(i=0;i<GL.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<GL.numVertexes;i++)
		if(!visited[i])
			DFS(GL,i);
}

/*邻接表实现广度优先遍历算法*/
void BFSTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode *p;
	Queue Q;
	for(i=0;i<GL->numVertexes;i++)
		visited[i]=FALSE;
	InitQueue(&Q);
	for(i=0;i<GL.numVertexes;i++)
	{
		if(!visited[i])
		{
			visited[i]=TURE;
			printf("%c",GL.adjlist[i].data);
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				P=GL.adjlist[i].firstedge;
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex]=TURE;
						EnQueue(&Q,p->adjvex);
						printf("c",GL.adjlist[p->adjvex].data);
					}
					p=p->next;
				}
			}
		}
	}
} 

#include<stdio.h>
#include<stdlib.h>
#include"sequeue.h"
typedef char VertexType;
typedef int EdgeType; 
#define MAXVEX 100
#define INFINITY 65535
#define TURE 1
#define FALSE 0
typedef struct
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes,numEdges;
}MGraph;

void CreatMGraph(MGraph *G)
{
	int i,j,k,w;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d",&G->numVertexes,&G->numEdges);
	for(i=0;i<G->numVertexes;i++)
	{
		scanf("%c",&G->vexs[i]);
	}
	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j]=INFINITY;
	for(k=0;k<G->numEdges;k++)
	{
		printf("please input edge (vi,vj)'s dot i and j and w:\n");
		scanf("%d,%d,%d",&i,&j,&w);
		G->arc[i][j]=w;
		G->arc[j][i]=G->arc[i][j];
	}
}


/*下面是用邻接矩阵实现深度遍历*/

int visited[MAXVEX];

void DFS(MGraph G,int i)
{
	int j;
	visited[i]=TURE;
	printf("%c",G.vexs[i]);
	for(j=0;j<G.numVertexes;j++)
		if(G.arc[i][j]==1&&!visited[j])
			DFS(G,j);
}

void DFSTraverse(MGraph G)
{
	int i;
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++)
		if(!visited[i])
			DFS(G,i);
}
 
 /*邻接矩阵的广度优先遍历算法*/
 
void BFSTraverse(MGraph G)
{
	int i,j;
	sqQueue Q;
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	IniQueue(&Q);
	for(i=0;i<G.numVertexes;i++)
	{
		if(!visited[i])
		{
			visited[i]=TURE;
			printf("%c",G.vexs[i]);
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				for(j=0;j<G.numVertexes;j++)
				{
					if(G.arc[i][j]==1&&!visited[j])
					{
						visited[j]=TURE;
						printf("%c",G.vexs[j]);
						EnQueue(&Q,j);
					}
				}
			}
		}
	}
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

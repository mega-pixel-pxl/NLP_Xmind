/*kruskal算法生成最小生成树*/
#include<stdio.h>
#include<stdlib.h>
#include"邻接矩阵实现无向图+DFS+BFS.cpp"
int Find(int *parent,int f);
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

void MiniSpanTree_Kruskal(MGraph G)
{
	int i,n,m,k=0,min,tem;
	Edge edges[MAXVEX];
	int parent[MAXVEX];
	/*把邻接矩阵转换为边集组并且按由小到大排序*/
	for(i=0;i<G.numVertexes;i++)
		for(int j=i+1;j<G.numVertexes;j++)
			if(G.arc[i][j]<65535)
			{
				edges[k].weight=G.arc[i][j];
				edges[k].begin=i;
				edges[k].end=j;
				k++;
			}
			
	for(i=0;i<G.numEdges;i++)
	{
		min=edges[i].weight;
		for(int j=i+1;j<G.numVertexes;j++)
			if(edges[j].weight<min)
			{
				min=edges[j].weight;
				k=j;
			}	
		tem=edges[i].weight;
		edges[i].weight=min;
		edges[k].weight=tem;		
	}		
	
	for(i=0;i<G.numVertexes;i++)
		parent[i]=0;
	for(i=0;i<G.numEdges;i++)
	{
		n=Find(parent,edges[i].begin);
		m=Find(parent,edges[i].end);
		if(m!=n)
		{
			parent[n]=m;
			printf("（%d,%d) %d",edges[i].begin,edges[i].end,edges[i].weight);
		}
	}
}

int Find(int *parent,int f)
{
	while(parent[f]>0)
		f=parent[f];
	return f;
}

#include<stdio.h>
#include<stdlib.h>
#include"邻接矩阵实现无向图+DFS+BFS.cpp" 

void MiniSpanTree_Prim(MGraph G)
{
	int min,i,j,k;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	lowcost[0]=0;
	
	adjvex[0]=0;
	for(i=0;i<G.numVertexes;i++)
	{
		lowcost[i]=G.arc[0][1];
		adjvex[i]=0;
	}
	
	for(i=1;i<G.numVertexes;i++)
	{
		min=65535;
		j=1;k=0;
		while(j<G.numVertexes)
		{
			if(lowcost[j]!=0&&lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;
			}
			j++;
		}
		
		printf("(%d,%d)",adjvex[k],k);
		lowcost[k]=0;
		
		for(j=1;j<G.numVertexes;j++)
		{
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
			{
				lowcost[j]=G.arc[k][j];
				adjvex[j]=k;
			}
		}
	}
	
}

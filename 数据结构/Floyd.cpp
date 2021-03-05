#include<stdio.h>
#include<stdlib.h>
#include"�ڽӾ���ʵ������ͼ+DFS+BFS.cpp"
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void ShortPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable *D)
{
	int v,w,k;
	for(v=0;v<G.numVertexes;v++)
	{
		for(w=0;w<G.numVertexes;w++)
		{
			(*D)[v][w]=G.arc[v][w];
			(*P)[v][w]=w;
		}
	}
	for(k=0;k<G.numVertexes;k++)
	{
		for(v=0;v<G.numVertexes;v++)
		{
			for(w=0;w<G.numVertexes;w++)
			{
				if((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
				{
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];
					(*P)[v][w]=(*P)[v][k];
				}
			}
		}
	}
	/*ͨ�����������·���ĺ�����Ӧ��ͬ�յ�����·��ȫ�����*/
	for(v=0;v<G.numVertexes;v++)
	{
		for(w=v+1;w<G.numVertexes;w++)
		{
			printf("v%d-v%d weight: %d",v,w,D[v][w]);
			k=P[v][w];
			printf(" path: %d",v);
			while(k!=w)
			{
				printf(" -> %d",k);
				k=P[k][w];
			}
			printf(" -> %d\n",w);
		}
		orintf(" -> %d\n",w);
	} 
	printf("\n");
}


 

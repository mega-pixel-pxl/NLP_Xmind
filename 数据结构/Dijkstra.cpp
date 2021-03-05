#include<stdio.h>
#include<stdlib.h>
#include"�ڽӾ���ʵ������ͼ+DFS+BFS.cpp"


typedef int Patharc[MAXVEX];			//���ڴ������·���±������ 
typedef int ShortPathTable[MAXVEX]; 	//���ڴ��浽�������·����Ȩֵ�� 
/*dijkstra�㷨����������G��v0���㵽���ඥ��v���·��P[v]����Ȩ����D[v] 
P[v]��ֵΪǰ�������±꣬D[v]��ʾv0��v�����·�����Ⱥ�*/ 
void ShortestPath_Dijkstra(MGraph G,int v0,Patharc *P,ShortPathTable *D)
{
	int v,w,k,min;
	int final[MAXVEX];//final[w]=1 ��ʾ��ö���v0��vw�����·�� 
	for(v=0;v<G.numVertexes;v++)//��ʼ������ 
	{
		final[v] = 0;			//ȫ�������ʼ��Ϊδ֪·��״̬ 
		(*D)[v] = G.arc[v0][v];//����v0�����ߵĶ������Ȩֵ 
		(*P)[v] = 0;			//��ʼ��·������PΪ0 
	}
	(*D)[v0] = 0;				//v0��v0��·��Ϊ0 
	final[v0] = 1;				//v0��v0����Ҫ��·�� 
//��ʼ��ѭ����ÿ�����V0��ĳ��v��������·��	
for(v=1;v<G.numVertexes;v++)
{
	min = INFINITY;			// ��ǰ��֪��v0������������ 
	for(w=0;w<G.numVertexes;w++)//Ѱ����v0����Ķ��� 
	{
		if(!final[w]&&(*D)[w]<min)
		{
			k=w;
				min=(*D)[w];	//w��v0������� 
		}
	}
	final[k]=1;//��Ŀǰ�ҵ�������Ķ�����Ϊ1 
	for(w=0;w<G.numVertexes;w++)//������ǰ���·�������� 
	{
		//�������v�����·������������·���ĳ��ȶ̵Ļ� 
		if(!final[w]&&(min+G.arc[k][w]<(*D)[w]))
		{//˵���ҵ��˸��̵�·�����޸�D[w]��P[w] 
			(*D)[w]=min+G.arc[k][w];//�޸ĵ�ǰ·������ 
			(*P)[w]=k;
		}
	}
}

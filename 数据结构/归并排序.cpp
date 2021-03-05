#include"排序用结构和函数.h" 

//递归实现归并算法 
void MergeSort(SqList *L)
{
	Msort(L->r,L->r,1,L->length);
}

void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;
		MSort(SR,TR2,s,m);
		MSort(SR,TR2,m+1,t);
		Merge(TR2,TR1,s,m,t);
	}
}

void Merge (int SR[], int TR[], int i, int m, int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m&&j<=n;k++)
	{
		if(SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-1;l++)
			TR[k+l]=SR[i+1];
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];
	}
}

//非递归实现

void MergeSort2(SqList *L)
{
	int * TR = (int *)malloc(L->length*sizeof(int));
	int k=1;
	while(k<k->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;
		MergePass(TR,L->r,k,L->length);
		k=2*k;
	}
}

void MergePass(int SR[],int TR[],int s,int n)
{
	int i=1;
	int j;
	while(i<=n-2*s+1)
	{
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;
	}
	if(i<n-s+1)
		Merge(SR,TR,i,i+s-1,n);
	else
		for(j=1;j<=n;j++)
			TR[j]=SR[j];
}

#inlcude"排序用结构和函数.h"

void InsertSort(SqList *L)//传入的数组第一个元素应该是0 
{
	int i,j;
	for(i=2;i<L->length;i++)
	{
		if(L->r[i]<L->r[i-1])
		{
			L->r[0]=L->r[i];
			for(j=i-1;L->r[j]>L->r[0];j--)
			{
				L->r[j+1]=L->r[j];
			}
			L->r[j+1]=L->r[0]; 
		}
	}
} 

#inlcude"排序用结构和函数.h"

void SelectSort(Sqlist *L)
{
	int i,j,min;
	for(i=0;i<L->length;i++)
	{
		min=i;
		for(j=i+1;j<L->length;j++)
		{
			if(L->r[j]<L->r[min])
				min=j;
		}
		if(!min)
			swap(L,i,min);
	}
}

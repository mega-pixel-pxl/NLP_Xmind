#include"排序用结构和函数.h" 


//初级冒泡排序 
void BubbleSort(SqList *L)
{
	int i,j;
	for(i=0;i<L->length;i++)
	{
		for(j=i+1;j<L->length;j++)
		{
			if(L->r[i]>L->r[j])
				swap(L,i,j);
		}
	}
}

//真正的冒泡排序

void realBubbleSort(SqList *L)
{
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
				swap(L,j,j+1);
		}
	}
}

//优化冒泡排序

void realBubbleSort(SqList *L)
{
	int i,j,flag;
	for(i=1;i<L->length && flag;i++)		//flag用来判断是否已经排序完毕 
	{										//如果flag为ture则外循环可以继续										 
		flag=FALSE;							//如果内循环体未发生交换则外循环退出
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1);
				flag=TURE;
			}	
		}
	}
}

#include"排序用结构和函数.h" 

//普通快排 

void QuickSort(SqList *L)
{
	QSort(L,1,L->length);
}

void QSort(SqList *L,int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot=Partition(L,low,high);
		
		QSort(L,low,pivot-1);
		QSort(L,pivot+1,high);
	}
}

void Partiton(SqList *L,int low,int high)
{
	int pivotkey;
	pivotkey=L->r[low];
	while(low<high)
	{
		while(low<high&&L->r[high]>=pivotkey)
			high--;
		swap(L,low,high);
		while(low<high&&L-r[low]<=pivotkey)
			low++;
		swap(L,low,high);
	}
	return low;
}

//改良快排1：优化选取轴枢

void Partiton(SqList *L,int low,int high)
{
	int pivotkey;
	
	//下面的代码改进了中枢的选择，从三个值中选择最优的中枢值
	//保证中枢值是一个中间值而不会过大过小 
	int m=low+(high+low)/2;
	if(L->r[low]>L->r[high])
		swap(L,low,high);
	if(L->r[m]>L->r[high])
		swap(L,m,high);
	if(L->r[m]<L->r[low])
		swap(L,m,low);
		
		
	pivotkey=L->r[low];
	while(low<high)
	{
		while(low<high&&L->r[high]>=pivotkey)
			high--;
		swap(L,low,high);
		while(low<high&&L-r[low]<=pivotkey)
			low++;
		swap(L,low,high);
	}
	return low;
}

//改良快排2：优化不必要交换

void Partiton(SqList *L,int low,int high)
{
	int pivotkey;
	
	//下面的代码改进了中枢的选择，从三个值中选择最优的中枢值
	//保证中枢值是一个中间值而不会过大过小 
	int m=low+(high+low)/2;
	if(L->r[low]>L->r[high])
		swap(L,low,high);
	if(L->r[m]>L->r[high])
		swap(L,m,high);
	if(L->r[m]<L->r[low])
		swap(L,m,low);
		
	L->r[0]=pivotkey;
	
	pivotkey=L->r[low];
	while(low<high)
	{
		while(low<high&&L->r[high]>=pivotkey)
			high--;
		//swap(L,low,high);
		L->r[low]=L->r[high];
		while(low<high&&L-r[low]<=pivotkey)
			low++;
		//swap(L,low,high);
		L->r[high]=L->r[low];
	}
	L->r[low]=L->r[0];
	return low;
}

//改进快排3：优化小数组时的排序方案

void QSort(SqList *L,int low,int high)
{
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)		//MAX...这个参数代表阈值数组的长度 
	{
		pivot=Partition(L,low,high);
		
		QSort(L,low,pivot-1);
		QSort(L,pivot+1,high);
	}
	else
		InserSort(L) ;
}

//改进快排4：优化递归操作（采用尾递归）

void QSort1(SqList *L,int low,int high)
{
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)		//MAX...这个参数代表阈值数组的长度 
	{
		while(low<high)
		{
			pivot=Partition(L,low,high);		//此处因为low递归一次后就没有作用了所以令其等于pivot+1实现一次partition来代替递归可以有效减少递归带来的空间损失 
			
			QSort1(L,low,pivot-1);
			low=pivot+1;
		}
		//QSort(L,pivot+1,high);
	}
	else
		InserSort(L) ;
}

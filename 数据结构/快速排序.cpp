#include"�����ýṹ�ͺ���.h" 

//��ͨ���� 

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

//��������1���Ż�ѡȡ����

void Partiton(SqList *L,int low,int high)
{
	int pivotkey;
	
	//����Ĵ���Ľ��������ѡ�񣬴�����ֵ��ѡ�����ŵ�����ֵ
	//��֤����ֵ��һ���м�ֵ����������С 
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

//��������2���Ż�����Ҫ����

void Partiton(SqList *L,int low,int high)
{
	int pivotkey;
	
	//����Ĵ���Ľ��������ѡ�񣬴�����ֵ��ѡ�����ŵ�����ֵ
	//��֤����ֵ��һ���м�ֵ����������С 
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

//�Ľ�����3���Ż�С����ʱ�����򷽰�

void QSort(SqList *L,int low,int high)
{
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)		//MAX...�������������ֵ����ĳ��� 
	{
		pivot=Partition(L,low,high);
		
		QSort(L,low,pivot-1);
		QSort(L,pivot+1,high);
	}
	else
		InserSort(L) ;
}

//�Ľ�����4���Ż��ݹ����������β�ݹ飩

void QSort1(SqList *L,int low,int high)
{
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)		//MAX...�������������ֵ����ĳ��� 
	{
		while(low<high)
		{
			pivot=Partition(L,low,high);		//�˴���Ϊlow�ݹ�һ�κ��û�������������������pivot+1ʵ��һ��partition������ݹ������Ч���ٵݹ�����Ŀռ���ʧ 
			
			QSort1(L,low,pivot-1);
			low=pivot+1;
		}
		//QSort(L,pivot+1,high);
	}
	else
		InserSort(L) ;
}

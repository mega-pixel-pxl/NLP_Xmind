#include"�����ýṹ�ͺ���.h" 


//����ð������ 
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

//������ð������

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

//�Ż�ð������

void realBubbleSort(SqList *L)
{
	int i,j,flag;
	for(i=1;i<L->length && flag;i++)		//flag�����ж��Ƿ��Ѿ�������� 
	{										//���flagΪture����ѭ�����Լ���										 
		flag=FALSE;							//�����ѭ����δ������������ѭ���˳�
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

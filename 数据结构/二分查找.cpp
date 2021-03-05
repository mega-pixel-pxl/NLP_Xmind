#include<stdio.h>
#include<stdlib.h>


int Binary_Search(int *a, int n, int key)
{
	int low,high,mid;
	low=1;
	high=n;
	while(low<=high)
	{
		mid=(low+high)/2;		//mid=low + (high - low)*(key - a[low])/(a[high] - a[low]);    ת��Ϊ��ֵ���� 
		if(key<a[mid])
			high=mid-1;
		else if(key>a[mid])
			low=mid+1;
		else
			return mid;
	}
	return 0;
}

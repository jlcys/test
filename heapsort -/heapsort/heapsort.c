//½¨¶Ñ
#include"heapsort.h"
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void adjustup(int *a,int child)//¸ÇÐ¡¶Ñ
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
	if (a[child] < a[parent])
	{
	swap(&a[child], &a[parent]);
	child = parent;
	parent = (child - 1) / 2;
	}
	else
	{
       break;
	}
	}
	

}
void adjustdown(int *a,int size,int parent)
{
	
	int child = parent * 2 + 1;
	while (child < size)
	{
if (a[child] > a[child + 1]&&child+1<size)
	{
		child++;
	}
if (a[child] < a[parent])
{
	swap(&a[child], &a[parent]);
	parent = child;
	child= parent * 2 + 1;
}
else break;
	}
}
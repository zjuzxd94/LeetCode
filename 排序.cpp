#include <iostream>
#include <algorithm>
using namespace std;

//√∞≈›≈≈–Ú
void bubbleSort(int *a, int n)
{
	for(int i=n-1;i>0;i--)
	{
		int flag = 0;
		for(int j=0;j<i;j++)
			if(a[j]>a[j+1])
			{
				flag = 1;
				a[j] = a[j] + a[j+1];
				a[j+1] = a[j] - a[j+1];
				a[j] = a[j] - a[j+1];
			}
		if(flag == 0)
			break;
	}
}
//≤Â»Î≈≈–Ú
void insertSort(int *a, int n)
{
	for(int i=1;i<n;i++)
	{
		int temp = a[i];
		int j=i;
		for(;j>0;j--)
			if(a[j-1]>temp)
				a[j] = a[j-1];
			else
				break;
		a[j] = temp;
	}
}
//œ£∂˚‘ˆ¡ø≈≈–Ú
void shellSort(int *a, int n)
{
	for(int d=n/2;d>0;d/=2)
		for(int i=d;i<n;i+=d)
		{
			int temp = a[i];
			int j = i;
			for(;j>=d;j-=d)
				if(a[j-d]>temp)
					a[j]=a[j-d];
				else
					break;
			a[j] = temp;
		}
}
//∂—≈≈–Ú
bool comp(int a,int b)
{
	return a>b;
}
void heapSort(int *a, int n)
{
	//for(int i=0;i<n;i++)
	//	make_heap(a+i,a+n,comp);
	make_heap(a,a+n,comp);
	pop_heap(a,a+n,comp);
}

int main()
{
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	heapSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
}
#include "iostream"

using namespace std;

void swap(int *a,int *b)
{
	if(a==b)
		return;
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void quicksort(int *p, int left, int right)
{
	if(left>=right)
		return;
	int pivot = p[left];
	int i = left; int j = right+1;
	while(i<j)
	{
		while(i<j&&p[--j]>pivot);//外层while跳出后，交换的是left和j时，要先从右往左
		while(i<j&&p[++i]<pivot);
		//while(i<j&&p[--j]>pivot);//外层while跳出后，交换的是left和i时，要先从左往右
		if(i<j)
			swap(&p[i],&p[j]);
	}
	swap(&p[left],&p[j]);
	quicksort(p,left,j-1);
	quicksort(p,j+1,right);
}
int main()
{
	int n;
	cin>>n;
	int *p = new int[n];
	for(int i=0;i<n;i++)
		cin>>p[i];
	quicksort(p,0,n-1);
	for(int i=0;i<n;i++)
		cout<<p[i]<<' ';
}
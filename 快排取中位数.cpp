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
int median3(int *_array,int left,int right)//必须保证right>left
{
	int center = (left+right)/2;
	if(_array[left]>_array[center])
		swap(&_array[left],&_array[center]);
	if(_array[left]>_array[right])
		swap(&_array[left],&_array[right]);
	if(_array[center]>_array[right])
		swap(&_array[center],&_array[right]);
	swap(&_array[center],&_array[right-1]);
	return _array[right-1];
}
void _quicksort(int *_array,int left,int right)
{
	if(left>=right)
		return;
	int pivot = median3(_array, left, right);
	
	int i = left; int j = right - 1;//right位置上已经是比pivot大的数了，j位置是pivot，i位置是比pivot小的数，都不必比较
	while(i<j)
	{
		while(i<j&&_array[++i]<pivot);
		while(i<j&&_array[--j]>pivot);//如果pivot放在left+1位置上，这两个while就要交换位置，且外层while跳出后的swap语句交换的是_array[j]和_array[left+1]
		if(i<j)
			swap(&_array[i],&_array[j]);
		else
			break;
	}
	swap(&_array[i],&_array[right-1]);//i位置上已经是一个比pivot大的数了，交换它们
	_quicksort(_array,left,i-1);
	_quicksort(_array,i+1,right);


}
void quicksort(int *_array,int n)
{
	_quicksort(_array,0,n-1);
}
int main()
{
	int n;
	cin>>n;
	int *_array = new int[n];
	for(int i=0;i<n;i++)
		cin>>_array[i];
	
	quicksort(_array,n);
	for(int i=0;i<n;i++)
		cout<<_array[i]<<' ';
}
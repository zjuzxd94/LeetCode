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
int median3(int *_array,int left,int right)//���뱣֤right>left
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
	
	int i = left; int j = right - 1;//rightλ�����Ѿ��Ǳ�pivot������ˣ�jλ����pivot��iλ���Ǳ�pivotС�����������رȽ�
	while(i<j)
	{
		while(i<j&&_array[++i]<pivot);
		while(i<j&&_array[--j]>pivot);//���pivot����left+1λ���ϣ�������while��Ҫ����λ�ã������while�������swap��佻������_array[j]��_array[left+1]
		if(i<j)
			swap(&_array[i],&_array[j]);
		else
			break;
	}
	swap(&_array[i],&_array[right-1]);//iλ�����Ѿ���һ����pivot������ˣ���������
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
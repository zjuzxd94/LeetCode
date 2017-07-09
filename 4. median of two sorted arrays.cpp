#include "head.h"

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total=nums1.size()+nums2.size();
		vector<int>::iterator a=nums1.begin();
		vector<int>::iterator b=nums2.begin();
		if(total%2)
			return findKth(a,nums1.size(),b,nums2.size(),total/2+1);
		else
			return (findKth(a,nums1.size(),b,nums2.size(),total/2)+
			findKth(a,nums1.size(),b,nums2.size(),total/2+1))/2;

	}
private:
	double findKth(vector<int>::iterator a, int m, vector<int>::iterator b, int n, int k){
		//传进来的参数，m和n不可能同时为零
		//保证m是小于n的
		if(m>n)
			return findKth(b,n,a,m,k);
		if(m==0)
			return b[k-1];
		if(k==1)
			return min(a[0],b[0]);
		int pa=min(k/2,m),pb=k-pa;
		if(a[pa-1]<b[pb-1])
			return findKth(a+pa,m-pa,b,n,k-pa);
		else if(a[pa-1]>b[pb-1])
			return findKth(a,m,b+pb,n-pb,k-pb);
		else
			return a[pa-1];
	}
	int min(int a,int b){
		return a>b?b:a;
	}
};

int main()
{
	Solution s;
	vector<int> a,b;
	a.push_back(1);
	a.push_back(3);
	b.push_back(2);
	double result = s.findMedianSortedArrays(a,b);
}
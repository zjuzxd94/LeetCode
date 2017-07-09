#include "head.h"
class Solution {
public:
	int mySqrt(int x) {
		//二分法
		long long l=0,r=x;
		int count=0;
		while(l!=r){
			long long mid=(l+r)/2;
			long long temp=mid*mid;
			if(temp>x)r=mid;
			else if(temp<x)l=mid;
			else return mid;
			if(r*r==x)return r;
			if(r-l==1)return l;
			count++;
			//printf("%d\n",count);
			cout<<l<<' '<<r<<endl;
		}
		return r;
	}
};
class Solution1 {
public:
	int mySqrt(int x) {
		//牛顿梯度法
		double pre=0;
		double cur=x;
		int count=0;
		while(abs(cur-pre)>0.1){
			pre=cur;
			cur=pre/2+x/(2*pre);
			count++;
			printf("%d\n",count);
		}
		return int(cur);
	}
};
int main()
{
	Solution s;
	cout<<s.mySqrt(1579205274);
}
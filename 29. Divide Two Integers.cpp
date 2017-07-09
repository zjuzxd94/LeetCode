//Accepted date: 20170604
//Author: xaingdongzhao
#include "head.h"
class Solution {
public:
	int divide(int dividend, int divisor) {
		if(divisor==0)
			return INT_MAX;
		if(dividend==0)
			return 0;
		int flag=1;
		if(dividend<0)
			flag=-flag;
		if(divisor<0)
			flag=-flag;
		long long d1=abs((long long)(dividend));
		long long d2=abs((long long)(divisor));
		if(d1<d2)
			return 0;

		long long result=0;
		long long i=0;
		long long temp=d2;
		while(d1>=temp){
			temp=temp<<1;
			i++;
		}
		temp=temp>>1;i--;
		while(temp!=d2){
			if(d1>=temp){
				result+=(long long)(1)<<i;
				d1-=temp;
			}
			i--;
			if(d1==0)
				break;
			temp=temp>>1;
		}
		if(d1>=d2)
			result++;
		result =flag==-1?-result:result;
		if(result>INT_MAX||result<INT_MIN)
			result=INT_MAX;
		return result;
	}
};

int main()
{
	Solution s;
	cout<<s.divide(-2147483648,-1);
}
//Accepted date: 20170603
//Author: xaingdongzhao
#include "head.h"
class Solution {
public:
	int findNthDigit(int n) {
		if(n<10)
			return n;
		int temp=n;
		long long a=9;
		int i=1;
		while(temp>a*i){
			temp-=a*(i++);
			a*=10;
		}
		int init=1;
		for(int j=1;j<i;j++)
			init*=10;
		int b=temp%i==0?temp/i:(temp/i+1);
		init+=b-1;
		b=(i-temp%i)%i;
		while(b-->0)
			init/=10;
		return init%10;
	}
};

int main()
{
	Solution s;
	cout<<s.findNthDigit(1000000000);
}
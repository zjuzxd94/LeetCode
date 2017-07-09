//Accepted date: 20170611
//Author: xaingdongzhao
#include "head.h"

class Solution {
public:
	int arrangeCoins(int n) {
		long long temp=sqrt(2*(long long)n);
		temp++;
		while(temp*(temp+1)>2*(long long)n)temp--;
		return temp;
	}
};

int main()
{
	Solution s;
	s.arrangeCoins(1804289383);
}
//Accepted date: 20170626
//Author: xaingdongzhao
#include "head.h"

//思路：当前长度是n，每个相同的起始元素对应(n-1)!个permutation，也就是(n-1)!个permutation后会换一个起始元素。
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> factorial(n+1,1);
		vector<int> digit(n);
		string result;
		for(int i=1;i<=n;i++){
			factorial[i]=factorial[i-1]*i;
			digit[i-1]=i;
		}
		while(!digit.empty()){
			int temp=(k-1)/factorial[n-1];
			result+=('0'+digit[temp]);
			digit.erase(digit.begin()+temp);
			k-=temp*factorial[n-1];
			n--;
		}
		return result;
	}
};
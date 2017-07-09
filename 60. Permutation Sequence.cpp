//Accepted date: 20170626
//Author: xaingdongzhao
#include "head.h"

//˼·����ǰ������n��ÿ����ͬ����ʼԪ�ض�Ӧ(n-1)!��permutation��Ҳ����(n-1)!��permutation��ỻһ����ʼԪ�ء�
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
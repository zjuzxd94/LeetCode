//Accepted date: 20170601
//Author: xaingdongzhao
#include "head.h"
class Solution {
public:
	bool isHappy(int n) {
		set<int> s;
		while(n!=1&&s.find(n)==s.end()){
			s.insert(n);
			int temp=n;
			n=0;
			while(temp>0){
				n+=(temp%10)*(temp%10);
				temp/=10;
			}
		}
		if(n==1)
			return true;
		else
			return false;
	}
};
//Accepted date: 20170603
//Author: xaingdongzhao

class Solution {
public:
	int getSum(int a, int b) {
		if(b==0)return a;
		int c=a^b;
		int carry=(a&b)<<1;
		return getSum(c,carry);
	}
};
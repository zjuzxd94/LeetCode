//Accepted date: 20170612
//Author: xaingdongzhao
#include "head.h"


//Ë¼Â· ²Î¿¼http://blog.csdn.net/sophia1224/article/details/53066315
class Solution {
public:
	int minMoves(vector<int>& nums) {
		int n=nums.size();
		int minNum=INT_MAX;
		int sum=0;
		for(int i=0;i<n;i++){
			if(nums[i]<minNum)
				minNum=nums[i];
			sum+=nums[i];
		}
		return sum-n*minNum;
	}
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2147483647);
	cout<<s.minMoves(nums);
}
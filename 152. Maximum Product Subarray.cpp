//Accepted date: 20170709
//Author: xaingdongzhao

#include "head.h"

//思路：类似于最大子列和的动态规划，不同之处在于，维护一个局部最大的同时还要维护一个局部最小
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n=nums.size();
		if(n==0)return 0;
		vector<int> dpMax(nums);
		vector<int> dpMin(nums);
		int result=dpMax[0];
		for(int i=1;i<n;i++){
			dpMax[i]=max(max(dpMax[i-1]*nums[i],nums[i]),dpMin[i-1]*nums[i]);
			dpMin[i]=min(min(dpMax[i-1]*nums[i],nums[i]),dpMin[i-1]*nums[i]);
			if(dpMax[i]>result){
				result=dpMax[i];
			}
		}
		return result;
	}
};
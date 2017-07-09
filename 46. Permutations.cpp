//Accepted date: 20170621
//Author: xaingdongzhao
#include "head.h"

//思路：回溯和递归
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> temp;
		recursion(nums,temp,result);
		return result;
	}
	void recursion(vector<int> nums, vector<int> temp, vector<vector<int>>& result){
		if(nums.empty()){
			result.push_back(temp);
			return;
		}
		for(int i=0;i<nums.size();i++){
			temp.push_back(nums[i]);
			vector<int> nums1=nums;
			nums1.erase(nums1.begin()+i);
			recursion(nums1,temp,result);
			temp.pop_back();
		}
	}
};
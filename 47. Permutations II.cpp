//Accepted date: 20170621
//Author: xaingdongzhao
#include "head.h"

//思路：回溯和递归
//因为有重复元素，先排序，遍历的时候跳过重复元素
class Solution {
public:
	static int comp(const void* a, const void* b){
		return *(int*)a-*(int*)b;
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		qsort(nums.data(),nums.size(),4,comp);
		vector<int> temp;
		recursion(nums,temp,result);
		return result;
	}
	void recursion(vector<int> nums, vector<int> temp, vector<vector<int>>& result){
		if(nums.empty()){
			result.push_back(temp);
			return;
		}
		int last=nums[0]-1;
		for(int i=0;i<nums.size();i++){
			if(nums[i]==last)
				continue;
			last=nums[i];
			temp.push_back(nums[i]);
			vector<int> nums1=nums;
			nums1.erase(nums1.begin()+i);
			recursion(nums1,temp,result);
			temp.pop_back();
		}
	}
};
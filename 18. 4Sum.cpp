//Accepted date: 20170528
//Author: xaingdongzhao
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//思路：在3Sum的基础上再套一层循环
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if(nums.size()==0)
			return result;
		int len=nums.size();
		qsort(nums.data(),len,sizeof(nums[0]),comp);
		long long lasti=nums[0]-1;
		for(int i=0;i<len-3;i++){
			if(nums[i]==lasti)
				continue;
			long long lastj=nums[i+1]-1;
			for(int j=i+1;j<len-2;j++){
				if(nums[j]==lastj)
					continue;
				int left=j+1;
				int right=len-1;
				long long matchedL=nums[left]-1;
				long long matchedR=nums[right]+1;
				while(left<right){
					int sum=nums[i]+nums[j]+nums[left]+nums[right];
					if(sum<target)
						left++;
					else if(sum>target)
						right--;
					else{
						if(nums[left]==matchedL&&nums[right]==matchedR)//避免重复
							;
						else{
							matchedL=nums[left];
							matchedR=nums[right];
							vector<int> tempResult;
							tempResult.push_back(nums[i]);
							tempResult.push_back(nums[j]);
							tempResult.push_back(nums[left]);
							tempResult.push_back(nums[right]);
							result.push_back(tempResult);
						}
						left++;
						right--;
					}
				}
				lastj=nums[j];
			}
			lasti=nums[i];
		}

		return result;
	}
	static int comp(const void* a, const void* b){
		return *(int*)a-*(int*)b;
	}
};

int main()
{
	vector<int> nums(6);
	nums[0]=1;
	nums[1]=0;
	nums[2]=-1;
	nums[3]=0;
	nums[4]=-2;
	nums[5]=2;
	int target=0;

	Solution s;
	vector<vector<int>> result=s.fourSum(nums,target);
	return 0;
}
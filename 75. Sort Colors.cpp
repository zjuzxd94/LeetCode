//Accepted date: 20170627
//Author: xaingdongzhao
#include "head.h"

//思路：用三个index：left right i
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if(nums.size()<2)return;
		int left=0;
		int right=nums.size()-1;
		while(nums[left]==0&&left<right)left++;
		while(nums[right]==2&&left<right)right--;
		int i=left;
		while(i<=right&&left<=right){
			if(nums[i]==0){
				nums[i]=nums[left];
				nums[left++]=0;
				i=left;
			}
			else if(nums[i]==1)
				i++;
			else if(nums[i]==2){
				nums[i]=nums[right];
				nums[right--]=2;
			}
		}
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	Solution s;
	s.sortColors(nums);

	string str;
	
	return 0;
}
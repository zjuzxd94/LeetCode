//Accepted date: 20170605
//Author: xaingdongzhao
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if(nums.empty())return -1;
		int l=0,r=nums.size()-1;
		while(l<r){
			if(r-l==1)//注意这里跳出的条件，否则会陷入死循环
				return nums[l]==target?l:(nums[r]==target?r:-1);
			int mid=r-(r-l+1)/2;
			if(nums[mid]==target)
				return mid;
			if(nums[mid]>=nums[l]&&nums[mid]>target){
				if(nums[l]<=target)
					r=mid;
				else
					l=mid;
			}
			else if(nums[mid]>=nums[l]&&nums[mid]<target)
				l=mid;
			else if(nums[mid]<nums[l]&&nums[mid]>target)
				r=mid;
			else if(nums[mid]<nums[l]&&nums[mid]<target){
				if(nums[r]>=target)
					l=mid;
				else
					r=mid;
			}
		}
		return nums[l]==target?l:-1;
	}
};
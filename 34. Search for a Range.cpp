//Accepted date: 20170605
//Author: xaingdongzhao

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		int l=0,r=nums.size()-1;
		while(l<=r){
			if(r-l<=1){
				if(nums[l]==nums[r]&&nums[l]==target){
					result.push_back(l);
					result.push_back(r);
				}
				else if(nums[l]==target){
					result.push_back(l);
					result.push_back(l);
				}
				else if(nums[r]==target){
					result.push_back(r);
					result.push_back(r);
				}
				break;
			}
			int mid=r-(r-l+1)/2;
			if(nums[mid]==target){
				int left=mid,right=mid;
				while(left>=0&&nums[left]==target)left--;
				while(right<nums.size()&&nums[right]==target)right++;
				result.push_back(left+1);
				result.push_back(right-1);
				break;
			}
			else if(nums[mid]<target)
				l=mid;
			else
				r=mid;
		}
		if(result.empty())
		{
			result.push_back(-1);
			result.push_back(-1);
		}
		return result;
	}
};
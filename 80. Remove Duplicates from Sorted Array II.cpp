#include "head.h"
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		map<int,int> hash;
		vector<int> result;
		int i=0;
		while(i<nums.size()){
			if(hash.find(nums[i])!=hash.end()){
				if(hash[nums[i]]<2){
					hash[nums[i]]++;
					result.push_back(nums[i]);
				}
			}
			else{
				hash[nums[i]]=1;
				result.push_back(nums[i]);
			}
			i++;
		}
		nums=result;
		return nums.size();
	}
};

int main()
{
	vector<int> nums(3,1);
	Solution s;
	s.removeDuplicates(nums);
}
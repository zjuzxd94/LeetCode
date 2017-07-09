//Accepted date: 20170526
//Author: xaingdongzhao
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int closest=INT_MAX;
		int result=0;
		int len=nums.size();
		qsort(nums.data(),len,sizeof(nums[0]),comp);
		for(int i=0;i<len-2;i++){
			int left=i+1;
			int right=len-1;
			while(left<right){
				int sum=nums[i]+nums[left]+nums[right];
				if(sum<target){
					if(target-sum<closest){
						closest=target-sum;
						result=sum;
					}
					left++;
				}
				else if(sum>target){
					if(sum-target<closest){
						closest=sum-target;
						result=sum;
					}
					right--;
				}
				else
					return sum;
			}
		}
		return result;
	}
	static int comp(const void* a, const void* b){
		return *(int*)a-*(int*)b;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(-1);// 2 1 -4
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-4);
	Solution s;
	cout<<s.threeSumClosest(nums,1);
}
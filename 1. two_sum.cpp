#include "iostream"
#include "string"
#include "vector"
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> indices;
	int flag = 0;
	for(int i=0;i<nums.size();i++) {
		if(flag == 1)
			break;
		for(int j=0;j<nums.size();j++){
			if(i==j)
				continue;
			if(nums[i]+nums[j]==target){
				if(i>j){
					i=i+j;
					j=i-j;
					i=i-j;
				}
				indices.push_back(i);
				indices.push_back(j);
				flag = 1;
				break;
			}
		}
	}
	return indices;
}

int main()
{
	vector<int> indices;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	int target = 6;
	indices = twoSum(nums,target);
	cout<<indices[0]<<' '<<indices[1];
	return 0;
}
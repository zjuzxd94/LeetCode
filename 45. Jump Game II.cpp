//Accepted date: 20170621
//Author: xaingdongzhao
#include "head.h"

//˼·��һ�α�������¼��ǰ����steps��steps+1���ܵ������Զ�±�
class Solution {
public:
	int jump(vector<int>& nums) {
		int n=nums.size();
		if(n<=1)return 0;
		vector<int> farest(n,0);
		farest[0]=0;
		farest[1]=nums[0];
		int steps=1;
		for(int i=1;i<n;){
			if(i<=farest[steps]){
				if(i+nums[i]>farest[steps+1])
					farest[steps+1]=i+nums[i];
				i++;
			}
			else{//������� i����++
				steps++;
			}
		}
		return steps;
	}
};

int main()
{
	Solution s;
	vector<int> nums(5);
	nums[0]=1;
	nums[1]=1;
	nums[2]=2;
	nums[3]=1;
	nums[4]=1;
	
	cout<<s.jump(nums);
}
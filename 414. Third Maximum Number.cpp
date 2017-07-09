//Accepted date: 20170611
//Author: xaingdongzhao
#include "head.h"

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		deque<int> q;
		set<int> s;//用于去重
		for(int i=0;i<nums.size();i++){
			if(s.find(nums[i])==s.end())
				s.insert(nums[i]);
			else
				continue;
			if(q.empty())
				q.push_back(nums[i]);
			else{
				if(q.size()==1){
					if(nums[i]>q.front())
						q.push_front(nums[i]);
					else if(nums[i]<q.front())
						q.push_back(nums[i]);
				}
				else if(q.size()==2){
					if(nums[i]>q.front())
						q.push_front(nums[i]);
					else if(nums[i]<q.front()&&nums[i]>q.back()){
						int temp=q.back();
						q.back()=nums[i];
						q.push_back(temp);
					}
					else if(nums[i]<q.back())
						q.push_back(nums[i]);
				}
				else if(q.size()==3){
					if(nums[i]>q.front()){
						q.push_front(nums[i]);
						q.pop_back();
					}
					else if(nums[i]<q.front()&&nums[i]>q.back()){
						q.pop_back();
						if(nums[i]>q.back()){
							int temp=q.back();
							q.back()=nums[i];
							q.push_back(temp);
						}
						else if(nums[i]<q.back())
							q.push_back(nums[i]);
					}
				}
			}
		}
		if(q.size()==3)
			return q.back();
		else 
			return q.front();
	}
};


int main()
{
	//[3,3,3,3,4,3,2,3,3]
	Solution s;
	vector<int> vec(9);
	for(auto i=0;i<9;i++)
		vec[i]=3;
	vec[4]=4;
	vec[6]=2;
	s.thirdMax(vec);
}
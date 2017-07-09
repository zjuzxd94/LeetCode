#include "head.h"
//˼·���ο�http://www.cnblogs.com/grandyang/p/4545261.html
//map������set���棬��Ϊmap�ĵڶ���ֵ����
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<long long> s;
		int left=0;
		int right=0;
		for(;right<nums.size();right++){
			if(right-left>k)
				s.erase(nums[left++]);
			set<long long>::iterator it=s.lower_bound((long long)nums[right]-t);
			if(it!=s.end()&&abs(nums[right]-*it)<=t)
				return true;
			s.insert(nums[right]);
		}
		return false;
	}
};
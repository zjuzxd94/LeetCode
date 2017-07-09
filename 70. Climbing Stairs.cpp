#include "head.h"
class Solution {
public:
	int climbStairs(int n) {
		if(n<3)return n;
		vector<int> result(n+1);
		result[1]=1;
		result[2]=2;
		for(int i=3;i<=n;i++){
			result[i]=result[i-1]+result[i-2];
		}
		return result[n];
	}
};
int main()
{
	Solution s;
	cout<<s.climbStairs(44);
	queue<int> q;
	deque<int> d;
	vector<int> v;
	
}
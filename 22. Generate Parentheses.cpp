//Accepted date: 20170528
//Author: xaingdongzhao
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Ë¼Â·£º²Î¿¼http://blog.csdn.net/fly_yr/article/details/48754087
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if(n<1)
			return result;
		dfs(result,"",n,n);
		return result;
	}
	void dfs(vector<string>& result,string temp,int left,int right){
		if(left==right&&left==0)
		{
			result.push_back(temp);
			return;
		}
		if(left>0)
			dfs(result,temp+'(',left-1,right);
		if(left<right)
			dfs(result,temp+')',left,right-1);
	}
};
//Accepted date: 20170529
//Author: xaingdongzhao
#include <vector>
#include <stack>
using namespace std;
//思路 参考http://www.cnblogs.com/grandyang/p/4322653.html解法三
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int result=0;
		heights.push_back(0);
		stack<int> sta;
		for(int i=0;i<heights.size();i++){
			while(!sta.empty()&&heights[i]<=heights[sta.top()]){
				int index=sta.top();
				sta.pop();
				result=max(result,heights[index]*(sta.empty()?i:i-sta.top()-1));
			}
			sta.push(i);
		}
		return result;
	}
};

int main()
{

	vector<int> heights(3);
	heights[0]=1;
	heights[1]=2;
	heights[2]=3;

	Solution s;
	s.largestRectangleArea(heights);
}
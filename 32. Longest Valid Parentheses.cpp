//Accepted date: 20170529
//Author: xaingdongzhao
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

//思路：参考https://segmentfault.com/a/1190000003481194
//栈方法
class Solution {
public:
	class parentheses{
	public:
		int i;
		char c;
		parentheses(int _i,char _c):i(_i),c(_c){}
	};

	int longestValidParentheses(string s) {
		int maxCount=0;
		stack<parentheses> sta;
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]=='(')//遇到左括号，将其push进栈
				sta.push(parentheses(i,'('));
			else{//遇到右括号，分类讨论
				if(!sta.empty()&&sta.top().c=='('){//如果当前栈顶是左括号，则消去并计算长度
					int count=0;
					sta.pop();
					if(sta.empty())
						count=i+1;
					else
						count=i-sta.top().i;
					if(count>maxCount)
						maxCount=count;
				}
				else//如果栈顶是右括号或者是空栈，则将右括号也push进栈，它的坐标将方便之后计算长度
					sta.push(parentheses(i,')'));
			}
		}
		return maxCount;
	}
};
//思路：参考https://segmentfault.com/a/1190000003481194
//动态规划方法
class Solution1 {
public:
	int longestValidParentheses(string s) {
		int len=s.size();
		if(len<2)
			return 0;
		int maxCount=0;
		vector<int> dp(len,0);
		for(int i=len-2;i>=0;i--){
			if(s[i]=='('){
				int end=i+dp[i+1]+1;
				if(end<len&&s[end]==')'){
					dp[i]=dp[i+1]+2;
					if(end+1<len)
						dp[i]+=dp[end+1];
				}
				if(dp[i]>maxCount)
					maxCount=dp[i];
			}
		}
		return maxCount;
	}
};

int main()
{
	string test="(((()(()"; 
	string test1="(()(((()";
	Solution1 s;
	cout<<s.longestValidParentheses(test);
	return 0;
}
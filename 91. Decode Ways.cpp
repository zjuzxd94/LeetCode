//Accepted date: 20170703
//Author: xaingdongzhao
#include "head.h"

//思路：分类
//http://blog.csdn.net/u012501459/article/details/46550815 中的分类方式漏掉了一种：s[i]在'7'到'9'之间而s[i-1]是'1'
class Solution {
public:
	int numDecodings(string s) {
		if(s.size()==0)return 0;

		vector<int> dp(s.size(),0);
		if(s[0]>'0'&&s[0]<='9')
			dp[0]=1;
		else
			dp[0]=0;
		if(s.size()==1)return dp[0];

		if(s[1]=='0'){
			if(s[0]=='1'||s[0]=='2')
				dp[1]=1;
			else
				dp[1]=0;
		}
		else if(s[1]<='6'&&(s[0]=='1'||s[0]=='2'))
			dp[1]=2;
		else if(s[1]<='9'&&s[0]=='1')
			dp[1]=2;
		else
			dp[1]=dp[0];

		for(int i=2;i<s.size();i++){
			if(s[i]=='0'){
				if(s[i-1]=='1'||s[i-1]=='2')
					dp[i]=dp[i-2];
				else
					dp[i]=0;
			}
			else if(s[i]<='6'&&(s[i-1]=='1'||s[i-1]=='2'))
				dp[i]=dp[i-1]+dp[i-2];
			else if(s[i]<='9'&&s[i-1]=='1')
				dp[i]=dp[i-1]+dp[i-2];
			else
				dp[i]=dp[i-1];
		}
		return dp[s.size()-1];
	}
};
#include "head.h"
//判断字符串中包含最多多少个"pizza"子序列，每个字符只考虑一次
//http://blog.csdn.net/h1021456873/article/details/48498519
int pizza(string s)
{
	string p="pizza";
	//dp[i][j]表示s中第j个字符之前的子串中最多包含的子序列p.substr(0,i+1)
	vector<vector<int>> dp(p.size(),vector<int>(s.size(),0));
	int sum=0;
	for(int j=0;j<s.size();j++){
		if(s[j]=='p')
			sum++;
		dp[0][j]=sum;
	}

	for(int i=1;i<p.size();i++){
		for(int j=1;j<s.size();j++){
			dp[i][j]=dp[i][j-1];
			if(p[i]==s[j]&&dp[i-1][j-1]>dp[i][j])
				dp[i][j]++;
		}
		
	}
	return dp[p.size()-1][s.size()-1];
}
int main()
{
	string s;
	cin>>s;
	cout<<pizza(s);
	return 0;
}
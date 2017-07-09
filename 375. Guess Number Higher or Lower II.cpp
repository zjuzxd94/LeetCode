//Accepted date: 20170603
//Author: xaingdongzhao
#include "head.h"

//思路：不是简单的二分，求dp[i][j]时，要考虑i到j中间所有的点为pick数的情况，求最小值
class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n+1,vector<int>(n+1,0));
		for(int i=1;i<n;i++)
			dp[i][i+1]=i;
		for(int len=3;len<=n;len++){
			for(int i=1;i<n-len+2;i++){
				int j=i+len-1;
				int globalMin=INT_MAX;
				for(int k=i+1;k<j;k++){
					int localMax=k+max(dp[i][k-1],dp[k+1][j]);
					if(localMax<globalMin)
						globalMin=localMax;
				}
				dp[i][j]=globalMin;
			}
		}
		return dp[1][n];
	}
};

int main()
{
	Solution s;
	cout<<s.getMoneyAmount(10);
}
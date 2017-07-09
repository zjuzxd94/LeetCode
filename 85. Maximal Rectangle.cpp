//Accepted date: 20170703
//Author: xaingdongzhao
#include "head.h"

//LeetCode84——Largest Rectangle in Histogram 的变形，按层遍历，更新直方图，求最大面积
//http://blog.csdn.net/zhangxiao93/article/details/50603143
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m=matrix.size();
		int result=0;
		if(m==0)return 0;
		int n=matrix[0].size();
		vector<int> dp(n+1,-1);
		for(int i=0;i<n;i++){
			dp[i]=matrix[0][i]-'0';
		}

		for(int i=0;i<m;i++){
			stack<int> sta;
			int tempMax=0;
			for(int j=0;j<dp.size();j++){
				while(!sta.empty()&&dp[j]<dp[sta.top()]){
					int index=sta.top();
					sta.pop();
					tempMax=max(tempMax,dp[index]*(sta.empty()?j:(j-sta.top()-1)));
				}
				sta.push(j);
			}
			result=max(result,tempMax);
			if(i<m-1){
				for(int j=0;j<n;j++){
					dp[j]=(matrix[i+1][j]=='0'?0:dp[j]+1);
				}
			}
		}

		return result;
	}
};
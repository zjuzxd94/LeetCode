//HDU 5464 Clarke and problem （DP）
//http://blog.csdn.net/h1021456873/article/details/48594839


//Accepted code:
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int mod=1000000000+7;
	int t;
	cin>>t;
	while(t--){
		int n,p;
		cin>>n>>p;
		vector<int> nums(n+1);
		vector<vector<int>> dp(n+1,vector<int>(p,0));
		for(int i=1;i<=n;i++)
		{
			cin>>nums[i];
			nums[i]%=p;
			while(nums[i]<0)
				nums[i]+=p;
			dp[i][nums[i]]=true;
		}
		
		dp[0][0]=1;//什么都不选也是一种可行解

		for(int i=1;i<=n;i++){
			for(int j=0;j<p;j++){
				int temp=j;
				while(temp<nums[i])
					temp+=p;
				dp[i][j]=(dp[i-1][j]+dp[i-1][(temp-nums[i])%p])%mod;
			}
		}
		cout<<dp[n][0]<<endl;

	}
	return 0;
}
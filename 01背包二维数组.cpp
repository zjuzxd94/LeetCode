#include <stdio.h>
#define MAXN 1002

int dp[MAXN][MAXN],w[MAXN],p[MAXN];
int _max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int n,v,T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&v);
		for(i=1;i<=n;i++)
			scanf("%d",&w[i]);//价值
		for(i=1;i<=n;i++)
			scanf("%d",&p[i]);//重量

		for(i=1;i<=n;i++)
			dp[i][0] = 0;
		for(i=0;i<=v;i++)
			dp[0][i] = 0;

		for(i=1;i<=n;i++)
			for(j=0;j<=v;j++)
			{
				dp[i][j] = dp[i-1][j];
				if(j>=p[i])
					dp[i][j] = _max(dp[i-1][j],dp[i-1][j-p[i]]+w[i]);
			}
		printf("%d\n",dp[n][v]);
	}
}
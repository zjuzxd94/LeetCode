#include "stdio.h"
#include "string.h"
#define MAXN 1002
int _max(int a,int b)
{
	return a>b?a:b;
}
int dp[MAXN],w[MAXN],p[MAXN];
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
		for(i=0;i<=v;i++)
			dp[i] = 0;
		for(i=1;i<=n;i++)
		{
			for(j=v;j>=0;j--)
			{
				if(j>p[i])
					dp[j] = _max(dp[j],dp[j-p[i]]+w[i]);
			}
		}
		printf("%d\n",dp[v]);
	}
}
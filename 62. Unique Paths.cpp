#include "head.h"

class Solution {
public:
	int uniquePaths(int m, int n) {
		if(m<=1)
			return n-1;
		if(n<=1)
			return m-1;
		//C(m+n-2,m-1);
		if(m<n){
			int temp=m;
			m=n;
			n=temp;
		}
		m=m+n-2;
		n=n-1;
		int result=1;
		int result1=1;
		for(int i=0;i<n;i++){
			result*=(m-i);
			result1*=(i+1);
		}
		return result/result1;
	}
};

int  main()
{
	int m=2,n=100;
	Solution s;
	s.uniquePaths(m,n);
}
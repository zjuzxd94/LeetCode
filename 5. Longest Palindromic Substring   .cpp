#include "head.h"

//��̬�滮����ʱ�临�Ӷ�O(n^2)
class Solution {
public:
	string longestPalindrome(string s) {
		if(s=="")
			return "";

		string result=s.substr(0,1);

		int n=s.size();
		int** p=new int*[n];
		for(int i=0;i<n;i++){
			p[i]=new int[n];
			for(int j=0;j<n;j++)
				p[i][j]=0;
			p[i][i]=1;
		}
		for(int i=0;i<n-1;i++){
			if(s[i]==s[i+1]){
				p[i][i+1]=1;
				if(2>result.size())
					result=s.substr(i,2);
			}
		}
		for(int i=2;i<n;i++){//��������Ϊ3������Ϊn�������Ӵ�
			for(int j=0;j<n-i;j++){
				if(p[j+1][j+i-1]&&s[j]==s[j+i]){
					if(i+1>result.size())
						result=s.substr(j,i+1);
					p[j][j+i]=1;
				}
			}
		}
		return result;

	}
};

//

int main()
{
	Solution s;
	cout<<s.longestPalindrome("abcba");
	string a="abcde";
}
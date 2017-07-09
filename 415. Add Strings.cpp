#include "head.h"
class Solution {
public:
	string addStrings(string num1, string num2) {
		int carry=0;
		int n1=num1.size(),n2=num2.size();
		int n=min(n1,n2);
		int m=max(n1,n2);
		string result(m+1,'0');
		for(int i=0;i<n;i++){
			int temp=num1[--n1]-'0'+num2[--n2]-'0'+carry;
			result[m--]=temp%10+'0';
			carry=temp/10;
		}
		while(n1>0){
			int temp=num1[--n1]-'0'+carry;
			result[m--]=temp%10+'0';
			carry=temp/10;
		}
		while(n2>0){
			int temp=num2[--n2]-'0'+carry;
			result[m--]=temp%10+'0';
			carry=temp/10;
		}
		result[0]=carry+'0';
		if(result[0]=='0'&&result.size()>1)return result.substr(1);
		else return result;
	}
};

int main()
{
	string s1="90",s2="90";
	Solution s;
	cout<<s.addStrings(s1,s2);
}
#include "head.h"
class Solution {
public:
	bool isPalindrome(string s) {
		string realS;
		for(int i=0;i<s.size();i++){
			if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')){
				realS+=s[i];
			}
			else if(s[i]>='A'&&s[i]<='Z'){
				realS+=s[i]-'A'+'a';
			}
		}
		int n=realS.size();
		for(int i=0;i<n/2;i++){
			if(realS[i]!=realS[n-i-1])
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout<<s.isPalindrome("");
}
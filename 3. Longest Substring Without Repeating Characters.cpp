#include "head.h"
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char,int> hash;
		int start=0,max=0;
		for(int i=0;i<s.size();i++){
			if(hash.find(s[i])==hash.end()){
				hash[s[i]]=i;
				int tempMax=hash.size();
				if(tempMax>max)
					max=tempMax;
			}
			else{
				int j=start;
				int m=hash[s[i]];
				for(;j<m;j++)
					hash.erase(s[j]);
				hash[s[i]]=i;
				start=j+1;
			}
		}
		return max;
	}
};

int main()
{
	Solution s;
	cout<<s.lengthOfLongestSubstring("abcabcbb");
	return 0;
}
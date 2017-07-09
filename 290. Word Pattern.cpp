//Accepted date: 20170602
//Author: xaingdongzhao

#include "head.h"
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		if(pattern.size()==0||str.size()==0)
			return false;
		vector<string> vstr;
		int i=0,cur=0,pre=0;
		for(;cur<=str.size();cur++){
			if(str[cur]==' '||cur==str.size()){
				vstr.push_back(str.substr(pre,i));
				pre=cur+1;
				i=0;
			}
			else
				i++;
		}
		if(pattern.size()!=vstr.size())
			return false;
		map<char,string> m;
		set<string> s;
		for(i=0;i<pattern.size();i++){
			if(m.find(pattern[i])==m.end()){
				if(s.find(vstr[i])!=s.end())
					return false;
				m[pattern[i]]=vstr[i];
				s.insert(vstr[i]);
			}
			else if(m[pattern[i]]!=vstr[i])
				return false;
		}
		return true;
	}
};

int main()
{
	string pattern="abba";
	string str="dog dog dog dog";
	Solution s;
	cout<<s.wordPattern(pattern,str);
	return 0;
}
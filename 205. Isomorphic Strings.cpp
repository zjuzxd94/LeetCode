//Accepted date: 20170601
//Author: xaingdongzhao
#include "head.h"

//思路：生成和字符串相同长度的整型数组，保存字符串对应位上的字符第一次出现的位置的下标
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if(s.size()!=t.size())
			return false;
		if(s==""&&t=="")
			return true;
		vector<int> ss, tt;
		map<char,int> maps,mapt;
		for(int i=0;i<s.size();i++){
			map<char,int>::iterator it1=maps.find(s[i]);
			map<char,int>::iterator it2=mapt.find(t[i]);
			if(it1==maps.end()){
				maps[s[i]]=i;
				ss.push_back(i);
			}
			else
				ss.push_back(it1->second);
			if(it2==mapt.end()){
				mapt[t[i]]=i;
				tt.push_back(i);
			}
			else
				tt.push_back(it2->second);
		}
		for(int i=0;i<ss.size();i++)
			if(ss[i]!=tt[i])
				return false;
		return true;
	}
};
//Accepted date: 20170601
//Author: xaingdongzhao
#include "head.h"

//˼·�����ɺ��ַ�����ͬ���ȵ��������飬�����ַ�����Ӧλ�ϵ��ַ���һ�γ��ֵ�λ�õ��±�
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
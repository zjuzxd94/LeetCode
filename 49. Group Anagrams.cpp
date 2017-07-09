//Accepted date: 20170621
//Author: xaingdongzhao
#include "head.h"

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string,vector<string>> m;
		vector<vector<string>> result;
		for(int i=0;i<strs.size();i++){
			string temp=strs[i];
			sort(temp.begin(),temp.end());
			m[temp].push_back(strs[i]);
		}
		for(auto i=m.begin();i!=m.end();i++){
			result.push_back(i->second);
		}
		return result;
	}
};
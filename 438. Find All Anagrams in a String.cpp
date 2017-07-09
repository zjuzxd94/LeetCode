//Accepted date: 20170529
//Author: xaingdongzhao
#include "head.h"

//思路：滑动窗口
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
		if(s.size()<p.size()||p.size()==0) return result;
		map<char,int> m;
		for(int i=0;i<p.size();i++){
			if(m.find(p[i])==m.end())
				m[p[i]]=1;
			else
				m[p[i]]++;
		}
		int left=0,right=0;
		while(right<=s.size()){
			if(right-left==p.size()){
				result.push_back(left);
				m[s[left++]]++;
			}
			if(m.find(s[right])==m.end()){
				while(left<right)
					m[s[left++]]++;
				left++;right++;
			}
			else{
				m[s[right]]--;
				if(m[s[right]]<0){
					while(s[left]!=s[right])m[s[left++]]++;
					m[s[left++]]++;
				}
				right++;
			}
		}
		return result;
	}
};

int main()
{
	string s1="abaacbabc",s2="abc";
	Solution s;
	s.findAnagrams(s1,s2);
}
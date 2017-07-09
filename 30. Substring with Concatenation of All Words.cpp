//Accepted date: 20170604
//Author: xaingdongzhao
#include "head.h"

//思路：将words中的词存入hash map中，记录每个词的个数。
//l是words中每个单词的长度，对s，遍历从第0~l-1个字符开始的子串
//维护一个窗口，left~right。窗口的长度正好是words中单词个数时，找到一个匹配结果。窗口移至right的右边，hash map复位，继续向后搜索
//若窗口右端的词不在hash map中，窗口移至right的右边，窗口移至right的右边，hash map复位，继续向后搜索
//若窗口右端的词在hash map中，并且这个词的个数大于零，将这个词的个数减一，right右移
//若窗口右端的词在hash map中，并且这个词的个数等于零，将left对应的词的个数加一，left右移
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		map<string,int> m;
		for(int i=0;i<words.size();i++){
			if(m.find(words[i])==m.end())
				m[words[i]]=1;
			else
				m[words[i]]++;
		}
		int l=words[0].size();
		map<string,int> temp;
		for(int i=0;i<l;i++){
			temp=m;
			int left=i,right=i;
			while(right<=s.size()){
				if(right-left==words.size()*l){
					result.push_back(left);
					temp[s.substr(left,l)]++;
					left+=l;
				}
				if(temp.find(s.substr(right,l))!=temp.end()){
					if(temp[s.substr(right,l)]>0){
						temp[s.substr(right,l)]--;
						right+=l;
					}
					else{
						temp[s.substr(left,l)]++;
						left+=l;
					}
				}
				else{
					right+=l;
					left=right;
					temp=m;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<string> word(4);
	word[0]="word";
	word[1]="good";
	word[2]="best";
	word[3]="good";
	s.findSubstring("wordgoodgoodgoodbestword",word);
}
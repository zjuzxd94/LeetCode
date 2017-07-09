//Accepted date: 20170604
//Author: xaingdongzhao
#include "head.h"

//˼·����words�еĴʴ���hash map�У���¼ÿ���ʵĸ�����
//l��words��ÿ�����ʵĳ��ȣ���s�������ӵ�0~l-1���ַ���ʼ���Ӵ�
//ά��һ�����ڣ�left~right�����ڵĳ���������words�е��ʸ���ʱ���ҵ�һ��ƥ��������������right���ұߣ�hash map��λ�������������
//�������Ҷ˵Ĵʲ���hash map�У���������right���ұߣ���������right���ұߣ�hash map��λ�������������
//�������Ҷ˵Ĵ���hash map�У���������ʵĸ��������㣬������ʵĸ�����һ��right����
//�������Ҷ˵Ĵ���hash map�У���������ʵĸ��������㣬��left��Ӧ�Ĵʵĸ�����һ��left����
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
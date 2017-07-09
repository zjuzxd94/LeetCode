#include "head.h"

void cal_next(string str, vector<int>& next)
{
	next[1]=0;
	for(int i=1;i<str.size();i++){
		int j=next[i];
		while(j>0&&str[j]!=str[i])
			j=next[j];
		if(str[j]==str[i])
			j++;
		next[i+1]=j;
	}
}

string KMP_search(string T, string P)
{
	vector<int> next(P.size()+1);
	cal_next(P,next);
	int maxlen=0;
	string result;
	int j=0;
	for(int i=0;i<T.size();i++){
		while(j>0&&T[i]!=P[j])
			j=next[j];
		if(T[i]==P[j])
			j++;
		if(j>maxlen){
			maxlen=j;
			result=T.substr(i-j+1,j);
		}
		if(j==P.size())
			j=next[j];
	}
	return result;
}

int main()
{
	string s1="abddabd";
	string s2="abcabdddabdhaha";
	string result;
	//思路：对s2的所有子串（从i开始到结尾）和s1做KMP匹配
	for(int i=0;i<s2.size();i++){
		string temp=KMP_search(s1,s2.substr(i));
		if(temp.size()>result.size())
			result=temp;
	}
	cout<<result;

	return 0;
}
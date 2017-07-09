#include "head.h"

void cal_next(string str, vector<int>& next)
{
	next[1]=0;
	for(int i=1;i<str.size();i++){
		int j=next[i];
		while(j>0&&str[j]!=str[i])
			j=next[j];
		if(str[j]==str[i])
			next[i+1]=j+1;
		else
			next[i+1]=j;
	}
}

void KMP_search(string T, string P)
{
	vector<int> next(P.size()+1);
	cal_next(P,next);
	int j=0;
	for(int i=0;i<T.size();i++){
		while(j>0&&T[i]!=P[j])
			j=next[j];
		if(T[i]==P[j])
			j++;
		if(j==P.size()){
			cout<<"match at "<<i-j+1<<endl;
			j=next[j];
		}

	}
}

int main()
{
	string T="abddabd";
	string P="abc";
	KMP_search(T,P);
}
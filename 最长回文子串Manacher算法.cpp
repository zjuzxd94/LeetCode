#include "head.h"

string manacher(string str)
{
	string newstr="#",result;
	for(int i=0;i<str.size();i++){
		newstr+=str[i];
		newstr+='#';
	}

	int id=0,maxid=0;
	int len=newstr.size();
	vector<int> p(len);
	p[0]=1;
	int maxLen=0;
	for(int i=1;i<newstr.size();i++){
		if(i<maxid){ //maxid是回文串到达最右的位置的下一个位置
			p[i]=min(p[2*id-i],maxid-i);
		}
		else
			p[i]=1;
		while(i-p[i]>=0&&i+p[i]<len&&newstr[i-p[i]]==newstr[i+p[i]])
			p[i]++;
		if(i+p[i]>maxid){
			maxid=i+p[i];
			id=i;
		}
		if(p[i]-1>maxLen){
			maxLen=p[i]-1;
			result=newstr.substr(i-p[i]+1,2*p[i]-1);
		}
	}
	return result;
}

int main()
{
	string str="abad";
	cout<<manacher(str);
	return 0;
}
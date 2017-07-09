#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace  std;

string manacher(string s)//求最长回文子串 manacher算法
{
	if(s=="")
		return "";
	string newstr("#");
	
	for(int i=0;i<s.size();i++){
		newstr+=s[i];
		newstr+='#';
	}
	string result;
	int len=newstr.size();
	int maxlen=0;
	int maxid=0;
	int id=0;
	vector<int> p(len,1);
	for(int i=0;i<len;i++){
		if(i<maxid)
			p[i]=min(p[2*id-i],maxid-i);
		else
			p[i]=1;
		while(i-p[i]>=0&&i+p[i]<len&&newstr[i-p[i]]==newstr[i+p[i]])
			p[i]++;
		if(2*p[i]-1>result.size())
			result=newstr.substr(i-p[i]+1,2*p[i]-1);
		if(i+p[i]>maxid){
			maxid=i+p[i];
			id=i;
		}
	}
	return result;
}

void calcNext(string s, vector<int>& next)
{
	next[1]=0;
	for(int i=1;i<s.size();i++){
		int j=next[i];
		while(j>0&&s[i]!=s[j])
			j=next[j];
		if(s[i]==s[j])
			j++;
		next[i+1]=j;
	}
}
string KMP(string s1, string s2)//字符串匹配 KMP算法
{
	vector<int> next(s2.size()+1);
	calcNext(s2,next);
	int j=0;
	int maxlen=0;
	for(int i=0;i<s1.size();i++){
		while(j>0&&s1[i]!=s2[j])
			j=next[j];
		if(s1[i]==s2[j])
			j++;
		if(j>maxlen)
			maxlen=j;
		if(j==s2.size())
			j=next[j];
	}
	return s2.substr(0,maxlen);
}

int LPS(string s)//最长回文子序列
{
	if(s=="")
		return 0;
	int len=s.size();
	vector<vector<int>> dp(len,vector<int>(len,0));
	for(int i=0;i<len;i++)
		dp[i][i]=1;

	int result=1;
	for(int k=1;k<len;k++){
		for(int i=0,j=k;i<len&&j<len;i++,j++){
			if(s[i]==s[j])
				dp[i][j]=dp[i+1][j-1]+2;
			else
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			if(dp[i][j]>result){
				result=dp[i][j];
			}
		}
	
	}
	return result;
}
int LCS(string s1, string s2)//最长公共子序列
{
	if(s1==""||s2=="")
		return 0;
	int len1=s1.size()+1,len2=s2.size()+1;
	vector<vector<int>> dp(len1,vector<int>(len2,0));
	for(int i=1;i<len1;i++){
		for(int j=1;j<len2;j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[len1-1][len2-1];
}
int getBottom(stack<int>& s)
{
	int temp=s.top();
	s.pop();
	if(s.empty())
		return temp;
	else{
		int result=getBottom(s);
		s.push(temp);
		return result;
	}
}
void reverse(stack<int>& s)//对栈逆序
{
	if(s.empty())
		return;
	int temp=getBottom(s);
	reverse(s);
	s.push(temp);
}
void sortStack(stack<int>& s)//对栈排序
{
	if(s.empty())
		return;
	stack<int> help;
	while(!s.empty()){
		int temp=s.top();
		s.pop();
		while(!help.empty()&&temp<help.top()){
			s.push(help.top());
			help.pop();
		}
		help.push(temp);
	}
	while(!help.empty()){
		s.push(help.top());
		help.pop();
	}
}
void quickSort(vector<int>& v, int i, int j)
{
	if(i>=j)
		return;

	int mid=(i+j)/2;
	int pivot=v[mid];
	v[mid]=v[i];
	v[i]=pivot;

	int left=i,right=j+1;
	while(left<right){
		while(left<right&&v[--right]>pivot);
		while(left<right&&v[++left]<pivot);
		if(left<right){
			int temp=v[left];
			v[left]=v[right];
			v[right]=temp;
		}
	}
	v[i]=v[right];
	v[right]=pivot;
	quickSort(v,i,mid-1);
	quickSort(v,mid+1,j);
}

class staticTest
{
private:
	staticTest(){}
public:
	static void fun()
	{
		cout<<"haha";
	}
};
int main()
{
	stack<int> sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(3);
	sta.push(4);
	//reverse(sta);
	//sortStack(sta);

	//string manacherstr="abcbadddabcdedcba";
	//cout<<manacher(manacherstr);

	//string kmps1="abcde",kmps2="bcdefgh";
	//cout<<KMP(kmps1,kmps2);

	//string lpsstr="abcdefdca";
	//cout<<LPS(lpsstr);

	//string lcss1="aebllcgd",lcss2="abbzcdsd";
	//cout<<LCS(lcss1,lcss2);

	//vector<int> vec1(5,1);
	//vec1[0]=4;
	//vec1[1]=5;
	//vec1[2]=3;
	//vec1[3]=1;
	//vec1[4]=1;
	//quickSort(vec1,0,4);

	staticTest st;//构造函数不能声明为private
	st.fun();
	staticTest::fun();
	return 0;
}
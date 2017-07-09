//Accepted date: 20170620
//Author: xaingdongzhao
#include "head.h"

//思路： 保存num1的1，2，...，9倍数。以num2的每一位乘num1，然后移位
class Solution {
public:
	string add(string s1,string s2){
		if(s1.size()==0)return s2;
		if(s2.size()==0)return s1;
		if(s1.size()<s2.size()){
			string temp=s1;
			s1=s2;
			s2=temp;
		}
		string result=s1;
		int i=s1.size()-1,j=s2.size()-1;
		int carry=0;
		while(j>=0){
			int sum=s1[i]-'0'+s2[j]-'0'+carry;
			carry=0;
			if(sum/10){
				carry=sum/10;
				sum=sum%10;
			}
			result[i]='0'+sum;
			i--;
			j--;
		}
		while(i>=0){
			int sum=s1[i]-'0'+carry;
			carry=0;
			if(sum/10){
				carry=sum/10;
				sum=sum%10;
			}
			result[i]='0'+sum;
			i--;
		}
		if(carry)
			result="1"+result;
		return result;
	}
	string multiply(string num1, string num2) {
		if(num1=="0")
			return "0";
		if(num2=="0")
			return "0";

		if(num1.size()<num2.size()){
			string temp=num1;
			num1=num2;
			num2=temp;
		}

		vector<string> strs(10,"");
		for(int i=1;i<=9;i++){
			strs[i]=add(strs[i-1],num1);
		}

		string result;
		for(int i=num2.size()-1,j=0;i>=0;i--,j++){
			if(num2[i]=='0')continue;
			string temp=strs[num2[i]-'0'];
			for(int k=0;k<j;k++)
				temp+="0";
			result=add(result,temp);
		}
		return result;
	}
};

int main()
{
	string s1="0",s2="0";

	Solution s;
	cout<<s.multiply(s1,s2);
	return 0;
}
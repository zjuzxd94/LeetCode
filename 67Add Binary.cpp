#include "head.h"
class Solution {
public:
	string addBinary(string a, string b) {
		if(a==""||b=="")return a==""?b:a;
		string result;
		int jinwei=0;
		int i=a.size()-1,j=b.size()-1;
		for(;i>=0||j>=0;){
			int temp;
			if(i>=0&&j>=0)temp=a[i]-'0'+b[j]-'0'+jinwei;
			else if(i>=0)temp=a[i]-'0'+jinwei;
			else temp=b[j]-'0'+jinwei;
			switch(temp){
			case 2: result="0"+result;jinwei=1;break;
			case 1: result="1"+result;jinwei=0;break;
			case 0: result="0"+result;jinwei=0;break;
			case 3: result="1"+result;jinwei=1;break;
			}
			i--;j--;
		}
		if(jinwei)result="1"+result;
		return result;
	}
};
int main()
{
	Solution s;
	cout<<s.addBinary("11","111");
}
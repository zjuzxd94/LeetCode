#include "head.h"
class Solution {
public:
	string convert(string s, int numRows) {
		if(s.size()==0)
			return "";
		if(numRows==1)
			return s;
		int rows=numRows,cols=s.size()/2+1; 
		char **gragh=new char*[rows+1];
		for(int i=0;i<rows+1;i++)
			gragh[i]=new char[cols+1];
		
		for(int i=1;i<=rows;i++)
			for(int j=1;j<=cols;j++)
				gragh[i][j]='\0';

		int m=1,n=1;
		for(int i=0;i<s.size();i++)
		{
			gragh[m][n]=s[i];
			if((n==1||n%(rows-1)==1)&&m<rows)m++;
			else if(m==1)m++;
			else{m--;n++;}
			// if(n%rows==1&&m==rows)
		}

		string result;
		for(int i=1;i<=rows;i++)
			for(int j=1;j<=cols;j++)
				if(gragh[i][j]!='\0')
					result+=gragh[i][j];
		return result;
	}
};

int main()
{
	Solution s;
	cout<<s.convert("abcde", 2);
	return 0;
}
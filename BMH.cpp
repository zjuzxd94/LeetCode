#include "head.h"
int main()
{
	string T="abcdabc",P="abc";
	int n=T.size();
	int m=P.size();
	vector<int> shift(128,m);
	for(int i=0;i<m-1;i++){
		shift[P[i]]=m-1-i;
	}

	for(int i=0;i<=n-m;){
		int j=m-1;
		for(;j>=0;j--){
			if(T[i+j]!=P[j])
				break;
		}
		if(j<0){
			cout<<"match at "<<i<<endl;
			i++;
		}
		else
			i+=shift[T[i+m-1]];
	}

	return 0;
}
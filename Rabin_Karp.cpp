#include "head.h"

void Rabin_Karp(string T, string P, int d, int q)
{
	int n=T.size();
	int m=P.size();
	int h=1;
	int t=0;
	int p=0;

	for(int i=0;i<m-1;i++){ //h=pow(d,m-1)%q
		h=(h*d)%q;
	}

	for(int i=0;i<m;i++){
		t=(t*d+T[i])%q;
		p=(p*d+P[i])%q;
	}

	for(int i=0;i<=n-m;i++){
		if(t==p){
			int j=-1;
			for(j=0;j<m;j++){
				if(T[i+j]!=P[j])
					break;
			}
			if(j==m)
				cout<<"match at "<<i<<endl;
		}
		if(i<n-m){
			t=((t-T[i]*h)*d+T[i+m])%q;
			if(t<0)
				t+=q;
		}
		
	}
}
int main()  
{  
	string T = "Rabin Rabin-Karp";
	string P = "Rabin";  
	int q = 101;  // A prime number  
	int d = 16;  
	Rabin_Karp(T, P,d,q);
	return 0;  
} 
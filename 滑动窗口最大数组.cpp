#include "head.h"
int main()
{
	int n,w;
	cin>>n>>w;
	vector<int> v(n);
	vector<int> result;
	for(int i=0;i<n;i++)
		cin>>v[i];

	deque<int> dq;
	for(int i=0;i<n;i++){
		if(dq.empty())
			dq.push_back(i);
		else if(v[dq.back()]>v[i])
			dq.push_back(i);
		else{
			while(!dq.empty()){
				if(v[dq.back()]<=v[i])
					dq.pop_back();
				else
					break;
			}
			dq.push_back(i);
		}
		if((i+1)>=w){
			while(dq.front()<=(i-w))
				dq.pop_front();
			result.push_back(v[dq.front()]);
		}
	}
	for(int i=0;i<n-w+1;i++)
		cout<<result[i]<<' ';
	return 0;
}
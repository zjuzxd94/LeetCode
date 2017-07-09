#include "head.h"
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int> right(n);//记录每个数右边第一个比它大的数的下标
	vector<int> left(n);//记录每个数左边第一个比它大的数的下标
	stack<int> s;
	for(int i=0;i<n;i++){
		if(s.empty()){
			s.push(i);
			left[i]=-1;
		}
		else{
			int temp=s.top();
			while(v[i]>v[temp]){
				s.pop();
				if(s.empty())
					break;
				temp=s.top();
			}
			if(s.empty())
				left[i]=-1;
			else
				left[i]=s.top();
		}
	}

	while(!s.empty())s.pop();//清空s

	for(int i=n-1;i>=0;i--){
		if(s.empty()){
			s.push(i);
			right[i]=-1;
		}
		else{
			int temp=s.top();
			while(v[i]>v[temp]){
				s.pop();
				if(s.empty())
					break;
				temp=s.top();
			}
			if(s.empty()){
				s.push(i);
				right[i]=-1;
			}
			else
				right[i]=s.top();
		}
	}

	vector<int> parent(n);//记录每个节点的父节点
	for(int i=0;i<n;i++){
		if(right[i]==-1){
			parent[i]=left[i]==-1?-1:left[i];
			continue;
		}
		if(left[i]==-1){
			parent[i]=right[i]==-1?-1:right[i];
			continue;
		}
		parent[i]=v[right[i]]<v[left[i]]?right[i]:left[i];
	}
	return 0;
}
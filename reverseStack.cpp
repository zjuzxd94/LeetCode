#include "head.h"
int getBottom(stack<int>& s)
{
	int temp=s.top();
	s.pop();
	if(s.empty())
		return temp;
	else{
		int last=getBottom(s);
		s.push(temp);
		return last;
	}
}
void reverseStack(stack<int>& s)
{
	if(s.empty())
		return;
	int bottom=getBottom(s);
	reverseStack(s);
	s.push(bottom);
}
int main()
{
	stack<int> s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		s.push(i);
	}
	reverseStack(s);
	for(int i=1;i<=n;i++){
		cout<<s.top()<<' ';
		s.pop();
	}
}
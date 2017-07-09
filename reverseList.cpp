#include "head.h"
struct node{
	int val;
	struct node* next;
	node(int _val):val(_val),next(NULL){}
};
int main()
{
	struct node* head=NULL;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		struct node* temp=head;
		head=new struct node(i);
		head->next=temp;
	}
	if(!head){
		cout<<"空链表";
		return 0;
	}

	struct node* now=head->next;
	head->next=NULL;
	struct node* temp;
	while(now){
		temp=now->next;
		now->next=head;
		head=now;
		now=temp;
	}

	while(head){
		cout<<head->val<<' ';
		head=head->next;
	}

	return 0;
}
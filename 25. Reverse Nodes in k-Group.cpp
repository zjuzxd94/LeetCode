#include <iostream>
#include <vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//http://blog.csdn.net/linhuanmars/article/details/20342851
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* temp=head;
		int n=0;
		while(temp){
			temp=temp->next;
			n++;
		}
		if(n<k||n==1||k==1)
			return head;
		int loop=n/k;
		ListNode* tail=head;
		ListNode* cur=head;
		ListNode* pre=head;
		for(int i=0;i<loop;i++){
			ListNode* tempTail=cur;
			pre=cur;
			cur=cur->next;
			for(int j=0;j<k-1;j++){
				temp=cur->next;
				cur->next=pre;
				pre=cur;
				cur=temp;
			}
			if(i==0){
				head=pre;
			}
			else{
				tail->next=pre;
				tail=tempTail;
			}
		}
		tail->next=cur;
		return head;
	}
};

int main()
{
	ListNode * head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	head->next->next->next->next=new ListNode(5);

	Solution s;
	head=s.reverseKGroup(head,2);
}
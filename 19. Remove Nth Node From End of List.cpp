//Accepted date: 20170528
//Author: xaingdongzhao
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//Ë¼Â·£ºË«Ö¸Õë
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1=head;
		ListNode* p2=head;
		while(n--)
			p2=p2->next;
		if(p2==NULL)
			return p1->next;
		ListNode* pre;
		while(p2!=NULL){
			pre=p1;
			p1=p1->next;
			p2=p2->next;
		}
		pre->next=p1->next;
		delete p1;
		p1=NULL;
		return head;
    }
};
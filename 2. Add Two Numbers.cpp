#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=new ListNode(0);
        ListNode* tail=result;
        int jinwei=0;
        while(l1||l2)
        {
            int temp=0;
            if(l1)
            {
                temp+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                temp+=l2->val;
                l2=l2->next;
            }
			temp=temp+jinwei;
            jinwei=temp/10;
            temp=temp%10;
            ListNode* tempNode=new ListNode(temp);
            tail->next=tempNode;
            tail=tail->next;
        }
		if(jinwei>0)
		{
			ListNode* tempNode=new ListNode(jinwei);
			tail->next=tempNode;
			tail=tail->next;
		}
        return result->next;
    }
};

int main()
{
	ListNode* l1=new ListNode(2);
	ListNode* l2=new ListNode(8);
	Solution s;
	ListNode*result = s.addTwoNumbers(l1,l2);

	return 0;
}
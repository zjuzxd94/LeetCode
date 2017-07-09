//Accepted date: 20170529
//Author: xaingdongzhao
#include <iostream>
#include <vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//思路：归并，递归实现
//参考http://blog.csdn.net/worldwindjp/article/details/39989005
class Solution {
public:
	ListNode* merge2Lists(ListNode* p1, ListNode* p2) {
		if(p1==NULL)
			return p2;
		if(p2==NULL)
			return p1;
		ListNode* result=new ListNode(0);
		ListNode* tail=result;
		while(p1&&p2){
			if(p1->val<p2->val){
				ListNode* temp=new ListNode(p1->val);
				tail->next=temp;
				tail=tail->next;
				p1=p1->next;
			}
			else{
				ListNode* temp=new ListNode(p2->val);
				tail->next=temp;
				tail=tail->next;
				p2=p2->next;
			}
		}
		while(p1){
			ListNode* temp=new ListNode(p1->val);
			tail->next=temp;
			tail=tail->next;
			p1=p1->next;
		}
		while(p2){
			ListNode* temp=new ListNode(p2->val);
			tail->next=temp;
			tail=tail->next;
			p2=p2->next;
		}
		return result->next;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size()==0)
			return NULL;
		if(lists.size()==1)
			return lists[0];
		int mid=lists.size()/2;

		vector<ListNode*> leftLists(lists.begin(),lists.begin()+mid);
		vector<ListNode*> rightLists(lists.begin()+mid,lists.end());
		ListNode* left=mergeKLists(leftLists);
		ListNode* right=mergeKLists(rightLists);
		return merge2Lists(left,right);
    }
};

int main()
{
	ListNode* p1=new ListNode(2);
	ListNode* p2=NULL;
	ListNode* p3=new ListNode(-1);
	vector<ListNode*> lists;
	lists.push_back(p1);
	lists.push_back(p2);
	lists.push_back(p3);
	Solution s;
	ListNode* result=s.mergeKLists(lists);

	return 0;
}
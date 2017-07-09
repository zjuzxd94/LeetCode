#include "head.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return help(root->left,root->right);
    }
    bool help(TreeNode* left, TreeNode* right){
        if(left==NULL&&right==NULL)return true;
        if(left&&right){
            if(left->val!=right->val)return false;
            if(!help(left->left,right->right))return false;
            if(!help(left->right,right->left))return false;
            return true;
        }
        else return false;
    }
};
//迭代 层序遍历
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
		if(root==NULL) return true;
		vector<TreeNode*> vec;		//用数组模拟队列
		vec.push_back(root);
		int i=0;					//i标记队列的起始位置
		int tail=0;
		vector<TreeNode*> temp;		//保存层序遍历一层的节点
		while(i<vec.size()){
			temp.push_back(vec[i]);
			if(vec[i]){
				vec.push_back(vec[i]->left);
				vec.push_back(vec[i]->right);
			}
			if(i==tail){
				if(!isPlalindrome(temp))return false;
				temp.clear();
				tail=vec.size()-1;
			}
			i++;
		}
		return true;
	}
	bool isPlalindrome(vector<TreeNode*>& vec){
		int i=0,j=vec.size()-1;
		while(i<j){
			if(vec[i]&&vec[j]){
				if(vec[i]->val!=vec[j]->val)return false;
			}
			else if(vec[i]==NULL&&vec[j]==NULL);
			else return false;
			i++;j--;
		}
		return true;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(4);
	root->right->left=new TreeNode(4);
	root->right->right=new TreeNode(3);
	Solution1 s;
	cout<<s.isSymmetric(root);
}
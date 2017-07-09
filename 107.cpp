#include "head.h"
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)return result;
        stack<vector<int>> tempResult;
        vector<TreeNode*> vec;//模拟队列
        vector<TreeNode*> temp;//保存层序遍历一层的节点
        vec.push_back(root);
        int i=0;//队列的起点
        int tail=0;
        while(i<vec.size()){
            temp.push_back(vec[i]);
            if(vec[i]){
                vec.push_back(vec[i]->left);
                vec.push_back(vec[i]->right);
            }
            if(i==tail){
                vector<int> tempVec;
                for(int j=0;j<temp.size();j++)
                    if(temp[j])tempVec.push_back(temp[j]->val);
				if(tempVec.size()>0)
					tempResult.push(tempVec);
                temp.clear();
                tail=vec.size()-1;
            }
            i++;
        }
        while(!tempResult.empty()){
            result.push_back(tempResult.top());
            tempResult.pop();
        }
        return result;
    }
};

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left=new TreeNode(9);
	root->right=new TreeNode(20);
	root->right->left=new TreeNode(15);
	root->right->right=new TreeNode(7);
	Solution s;
	s.levelOrderBottom(root);
}
//Accepted date: 20170611
//Author: xaingdongzhao
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//思路：深度优先搜索
//需要注意路径的开始和结束不一定是根节点和叶子节点
//但要防止某个节点作为路径开始节点的重复计算，使用了set来标记节点是否作为路径开始节点已经被访问过
class Solution {
private:
    set<TreeNode*> s;
public:
    int dfs(TreeNode* root, int sum, int totalSum){
        if(root==NULL)
            return 0;
        if(s.find(root)!=s.end()){
            return (root->val==sum)+dfs(root->left,sum-root->val,totalSum)
            +dfs(root->right,sum-root->val,totalSum);
        }
        else{
            s.insert(root);
            return (root->val==sum)+dfs(root->left,totalSum,totalSum)
            +dfs(root->right,totalSum,totalSum)
            +dfs(root->left,sum-root->val,totalSum)
            +dfs(root->right,sum-root->val,totalSum);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        return dfs(root,sum,sum);
    }
};
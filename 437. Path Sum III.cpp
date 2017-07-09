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

//˼·�������������
//��Ҫע��·���Ŀ�ʼ�ͽ�����һ���Ǹ��ڵ��Ҷ�ӽڵ�
//��Ҫ��ֹĳ���ڵ���Ϊ·����ʼ�ڵ���ظ����㣬ʹ����set����ǽڵ��Ƿ���Ϊ·����ʼ�ڵ��Ѿ������ʹ�
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
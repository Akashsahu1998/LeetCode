/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int DFS(TreeNode *root,int sum){
        if(root==nullptr)
            return 0;
        int ans = root->val==sum?1:0;
        return ans + DFS(root->left,sum-root->val) + DFS(root->right,sum-root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return 0;
        return DFS(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }
};

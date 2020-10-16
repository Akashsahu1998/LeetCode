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
    void solve(TreeNode* root, int &ans, int k) {
        if(root == NULL) return;
        k = (k << 1) | (root->val);
        if((!root->left) && (!root->right)) {
            ans += k;
            return;
        }
        solve(root->left, ans, k);
        solve(root->right, ans, k);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0, k = 0;
        solve(root, ans, 0);
        return ans;
    }
};


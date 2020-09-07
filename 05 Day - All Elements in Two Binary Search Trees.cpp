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
    void dfs(TreeNode* root, vector<int> &sortVec){
        if(root->left != NULL) dfs(root->left, sortVec);   
        sortVec.push_back(root->val);
        if(root->right != NULL) dfs(root->right, sortVec);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;
        if(root1 != NULL) dfs(root1, r1);
        if(root2 != NULL) dfs(root2, r2);
        vector<int>ans(r1.size() + r2.size());
        merge(r1.begin(), r1.end(), r2.begin(), r2.end(), ans.begin());
        return ans;    
    }
};

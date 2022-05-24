
// Question) 1373. Maximum Sum BST in Binary Tree


// Implementation

// Using DFS
// Time Complexity : O(N)
// Space Complexity : O(H), Where H is the Height of the BST

class NodeValue{
  public:
    int minValue, maxValue, ans;
    
    NodeValue(int _minValue, int _maxValue, int _ans){
        minValue = _minValue;
        maxValue = _maxValue;
        ans = _ans;
    }
};

class Solution {
private:
    NodeValue solve(TreeNode* root, int &res){
        if(!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        NodeValue left = solve(root->left, res);
        NodeValue right = solve(root->right, res);
        
        if(left.maxValue < root->val && right.minValue > root->val){
            res = max(res, root->val + left.ans + right.ans);
            return NodeValue(min(left.minValue, root->val), 
                             max(right.maxValue, root->val), 
                             root->val + left.ans + right.ans
                            );
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(left.ans, right.ans));
    }

public:
    int maxSumBST(TreeNode* root) {
        int res = 0;
        NodeValue val = solve(root, res);        
        return res;
    }
};


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

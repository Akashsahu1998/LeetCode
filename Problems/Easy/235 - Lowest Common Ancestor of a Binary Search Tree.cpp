
// Question) 235. Lowest Common Ancestor of a Binary Search Tree


// Implementation

// 1st Approach
// Recursive Approach
// Time Complexity = O(H), Where H is the height of the BST
// Space Complexity = O(N), Where H is the height of the BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        int curValue = root->val;
        
        // if possibility of p & q are going on left side
        if(p->val < curValue && q->val < curValue) return lowestCommonAncestor(root->left, p, q);
        
        // if possibility of p & q are going on right side
        if(p->val > curValue && q->val > curValue) return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};


// Question) 226. Invert Binary Tree


// Implementation

// Recursive Approach
// Time Complexity : O(N)
// Space Complexity : O(H), Where H is the height of the tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        invertTree(root->left);
        invertTree(root->right);
        
        // swap the left & right child of parent node
        swap(root->left, root->right);
        
        return root;
    }
};

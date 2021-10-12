
// Question) 111. Minimum Depth of Binary Tree


// Implementation

// DFS Approach
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:    
    int minDepth(TreeNode* root) {
        return (root == NULL) ? 0
        : ((!root->left) && (!root->right)) ? 1
        : (!root->left) ? minDepth(root->right) + 1
        : (!root->right) ? minDepth(root->left) + 1
        : min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

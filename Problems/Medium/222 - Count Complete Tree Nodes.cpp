
// Question) 222. Count Complete Tree Nodes


// Implementation

// Naive Approach
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

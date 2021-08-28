
// Question) 104. Maximum Depth of Binary Tree


// Implementation

// Recursive Approach 
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right))+1;
}

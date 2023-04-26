
// Question) 124. Binary Tree Maximum Path Sum


// Implementation

// DFS Traversal
// Time Complexity = O(N)
// Space Complexity = O(H), where H is the height of the Binary Tree
class Solution {
public:
    int maxPathSumFromBinaryTree(TreeNode* root, int &ans) {
        if(!root) return 0;
        
        // 0 to avoid the negative number if any, i.e [2, -1]
        int leftSum = max(0, maxPathSumFromBinaryTree(root->left, ans));
        int rightSum = max(0, maxPathSumFromBinaryTree(root->right, ans));
        ans = max(ans, leftSum + rightSum + root->val);
        return max(leftSum, rightSum) + root->val;
    }
     
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSumFromBinaryTree(root, ans);
        return ans;
    }
};
